#pragma once
#include "LAstNode.h"

namespace L
{
    class LParenthesesNode : public LAstNode
    {
    public:
        LParenthesesNode(const LAstNodePtr& inChildNode);
        virtual std::string ToString() override;

    protected:
        LAstNodePtr mChildNode;
    };
}
