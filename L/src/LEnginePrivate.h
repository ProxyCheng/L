#pragma once
#include <stack>
#include <unordered_map>

#include "LEngine.h"
#include "Evaluators/Expressions/LExpression.h"
#include "Evaluators/Expressions/LLambdaExpressionNode.h"
#include "Parsers/Asts/LAst.h"
#include "Parsers/Asts/LLambdaAstNode.h"

namespace L
{
    class LEnginePrivate
    {
    public:
        LEnginePrivate(LEngine* inPublic);
        LDiagnosticPtr Init();
        LDiagnosticPtr Evaluate(const std::string& inExpression, std::string& outResult);
        LDiagnosticPtr CreateExpression(const LAst& inAst, LExpression& outExpression);
        using ParametersType = std::unordered_map<std::string, std::stack<LLambdaExpressionNode*>>;
        LDiagnosticPtr CreateExpressionNode(const LAstNodePtr& inAstNode, LExpressionNodePtr& outExpressionNode, ParametersType& refParameters);
        LDiagnosticPtr EvaluateExpression(const LExpression& inExpression, LExpression& outExpression);

    protected:
        friend LEngine;
        LEngine* mPublic = nullptr;
        std::unordered_map<std::string, LExpressionPtr> mNamedExpressions;
    };
}
