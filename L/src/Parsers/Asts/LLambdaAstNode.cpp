#include "LLambdaAstNode.h"

namespace L
{
    LLambdaAstNode::LLambdaAstNode(const LSymbolAstNodePtr& inHeadNode, const LAstNodePtr& inBodyNode)
        : LAstNode(LAstNodeType_Lambda)
        , mHeadNode(inHeadNode)
        , mBodyNode(inBodyNode)
    {
    }

    std::string LLambdaAstNode::ToString()
    {
        return std::string("L") + mHeadNode->ToString() + "." + mBodyNode->ToString();
    }

    LSymbolAstNodePtr& LLambdaAstNode::RefHeadNode()
    {
        return mHeadNode;
    }

    const LSymbolAstNodePtr& LLambdaAstNode::RefHeadNode() const
    {
        return mHeadNode;
    }

    LAstNodePtr& LLambdaAstNode::RefBodyNode()
    {
        return mBodyNode;
    }

    const LAstNodePtr& LLambdaAstNode::RefBodyNode() const
    {
        return mBodyNode;
    }
}
