#pragma once
#include <memory>

#include "LDiagnostic.h"
#include "LLexer.h"
#include "Asts/LAst.h"

namespace L
{
    class LParser
    {
    public:
        LParser(LLexer* inLexer);
        LDiagnosticPtr Parse(const std::string& inExpression, LAst& outAst);

    protected:
        LDiagnosticPtr ParseInternal(LAstNodePtr& outNode, LToken& outEndToken);
        LDiagnosticPtr ParseLambda(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken);
        LDiagnosticPtr ParseParentheses(const LToken& inStartTOken, LAstNodePtr& outNode, LToken& outEndToken);
        LDiagnosticPtr ParseSymbolStart(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken);
        LDiagnosticPtr ParseSingleSymbol(const LToken& inStartToken, LAstNodePtr& outNode, LToken& outEndToken);
        
    protected:
        LLexer* mLexer;
    };
}
