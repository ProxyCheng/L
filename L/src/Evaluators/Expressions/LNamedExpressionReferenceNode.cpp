#include "LNamedExpressionReferenceNode.h"

namespace L
{
    LNamedExpressionReferenceNode::LNamedExpressionReferenceNode(LExpression* inReferencedExpression, const std::string& inReferencedName)
        : LExpressionNode(LExpressionNodeType_NamedExpressionReference)
        , mReferencedExpression(inReferencedExpression)
        , mReferencedName(inReferencedName)
    {
    }

    std::string LNamedExpressionReferenceNode::ToString(LExpressionToStringContext& inContext)
    {
        return mReferencedName;
    }
}
