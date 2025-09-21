#pragma once
#include "LExpressionNode.h"

namespace L
{
    class LEvaluateExpressionNode : public LExpressionNode
    {
    public:
        LEvaluateExpressionNode();
        LExpressionNodePtr& RefLeftNode();
        const LExpressionNodePtr& RefLeftNode() const;
        LExpressionNodePtr& RefRightNode();
        const LExpressionNodePtr& RefRightNode() const;
        virtual std::string ToString(LExpressionToStringContext& inContext) override;

    protected:
        LExpressionNodePtr mLeftNode;
        LExpressionNodePtr mRightNode;
    };

    using LEvaluateExpressionNodePtr = std::shared_ptr<LEvaluateExpressionNode>;
}
