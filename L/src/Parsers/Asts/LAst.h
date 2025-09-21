#pragma once
#include <string>

#include "LAstNode.h"

namespace L
{
    class LAst
    {
    public:
        LAstNodePtr& RefRoot();
        const LAstNodePtr& RefRoot() const;
        std::string ToString();
        
    protected:
        LAstNodePtr mRoot;
    };
}
