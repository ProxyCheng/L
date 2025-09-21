#pragma once
#include <string>

#include "LAstNode.h"

namespace L
{
    class LSymbolAstNode : public LAstNode
    {
    public:
        LSymbolAstNode(const std::string& inSymbol);
        virtual std::string ToString() override;
        std::string& RefSymbol();
        const std::string& RefSymbol() const;

    protected:
        std::string mSymbol;
    };

    using LSymbolAstNodePtr = std::shared_ptr<LSymbolAstNode>;
}
