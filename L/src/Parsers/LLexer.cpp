#include "LLexer.h"

namespace L
{
    void LLexer::Bind(const std::string& inExpression)
    {
        mExpression = inExpression;
        mPosition = 0;
    }

    enum LCharType
    {
        LCharType_End,
        LCharType_Space,
        LCharType_Dot,
        LCharType_Digit,
        LCharType_L,
        LCharType_Other,
        LCharType_LParentheses,
        LCharType_RParentheses,
        LCharType_Equal,
    };

    inline LCharType GetCharType(char c)
    {
        switch (c)
        {
        case '\0':
            return LCharType_End;
        case '.':
            return LCharType_Dot;
        case '(':
            return LCharType_LParentheses;
        case ')':
            return LCharType_RParentheses;
        case '\r':
        case '\n':
            return LCharType_Space;
        case 'L':
            return LCharType_L;
        case '=':
            return LCharType_Equal;
        }
        if (std::isspace(c))
            return LCharType_Space;
        if (std::isdigit(c))
            return LCharType_Digit;
        return LCharType_Other;
    }

    LDiagnosticPtr LLexer::TakeToken(LToken& outToken)
    {
        outToken.mStartPosition = mPosition;
        char c = TakeChar();
        char d = '\0';
        switch (GetCharType(c))
        {
        case LCharType_End:
            outToken.mType = LTokenType_End;
            break;
        case LCharType_Space:
            d = TakeChar();
            while (GetCharType(d) == LCharType_Space)
                d = TakeChar();
            Revoke();
            outToken.mType = LTokenType_Space;
            break;
        case LCharType_Dot:
            outToken.mType = LTokenType_Dot;
            break;
        case LCharType_Digit:
            d = TakeChar();
            while (GetCharType(d) == LCharType_Digit)
                d = TakeChar();
            if (GetCharType(d) == LCharType_Other)
                return std::make_shared<LDiagnostic>("Unexpected character.", mExpression, mPosition - 1, 1);
            Revoke();
            outToken.mType = LTokenType_Symbol;
            break;
        case LCharType_L:
            outToken.mType = LTokenType_L;
            break;
        case LCharType_Other:
            d = TakeChar();
            while (GetCharType(d) == LCharType_Other || GetCharType(d) == LCharType_Digit || GetCharType(d) == LCharType_L)
                d = TakeChar();
            Revoke();
            outToken.mType = LTokenType_Symbol;
            break;
        case LCharType_LParentheses:
            outToken.mType = LTokenType_LParentheses;
            break;
        case LCharType_RParentheses:
            outToken.mType = LTokenType_RParentheses;
            break;
        case LCharType_Equal:
            outToken.mType = LTokenType_Assign;
            break;
        default:
            outToken.mType = LTokenType_Unknown;
            break;
        }
        outToken.mLength = mPosition - outToken.mStartPosition;
        if (outToken.mStartPosition < mExpression.size())
            outToken.mData = mExpression.substr(outToken.mStartPosition, outToken.mLength);
        return nullptr;
    }

    std::string& LLexer::RefExpression()
    {
        return mExpression;
    }

    int LLexer::GetPosition()
    {
        return mPosition;
    }

    char LLexer::TakeChar()
    {
        char c = mPosition < mExpression.size() ? mExpression[mPosition] : '\0';
        mPosition++;
        return c;
    }

    void LLexer::Revoke()
    {
        mPosition--;
    }
}
