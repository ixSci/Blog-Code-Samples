#pragma once

#include "Vertex.h"

class INodeProcessor
{
public:
    virtual void processVertex(const Vertex& vertex) = 0;
    virtual ~INodeProcessor() = default;
};
