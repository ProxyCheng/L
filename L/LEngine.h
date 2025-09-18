#pragma once
#include <memory>
#include <string>

#include "L.h"
#include "LDiagnostic.h"

namespace L
{
    class L_API LEngine
    {
    public:
        LDiagnosticPtr Evaluate(const std::string& inExpression, std::string& outResult);
    };
}
