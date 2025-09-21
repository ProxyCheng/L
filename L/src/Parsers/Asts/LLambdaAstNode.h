#pragma once
#include "LAstNode.h"
#include "LSymbolAstNode.h"

namespace L
{
    class LLambdaAstNode : public LAstNode
    {
    public:
        LLambdaAstNode(const LSymbolAstNodePtr& inHeadNode, const LAstNodePtr& inBodyNode);
        virtual std::string ToString() override;
        LSymbolAstNodePtr& RefHeadNode();
        const LSymbolAstNodePtr& RefHeadNode() const;
        LAstNodePtr& RefBodyNode();
        const LAstNodePtr& RefBodyNode() const;

    protected:
        LSymbolAstNodePtr mHeadNode;
        LAstNodePtr mBodyNode;
    };

    using LLambdaAstNodePtr = std::shared_ptr<LLambdaAstNode>;
}
