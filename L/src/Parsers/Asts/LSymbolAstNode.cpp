#include "LSymbolAstNode.h"

namespace L
{
    LSymbolAstNode::LSymbolAstNode(const std::string& inSymbol)
        : LAstNode(LAstNodeType_Symbol)
        , mSymbol(inSymbol)
    {
    }

    std::string LSymbolAstNode::ToString()
    {
        return mSymbol;
    }

    std::string& LSymbolAstNode::RefSymbol()
    {
        return mSymbol;
    }

    const std::string& LSymbolAstNode::RefSymbol() const
    {
        return mSymbol;
    }
}
