#include "LPrenthesesNode.h"

namespace L
{
    LParenthesesNode::LParenthesesNode(const LAstNodePtr& inChildNode)
        : mChildNode(inChildNode)
    {
    }

    std::string LParenthesesNode::ToString()
    {
        return std::string("(") + mChildNode->ToString() + ")";
    }
}
