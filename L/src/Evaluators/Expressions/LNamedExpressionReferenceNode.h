#pragma once
#include "LExpression.h"

namespace L
{
    class LNamedExpressionReferenceNode : public LExpressionNode
    {
    public:
        LNamedExpressionReferenceNode(LExpression* inReferencedExpression, const std::string& inReferencedName);
        virtual std::string ToString(LExpressionToStringContext& inContext) override;

    protected:
        LExpression* mReferencedExpression = nullptr;
        std::string mReferencedName;
    };
}
