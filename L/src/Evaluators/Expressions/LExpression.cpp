#include "LExpression.h"

namespace L
{
    LExpressionNodePtr& LExpression::RefRoot()
    {
        return mRoot;
    }

    std::string LExpression::ToString()
    {
        if (mRoot)
        {
            LExpressionToStringContext context;
            return mRoot->ToString(context);
        }
        return "";
    }

    const LExpressionNodePtr& LExpression::RefRoot() const
    {
        return mRoot;
    }

    std::string LExpressionToStringContext::GenerateName()
    {
        std::string result;
        int nameCounter = mNameCounter++;
        do
        {
            result += static_cast<char>('a' + nameCounter % 26);
            nameCounter /= 26;
        }
        while (nameCounter > 0);
        return result;
    }

    std::string LExpressionToStringContext::RegisterNode(const LExpressionNode* inNode)
    {
        return mNode2Name.emplace(inNode, GenerateName()).first->second;
    }

    std::string LExpressionToStringContext::GetName(const LExpressionNode* inNode)
    {
        if (auto iter = mNode2Name.find(inNode); iter != mNode2Name.cend())
            return iter->second;
        return "";
    }
}
