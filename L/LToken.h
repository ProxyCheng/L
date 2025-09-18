#pragma once
#include <memory>
#include <string>

namespace L
{
    enum LTokenType
    {
        LTokenType_Invalid = -1,
        LTokenType_Unknown = 0,
        LTokenType_End,
        LTokenType_L,
        LTokenType_Symbol,
        LTokenType_Dot,
        LTokenType_Space,
        LTokenType_LParentheses,
        LTokenType_RParentheses,
        LTokenType_Assign,
    };
    
    struct LToken
    {
    public:
        LTokenType mType = LTokenType_Invalid;
        std::string mData;
        int mStartPosition = -1;
        int mLength = -1;
    };
}
