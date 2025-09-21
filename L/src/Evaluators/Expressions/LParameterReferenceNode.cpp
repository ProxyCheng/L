#include "LParameterReferenceNode.h"

#include "LExpression.h"

namespace L
{
    LParameterReferenceNode::LParameterReferenceNode(LLambdaExpressionNode* inReferencedNode)
        : LExpressionNode(LExpressionNodeType_ParameterReference)
        , mReferencedNode(inReferencedNode)
    {
    }

    std::string LParameterReferenceNode::ToString(LExpressionToStringContext& inContext)
    {
        return inContext.GetName(mReferencedNode);
    }
}
