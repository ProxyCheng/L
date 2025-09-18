#pragma once
#include "LAstNode.h"
#include "LSymbolNode.h"

namespace L
{
    class LAssignNode : public LAstNode
    {
    public:
        LAssignNode(const LSymbolNodePtr& inLeftNode, const LAstNodePtr& inRightNode);
        virtual std::string ToString() override;

    protected:
        LSymbolNodePtr mLeftNode;
        LAstNodePtr mRightNode;
    };
}
