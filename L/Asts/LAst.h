#pragma once
#include <string>

#include "LAstNode.h"

namespace L
{
    class LAst
    {
    public:
        LAstNodePtr& RefRoot();
        std::string ToString();
        
    protected:
        LAstNodePtr mRoot;
    };
}
