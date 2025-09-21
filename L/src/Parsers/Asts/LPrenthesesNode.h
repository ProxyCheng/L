#pragma once
#include "LAstNode.h"

namespace L
{
    class LParenthesesAstNode : public LAstNode
    {
    public:
        LParenthesesAstNode(const LAstNodePtr& inChildNode);
        virtual std::string ToString() override;
        LAstNodePtr& RefChildNode();
        const LAstNodePtr& RefChildNode() const;

    protected:
        LAstNodePtr mChildNode;
    };
}
