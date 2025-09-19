#include "LAssignNode.h"

namespace L
{
    LAssignNode::LAssignNode(const LSymbolNodePtr& inLeftNode, const LAstNodePtr& inRightNode)
        : mLeftNode(inLeftNode)
        , mRightNode(inRightNode)
    {
    }

    std::string LAssignNode::ToString()
    {
        return mLeftNode->ToString() + "=" + mRightNode->ToString();
    }
}
