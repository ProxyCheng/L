#include "LLambdaNode.h"

namespace L
{
    LLambdaNode::LLambdaNode(const LSymbolNodePtr& inHeadNode, const LAstNodePtr& inBodyNode)
        : mHeadNode(inHeadNode)
        , mBodyNode(inBodyNode)
    {
    }

    std::string LLambdaNode::ToString()
    {
        return std::string("L") + mHeadNode->ToString() + "." + mBodyNode->ToString();
    }
}
