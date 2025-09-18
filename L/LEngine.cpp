#include "LEngine.h"

#include <iostream>

#include "LLexer.h"
#include "LParser.h"

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
