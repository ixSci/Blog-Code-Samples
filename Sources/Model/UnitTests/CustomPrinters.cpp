#include "CustomPrinters.h"

void PrintTo(const Vertex *node, std::ostream *stream)
{
    *stream << node->toString();
}
