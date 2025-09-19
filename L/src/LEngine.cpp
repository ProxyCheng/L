#include "LEngine.h"

#include <iostream>

#include "LDiagnostic.h"
#include "Parsers/LLexer.h"
#include "Parsers/LParser.h"

namespace L
{
    LDiagnosticPtr LEngine::Evaluate(const std::string& inExpression, std::string& outResult)
    {
        LLexer lexer;
        LParser parser(&lexer);
        LAst ast;
        RETURN_IF_PANIC(parser.Parse(inExpression, ast))
        outResult = ast.ToString();
    }
}
