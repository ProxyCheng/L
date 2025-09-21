#pragma once
#include <memory>
#include <unordered_map>

#include "LDiagnostic.h"
#include "LExpressionNode.h"

namespace L
{
    class LExpression
    {
    public:
        LExpressionNodePtr& RefRoot();
        std::string ToString();
        const LExpressionNodePtr& RefRoot() const;

    protected:
        std::shared_ptr<LExpressionNode> mRoot;
    };

    using LExpressionPtr = std::shared_ptr<LExpression>;

    class LExpressionToStringContext
    {
    public:
        std::string GenerateName();
        std::string RegisterNode(const LExpressionNode* inNode);
        std::string GetName(const LExpressionNode* inNode);

    protected:
        std::unordered_map<const LExpressionNode*, std::string> mNode2Name;
        int mNameCounter = 0;
    };
}
