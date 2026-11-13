#include <ostream>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "CustomPrinters.h"
#include "FakeProcessor.h"
#include "Vertex.h"

using namespace testing;

static void PrintTo(const Vertex& node, std::ostream* stream)
{
    *stream << "Fake Vertex: " << node.toString();
}

class ProcessorTest: public Test
{};

TEST_F(ProcessorTest, Processor_UninterestingCall_CallsCorrectPrintTo)
{
    StrictMock<FakeProcessor> processor;

    processor.processNode(Vertex{"unexpected"});
}
