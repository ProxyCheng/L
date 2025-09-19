#pragma once
#include <memory>
#include <string>

#include "LDiagnostic.h"
#include "LToken.h"

namespace L
{
    class LLexer
    {
    public:
        void Bind(const std::string& inExpression);
        LDiagnosticPtr TakeToken(LToken& outToken);
        std::string& RefExpression();
        int GetPosition();

    protected:
        char TakeChar();
        void Revoke();

    protected:
        std::string mExpression;
        int mPosition = 0;
    };
}
