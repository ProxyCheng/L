#include "LLambdaExpressionNode.h"

#include "LExpression.h"

namespace L
{
    LLambdaExpressionNode::LLambdaExpressionNode()
        : LExpressionNode(LExpressionNodeType_Lambda)
    {
    }

    LExpressionNodePtr& LLambdaExpressionNode::RefChildNode()
    {
        return mChildNode;
    }

    const LExpressionNodePtr& LLambdaExpressionNode::RefChildNode() const
    {
        return mChildNode;
    }

    std::string LLambdaExpressionNode::ToString(LExpressionToStringContext& inContext)
    {
        std::string parameterName = inContext.RegisterNode(this);
        std::string childString = mChildNode->ToString(inContext);
        if (mChildNode->GetType() == LExpressionNodeType_Evaluate)
            childString = std::string("(") + childString + ")";
        return std::string("L") + parameterName + "." + childString;
    }
}
