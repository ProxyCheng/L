#include "LEvaluateExpressionNode.h"

namespace L
{
    LEvaluateExpressionNode::LEvaluateExpressionNode()
        : LExpressionNode(LExpressionNodeType_Evaluate)
    {
    }

    LExpressionNodePtr& LEvaluateExpressionNode::RefLeftNode()
    {
        return mLeftNode;
    }

    const LExpressionNodePtr& LEvaluateExpressionNode::RefLeftNode() const
    {
        return mLeftNode;
    }

    LExpressionNodePtr& LEvaluateExpressionNode::RefRightNode()
    {
        return mRightNode;
    }

    const LExpressionNodePtr& LEvaluateExpressionNode::RefRightNode() const
    {
        return mRightNode;
    }

    std::string LEvaluateExpressionNode::ToString(LExpressionToStringContext& inContext)
    {
        return mLeftNode->ToString(inContext) + " " + mRightNode->ToString(inContext);
    }
}
