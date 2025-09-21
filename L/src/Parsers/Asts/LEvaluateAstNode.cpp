#include "LEvaluateAstNode.h"

namespace L
{
    LEvaluateAstNode::LEvaluateAstNode(const LAstNodePtr& inLeftNode, const LAstNodePtr& inRightNode)
        : LAstNode(LAstNodeType_Evaluate)
        , mLeftNode(inLeftNode)
        , mRightNode(inRightNode)
    {
    }

    std::string LEvaluateAstNode::ToString()
    {
        return mLeftNode->ToString() + " " + mRightNode->ToString();
    }

    LAstNodePtr& LEvaluateAstNode::RefLeftNode()
    {
        return mLeftNode;
    }

    const LAstNodePtr& LEvaluateAstNode::RefLeftNode() const
    {
        return mLeftNode;
    }

    LAstNodePtr& LEvaluateAstNode::RefRightNode()
    {
        return mRightNode;
    }

    const LAstNodePtr& LEvaluateAstNode::RefRightNode() const
    {
        return mRightNode;
    }
}
