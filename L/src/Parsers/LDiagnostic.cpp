#include "LDiagnostic.h"

namespace L
{
    LDiagnostic::LDiagnostic(const std::string& inDescription, const std::string& inExpression, int inStartPosition, int inLength)
        : mDescription(inDescription)
        , mExpression(inExpression)
        , mStartPosition(inStartPosition)
        , mLength(inLength)
    {
    }

    LDiagnostic::~LDiagnostic() = default;

    std::string LDiagnostic::ToString()
    {
        std::string result;
        result += mDescription + "\n";
        result += mExpression + "\n";
        if (mStartPosition < 0)
            return result;
        for (int i = 0; i < mStartPosition; i++)
            result += " ";
        result += "^";
        for (int i = 0; i < mLength - 1; i++)
            result += "~";
        return result;
    }
}
