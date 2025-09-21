#include "LExpressionNode.h"

namespace L
{
    LExpressionNode::LExpressionNode(LExpressionNodeType inType)
        : mType(inType)
    {
    }

    LExpressionNodeType LExpressionNode::GetType()
    {
        return mType;
    }
}
