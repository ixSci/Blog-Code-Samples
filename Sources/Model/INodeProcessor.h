#pragma once

#include "INode.h"

class INodeProcessor
{
public:
    virtual void processNode(const INode& node) = 0;
    virtual ~INodeProcessor() = default;
};
