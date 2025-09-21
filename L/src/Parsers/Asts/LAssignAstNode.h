#pragma once
#include "LAstNode.h"
#include "LSymbolAstNode.h"

namespace L
{
    class LAssignAstNode : public LAstNode
    {
    public:
        LAssignAstNode(const LSymbolAstNodePtr& inLeftNode, const LAstNodePtr& inRightNode);
        virtual std::string ToString() override;
        LSymbolAstNodePtr& RefLeftNode();
        const LSymbolAstNodePtr& RefLeftNode() const;
        LAstNodePtr& RefRightNode();
        const LAstNodePtr& RefRightNode() const;

    protected:
        LSymbolAstNodePtr mLeftNode;
        LAstNodePtr mRightNode;
    };
}
