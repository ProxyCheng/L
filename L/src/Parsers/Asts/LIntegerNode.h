#pragma once
#include "LAstNode.h"

namespace L
{
    class LIntegerNode : public LAstNode
    {
    public:
        LIntegerNode(int inData);
        virtual std::string ToString() override;

    protected:
        int mData = 0;
    };
}
