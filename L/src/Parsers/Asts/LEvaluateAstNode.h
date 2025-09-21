#pragma once
#include <vector>

#include "LAstNode.h"

namespace L
{
    class LEvaluateAstNode : public LAstNode
    {
    public:
        LEvaluateAstNode(const LAstNodePtr& inLeftNode, const LAstNodePtr& inRightNode);
        virtual std::string ToString() override;
        LAstNodePtr& RefLeftNode();
        const LAstNodePtr& RefLeftNode() const;
        LAstNodePtr& RefRightNode();
        const LAstNodePtr& RefRightNode() const;

    protected:
        LAstNodePtr mLeftNode;
        LAstNodePtr mRightNode;
    };
}
