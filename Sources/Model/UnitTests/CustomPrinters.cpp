#include "CustomPrinters.h"

void PrintToTest(const INode& node, std::ostream* stream)
{
    *stream << node.toString();
}
