#include "LParser.h"

#include "Asts/LAssignAstNode.h"
#include "Asts/LEvaluateAstNode.h"
#include "Asts/LLambdaAstNode.h"
#include "Asts/LPrenthesesNode.h"
#include "Asts/LSymbolAstNode.h"

namespace L
{
    LParser::LParser(LLexer* inLexer)
        : mLexer(inLexer)
    {
    }

    LDiagnosticPtr LParser::Parse(const std::string& inExpression, LAst& outAst)
    {
        mLexer->Bind(inExpression);
        LToken endToken;
        RETURN_IF_PANIC(ParseInternal(outAst.RefRoot(), endToken))
        if (endToken.mType != LTokenType_End)
            return std::make_shared<LDiagnostic>(
                "Redundant ending.",
                mLexer->RefExpression(),
                endToken.mStartPosition,
                mLexer->RefExpression().size() - endToken.mStartPosition
            );
        return nullptr;
    }

    LDiagnosticPtr LParser::ParseInternal(LAstNodePtr& outNode, LToken& outEndToken)
    {
        LToken token;
        do
        {
            RETURN_IF_PANIC(mLexer->TakeToken(token))
        }
        while (token.mType == LTokenType_Space);
        switch (token.mType)
        {
        case LTokenType_L:
            RETURN_IF_PANIC(ParseLambda(token, outNode, outEndToken))
            break;
        case LTokenType_LParentheses:
            RETURN_IF_PANIC(ParseParentheses(token, outNode, outEndToken))
            break;
        case LTokenType_Symbol:
            RETURN_IF_PANIC(ParseSymbolStart(token, outNode, outEndToken))
            break;
        default:
            return std::make_shared<LDiagnostic>(
                "Invalid expression.",
                mLexer->RefExpression(),
                token.mStartPosition,
                token.mLength
            );
        }
        return nullptr;
    }

    LDiagnosticPtr LParser::ParseLambda(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken)
    {
        LToken token;
        do
        {
            RETURN_IF_PANIC(mLexer->TakeToken(token))
        }
        while (token.mType == LTokenType_Space);
        if (token.mType != LTokenType_Symbol)
            return std::make_shared<LDiagnostic>(
                std::string("Expecting a symbol."),
                mLexer->RefExpression(),
                token.mStartPosition,
                token.mLength
            );
        LSymbolAstNodePtr headNode = std::make_shared<LSymbolAstNode>(token.mData);
        do
        {
            RETURN_IF_PANIC(mLexer->TakeToken(token))
        }
        while (token.mType == LTokenType_Space);
        if (token.mType != LTokenType_Dot)
            return std::make_shared<LDiagnostic>(
                "Expecting '.'.",
                mLexer->RefExpression(),
                token.mStartPosition,
                token.mLength
            );
        LAstNodePtr bodyNode;
        RETURN_IF_PANIC(ParseInternal(bodyNode, outEndToken))
        outNode = std::make_shared<LLambdaAstNode>(headNode, bodyNode);
        return nullptr;
    }

    LDiagnosticPtr LParser::ParseParentheses(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken)
    {
        LAstNodePtr childNode;
        LToken token;
        RETURN_IF_PANIC(ParseInternal(childNode, token))
        if (token.mType != LTokenType_RParentheses)
            return std::make_shared<LDiagnostic>(
                "Expecting ')'.",
                mLexer->RefExpression(),
                token.mStartPosition,
                token.mLength
            );
        outNode = std::make_shared<LParenthesesAstNode>(childNode);
        RETURN_IF_PANIC(mLexer->TakeToken(outEndToken))
        return nullptr;
    }

    LDiagnosticPtr LParser::ParseSymbolStart(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken)
    {
        LSymbolAstNodePtr symbolNode = std::make_shared<LSymbolAstNode>(inStartToken.mData);
        LToken token;
        do
        {
            RETURN_IF_PANIC(mLexer->TakeToken(token))
        }
        while (token.mType == LTokenType_Space);
        if (token.mType == LTokenType_Assign)
        {
            LAstNodePtr rightNode;
            RETURN_IF_PANIC(ParseInternal(rightNode, outEndToken))
            outNode = std::make_shared<LAssignAstNode>(symbolNode, rightNode);
            return nullptr;
        }
        LAstNodePtr leftNode = symbolNode;
        while (token.mType == LTokenType_Symbol || token.mType == LTokenType_LParentheses)
        {
            LAstNodePtr rightNode;
            LToken token2;
            RETURN_IF_PANIC(ParseSingleSymbol(token, rightNode, token2))
            token = token2;
            leftNode = std::make_shared<LEvaluateAstNode>(leftNode, rightNode);
            while (token.mType == LTokenType_Space)
                RETURN_IF_PANIC(mLexer->TakeToken(token))
        }
        outNode = leftNode;
        outEndToken = token;
        return nullptr;
    }
    
    LDiagnosticPtr LParser::ParseSingleSymbol(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken)
    {
        switch (inStartToken.mType)
        {
        case LTokenType_Symbol:
            outNode = std::make_shared<LSymbolAstNode>(inStartToken.mData);
            RETURN_IF_PANIC(mLexer->TakeToken(outEndToken))
            break;
        case LTokenType_LParentheses:
            return ParseParentheses(inStartToken, outNode, outEndToken);
        default:
            return std::make_shared<LDiagnostic>(
                "Expecting a symbol.",
                mLexer->RefExpression(),
                inStartToken.mStartPosition,
                inStartToken.mLength
            );
        }
        return nullptr;
    }
}
