#include "LAstNode.h"

namespace L
{
    LAstNode::LAstNode(LAstNodeType inType)
        : mType(inType)
    {
    }

    LAstNodeType LAstNode::GetType()
    {
        return mType;
    }
}
