#pragma once
#include "LAstNode.h"
#include "LSymbolNode.h"

namespace L
{
    class LLambdaNode : public LAstNode
    {
    public:
        LLambdaNode(const LSymbolNodePtr& inHeadNode, const LAstNodePtr& inBodyNode);
        virtual std::string ToString() override;

    protected:
        LSymbolNodePtr mHeadNode;
        LAstNodePtr mBodyNode;
    };

    using LLambdaNodePtr = std::shared_ptr<LLambdaNode>;
}
