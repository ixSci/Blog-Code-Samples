#include <iostream>
#include <string>
#include "Variant.h"

int main()
{
    Variant var;
    std::cout << "Var type: " << var.type() << "\n";
    var = Variant{55};
    std::cout << "Var type: " << var.type() << ", value=" << var.integral() << "\n";
    var = Variant{"hey"};
    std::cout << "Var type: " << var.type() << ", value=" << var.string() << "\n";
}