#include "LEvaluateNode.h"

namespace L
{
    LEvaluateNode::LEvaluateNode(const LAstNodePtr& inLeftNode, const LAstNodePtr& inRightNode)
        : mLeftNode(inLeftNode)
        , mRightNode(inRightNode)
    {
    }

    std::string LEvaluateNode::ToString()
    {
        return mLeftNode->ToString() + " " + mRightNode->ToString();
    }
}
