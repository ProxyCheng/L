#pragma once
#include "LExpressionNode.h"
#include "LLambdaExpressionNode.h"
#include "src/Parsers/Asts/LLambdaAstNode.h"

namespace L
{
    class LParameterReferenceNode : public LExpressionNode
    {
    public:
        LParameterReferenceNode(LLambdaExpressionNode* inReferencedNode);
        virtual std::string ToString(LExpressionToStringContext& inContext) override;

    protected:
        LLambdaExpressionNode* mReferencedNode = nullptr;
    };

    using LParameterExpressionNodePtr = std::shared_ptr<LParameterReferenceNode>;
}
