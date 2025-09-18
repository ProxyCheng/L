#pragma once
#include <vector>

#include "LAstNode.h"

namespace L
{
    class LEvaluateNode : public LAstNode
    {
    public:
        LEvaluateNode(const LAstNodePtr& inLeftNode, const LAstNodePtr& inRightNode);
        virtual std::string ToString() override;

    protected:
        LAstNodePtr mLeftNode;
        LAstNodePtr mRightNode;
    };
}
