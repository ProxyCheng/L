#include "LSymbolNode.h"

namespace L
{
    LSymbolNode::LSymbolNode(const std::string& inSymbol)
        : mSymbol(inSymbol)
    {
    }

    std::string LSymbolNode::ToString()
    {
        return mSymbol;
    }
}
