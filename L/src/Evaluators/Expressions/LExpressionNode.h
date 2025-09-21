#pragma once
#include <memory>
#include <string>

namespace L
{
    enum LExpressionNodeType
    {
        LExpressionNodeType_Invalid = -1,
        LExpressionNodeType_Unknown = 0,
        LExpressionNodeType_Lambda,
        LExpressionNodeType_Evaluate,
        LExpressionNodeType_ParameterReference,
        LExpressionNodeType_NamedExpressionReference,
        LExpressionNodeType_Assign,
    };
    
    class LExpressionToStringContext;

    class LExpressionNode
    {
    public:
        LExpressionNode(LExpressionNodeType inType);
        virtual LExpressionNodeType GetType();
        virtual std::string ToString(LExpressionToStringContext& inContext) = 0;

    protected:
        LExpressionNodeType mType = LExpressionNodeType_Unknown;
    };

    using LExpressionNodePtr = std::shared_ptr<LExpressionNode>;
}
