#pragma once

#include <gmock/gmock.h>
#include "INode.h"
#include "INodeProcessor.h"

class FakeProcessor: public INodeProcessor
{
public:
    FakeProcessor();
    MOCK_METHOD(void, processNode, (const INode& vertex), (override));
};
