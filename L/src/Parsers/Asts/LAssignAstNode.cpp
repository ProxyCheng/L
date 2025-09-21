#include "LAssignAstNode.h"

namespace L
{
    LAssignAstNode::LAssignAstNode(const LSymbolAstNodePtr& inLeftNode, const LAstNodePtr& inRightNode)
        : LAstNode(LAstNodeType_Assign)
        , mLeftNode(inLeftNode)
        , mRightNode(inRightNode)
    {
    }

    std::string LAssignAstNode::ToString()
    {
        return mLeftNode->ToString() + "=" + mRightNode->ToString();
    }

    LSymbolAstNodePtr& LAssignAstNode::RefLeftNode()
    {
        return mLeftNode;
    }

    const LSymbolAstNodePtr& LAssignAstNode::RefLeftNode() const
    {
        return mLeftNode;
    }

    LAstNodePtr& LAssignAstNode::RefRightNode()
    {
        return mRightNode;
    }

    const LAstNodePtr& LAssignAstNode::RefRightNode() const
    {
        return mRightNode;
    }
}
