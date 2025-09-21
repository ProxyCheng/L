#include "LEnginePrivate.h"

#include "Evaluators/Expressions/LAssignExpressionNode.h"
#include "Evaluators/Expressions/LEvaluateExpressionNode.h"
#include "Evaluators/Expressions/LNamedExpressionReferenceNode.h"
#include "Evaluators/Expressions/LParameterReferenceNode.h"
#include "Parsers/LLexer.h"
#include "Parsers/LParser.h"
#include "Parsers/Asts/LAssignAstNode.h"
#include "Parsers/Asts/LEvaluateAstNode.h"
#include "Parsers/Asts/LLambdaAstNode.h"
#include "Parsers/Asts/LPrenthesesNode.h"

namespace L
{
    LEnginePrivate::LEnginePrivate(LEngine* inPublic)
        : mPublic(inPublic)
    {
    }

    LDiagnosticPtr LEnginePrivate::Init()
    {
        static std::vector<std::string> Predefs{
            { "TRUE  = La.Lb.a" },
            { "FALSE = La.Lb.b" },
            { "IF    = La.Lb.Lc.(a b c)" },
            { "AND   = La.Lb.(a b a)" },
            { "OR    = La.Lb.(a a b)" },
            { "NOT   = La.(a FALSE TRUE)" },
        };
        for (const std::string& expression : Predefs)
        {
            std::string result;
            RETURN_IF_PANIC(Evaluate(expression, result))
        }
    }

    LDiagnosticPtr LEnginePrivate::Evaluate(const std::string& inExpression, std::string& outResult)
    {
        LLexer lexer;
        LParser parser(&lexer);
        LAst ast;
        RETURN_IF_PANIC(parser.Parse(inExpression, ast))
        LExpression expression;
        RETURN_IF_PANIC(CreateExpression(ast, expression))
        LExpression evaluatedExpression;
        RETURN_IF_PANIC(EvaluateExpression(expression, evaluatedExpression))
        outResult = expression.ToString();
        int a = 1;
        return nullptr;
    }

    LDiagnosticPtr LEnginePrivate::CreateExpression(const LAst& inAst, LExpression& outExpression)
    {
        ParametersType parameters;
        return CreateExpressionNode(inAst.RefRoot(), outExpression.RefRoot(), parameters);
    }

    LDiagnosticPtr LEnginePrivate::CreateExpressionNode(const LAstNodePtr& inAstNode, LExpressionNodePtr& outExpressionNode, ParametersType& refParameters)
    {
        switch (inAstNode->GetType())
        {
        case LAstNodeType_Symbol:
            {
                const LSymbolAstNode* symbolAstNode = static_cast<const LSymbolAstNode*>(inAstNode.get());
                const std::string& symbol = symbolAstNode->RefSymbol();
                if (auto iter = refParameters.find(symbol); iter != refParameters.cend())
                {
                    LLambdaExpressionNode* referencedNode = iter->second.top();
                    outExpressionNode = std::make_shared<LParameterReferenceNode>(referencedNode);
                    break;
                }
                if (auto iter = mNamedExpressions.find(symbol); iter != mNamedExpressions.cend())
                {
                    LExpression* referencedExpression = iter->second.get();
                    outExpressionNode = std::make_shared<LNamedExpressionReferenceNode>(referencedExpression, iter->first);
                    break;
                }
                return std::make_shared<LDiagnostic>(
                    "Unknown Symbol.",
                    symbol,
                    -1,
                    0
                );
            }
            break;
        case LAstNodeType_Lambda:
            {
                const LLambdaAstNode* lambdaAstNode = static_cast<const LLambdaAstNode*>(inAstNode.get());
                const std::string& parameterName = lambdaAstNode->RefHeadNode()->RefSymbol();
                LLambdaExpressionNodePtr lambdaExpressionNode = std::make_shared<LLambdaExpressionNode>();
                std::stack<LLambdaExpressionNode*>& stack = refParameters.emplace(parameterName, std::stack<LLambdaExpressionNode*>()).first->second;
                stack.emplace(lambdaExpressionNode.get());
                RETURN_IF_PANIC(CreateExpressionNode(lambdaAstNode->RefBodyNode(), lambdaExpressionNode->RefChildNode(), refParameters))
                stack.pop();
                if (stack.empty())
                    refParameters.erase(parameterName);
                outExpressionNode = lambdaExpressionNode;
            }
            break;
        case LAstNodeType_Parentheses:
            {
                const LParenthesesAstNode* parenthesesAstNode = static_cast<const LParenthesesAstNode*>(inAstNode.get());
                RETURN_IF_PANIC(CreateExpressionNode(parenthesesAstNode->RefChildNode(), outExpressionNode, refParameters))
            }
            break;
        case LAstNodeType_Evaluate:
            {
                const LEvaluateAstNode* evaluateAstNode = static_cast<const LEvaluateAstNode*>(inAstNode.get());
                LEvaluateExpressionNodePtr evaluateExpressionNode = std::make_shared<LEvaluateExpressionNode>();
                RETURN_IF_PANIC(CreateExpressionNode(evaluateAstNode->RefLeftNode(), evaluateExpressionNode->RefLeftNode(), refParameters))
                RETURN_IF_PANIC(CreateExpressionNode(evaluateAstNode->RefRightNode(), evaluateExpressionNode->RefRightNode(), refParameters))
                outExpressionNode = evaluateExpressionNode;
            }
            break;
        case LAstNodeType_Assign:
            {
                const LAssignAstNode* assignAstNode = static_cast<const LAssignAstNode*>(inAstNode.get());
                LAssignExpressionNodePtr assignExpressionNode = std::make_shared<LAssignExpressionNode>(assignAstNode->RefLeftNode()->RefSymbol());
                LExpressionPtr rightExpression = std::make_shared<LExpression>();
                RETURN_IF_PANIC(CreateExpressionNode(assignAstNode->RefRightNode(), rightExpression->RefRoot(), refParameters))
                assignExpressionNode->RefRightExpression() = rightExpression;
                outExpressionNode = assignExpressionNode;
            }
            break;
        default:
            return std::make_shared<LDiagnostic>(
                "Unknown Ast Node.",
                "",
                0,
                0
            );
        }
        return nullptr;
    }

    LDiagnosticPtr LEnginePrivate::EvaluateExpression(const LExpression& inExpression, LExpression& outExpression)
    {
        const LExpressionNodePtr& node = inExpression.RefRoot();
        switch (node->GetType())
        {
        case LExpressionNodeType_Lambda:
            break;
        case LExpressionNodeType_Evaluate:
            // TODO
            break;
        case LExpressionNodeType_Assign:
            {
                const LAssignExpressionNode* assignNode = static_cast<const LAssignExpressionNode*>(node.get());
                const std::string& leftName = assignNode->RefLeftName();
                const LExpressionPtr& rightExpression = assignNode->RefRightExpression();
                mNamedExpressions.emplace(leftName, rightExpression);
            }
            break;
        }
        return nullptr;
    }
}
