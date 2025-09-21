#pragma once
#include <memory>
#include <string>

#include "L.h"
#include "LDiagnostic.h"

namespace L
{
    class LEnginePrivate;

    class L_API LEngine
    {
    public:
        LEngine();
        virtual ~LEngine();
        LDiagnosticPtr Init();
        LDiagnosticPtr Evaluate(const std::string& inExpression, std::string& outResult);

    protected:
        friend LEnginePrivate;
        std::shared_ptr<LEnginePrivate> mPrivate;
    };
}
