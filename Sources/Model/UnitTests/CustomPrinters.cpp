#include "CustomPrinters.h"

 void PrintTo(const INode& node, std::ostream* stream)
{
    *stream << node.toString();
}
