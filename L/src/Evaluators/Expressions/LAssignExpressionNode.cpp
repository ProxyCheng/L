#include "LAssignExpressionNode.h"

namespace L
{
    LAssignExpressionNode::LAssignExpressionNode(const std::string& inLeftName)
        : LExpressionNode(LExpressionNodeType_Assign)
        , mLeftName(inLeftName)
    {
    }

    std::string& LAssignExpressionNode::RefLeftName()
    {
        return mLeftName;
    }

    const std::string& LAssignExpressionNode::RefLeftName() const
    {
        return mLeftName;
    }

    LExpressionPtr& LAssignExpressionNode::RefRightExpression()
    {
        return mRightExpression;
    }

    const LExpressionPtr& LAssignExpressionNode::RefRightExpression() const
    {
        return mRightExpression;
    }

    std::string LAssignExpressionNode::ToString(LExpressionToStringContext& inContext)
    {
        return mLeftName + "=" + mRightExpression->ToString();
    }
}
