#include "LEngine.h"

#include <iostream>

#include "LDiagnostic.h"
#include "LEnginePrivate.h"
#include "Parsers/LLexer.h"

namespace L
{
    LEngine::LEngine()
        : mPrivate(std::make_shared<LEnginePrivate>(this))
    {
    }

    LEngine::~LEngine() = default;

    LDiagnosticPtr LEngine::Init()
    {
        return mPrivate->Init();
    }

    LDiagnosticPtr LEngine::Evaluate(const std::string& inExpression, std::string& outResult)
    {
        return mPrivate->Evaluate(inExpression, outResult);
    }
}
