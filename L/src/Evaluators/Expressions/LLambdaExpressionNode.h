#pragma once
#include "LExpressionNode.h"

namespace L
{
    class LLambdaExpressionNode : public LExpressionNode
    {
    public:
        LLambdaExpressionNode();
        LExpressionNodePtr& RefChildNode();
        const LExpressionNodePtr& RefChildNode() const;
        virtual std::string ToString(LExpressionToStringContext& inContext) override;

    protected:
        LExpressionNodePtr mChildNode;
    };

    using LLambdaExpressionNodePtr = std::shared_ptr<LLambdaExpressionNode>;
}
