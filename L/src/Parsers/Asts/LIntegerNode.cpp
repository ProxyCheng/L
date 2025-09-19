#include "LIntegerNode.h"

namespace L
{
    LIntegerNode::LIntegerNode(int inData)
        : mData(inData)
    {
    }

    std::string LIntegerNode::ToString()
    {
        return std::to_string(mData);
    }
}
