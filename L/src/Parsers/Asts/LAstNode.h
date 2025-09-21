#pragma once
#include <memory>
#include <string>

namespace L
{
    enum LAstNodeType
    {
        LAstNodeType_Invalid = -1,
        LAstNodeType_Unknown = 0,
        LAstNodeType_Symbol,
        LAstNodeType_Lambda,
        LAstNodeType_Parentheses,
        LAstNodeType_Evaluate,
        LAstNodeType_Assign,
    };
    
    class LAstNode
    {
    public:
        LAstNode(LAstNodeType inType);
        virtual ~LAstNode() = default;
        LAstNodeType GetType();
        virtual std::string ToString() = 0;

    protected:
        LAstNodeType mType = LAstNodeType_Invalid;
    };

    using LAstNodePtr = std::shared_ptr<LAstNode>;
}
