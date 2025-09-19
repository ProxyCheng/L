#pragma once
#include <memory>
#include <string>

#include "L.h"

namespace L
{
    class L_API LDiagnostic
    {
    public:
        LDiagnostic(const std::string& inDescription, const std::string& inExpression, int inStartPosition, int inLength);
        ~LDiagnostic();
        std::string ToString();

    protected:
        std::string mDescription;
        std::string mExpression;
        int mStartPosition;
        int mLength;
    };
    
    using LDiagnosticPtr = std::shared_ptr<LDiagnostic>;
}
