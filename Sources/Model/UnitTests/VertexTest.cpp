#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <format>
#include "Vertex.h"

using namespace testing;

MATCHER_P(NodeEq, expected, std::format(R"({} equal to "{}")", negation ? "isn't" : "is", expected.toString()))
{
    return arg.equals(expected);
}

class VertexTest: public Test
{};

TEST_F(VertexTest, Equals_DifferentVertices_ReturnsFalse)
{
    const Vertex expected{"expected"};

    const Vertex actual{"actual"};

    EXPECT_THAT(actual, NodeEq(expected));
}
