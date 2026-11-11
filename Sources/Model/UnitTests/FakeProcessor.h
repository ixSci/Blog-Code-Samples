#pragma once

#include <gmock/gmock.h>
#include "INodeProcessor.h"
#include "Vertex.h"

class FakeProcessor: public INodeProcessor
{
public:
    FakeProcessor();
    MOCK_METHOD(void, processVertex, (const Vertex& vertex), (override));
};
