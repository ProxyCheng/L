#include "LPrenthesesNode.h"

namespace L
{
    LParenthesesAstNode::LParenthesesAstNode(const LAstNodePtr& inChildNode)
        : LAstNode(LAstNodeType_Parentheses)
        , mChildNode(inChildNode)
    {
    }

    std::string LParenthesesAstNode::ToString()
    {
        return std::string("(") + mChildNode->ToString() + ")";
    }

    LAstNodePtr& LParenthesesAstNode::RefChildNode()
    {
        return mChildNode;
    }

    const LAstNodePtr& LParenthesesAstNode::RefChildNode() const
    {
        return mChildNode;
    }
}
