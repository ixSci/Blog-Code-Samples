#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "FakeProcessor.h"

using namespace testing;

class ProcessorTest: public Test
{};

TEST_F(ProcessorTest, Factory_UninteresteCall_CallsCorrectPrintTo)
{
    StrictMock<FakeProcessor> factory;

    factory.processVertex(Vertex{"unexpected"});
}
