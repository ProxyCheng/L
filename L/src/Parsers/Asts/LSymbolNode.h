#pragma once
#include <string>

#include "LAstNode.h"

namespace L
{
    class LSymbolNode : public LAstNode
    {
    public:
        LSymbolNode(const std::string& inSymbol);
        virtual std::string ToString() override;

    protected:
        std::string mSymbol;
    };

    using LSymbolNodePtr = std::shared_ptr<LSymbolNode>;
}
