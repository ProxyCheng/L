#include "LAst.h"

namespace L
{
    class LAstRootNode : public LAstNode
    {
        
    };
    
    LAstNodePtr& LAst::RefRoot()
    {
        return mRoot;
    }

    const LAstNodePtr& LAst::RefRoot() const
    {
        return mRoot;
    }

    std::string LAst::ToString()
    {
        if (!mRoot)
            return "";
        return mRoot->ToString();
    }
}
