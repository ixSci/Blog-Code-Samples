#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "FakeProcessor.h"

using namespace testing;

static void PrintTo(const Vertex& node, std::ostream *stream)
{
    *stream << "Fake Vertex: " << node.toString();
}

class ProcessorTest: public Test
{};

TEST_F(ProcessorTest, Factory_UninteresteCall_CallsCorrectPrintTo)
{
    StrictMock<FakeProcessor> factory;

    factory.processVertex(Vertex{"unexpected"});
}
