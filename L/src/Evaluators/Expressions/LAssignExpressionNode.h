#pragma once
#include <string>

#include "LExpression.h"
#include "LExpressionNode.h"

namespace L
{
    class LAssignExpressionNode : public LExpressionNode
    {
    public:
        LAssignExpressionNode(const std::string& inLeftName);
        std::string& RefLeftName();
        const std::string& RefLeftName() const;
        LExpressionPtr& RefRightExpression();
        const LExpressionPtr& RefRightExpression() const;
        virtual std::string ToString(LExpressionToStringContext& inContext) override;

    protected:
        std::string mLeftName;
        LExpressionPtr mRightExpression;
    };

    using LAssignExpressionNodePtr = std::shared_ptr<LAssignExpressionNode>;
}
