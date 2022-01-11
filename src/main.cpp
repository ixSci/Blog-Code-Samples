#include <iostream>
#include <string>
#include "Variant.h"

using namespace std::string_literals;

int main()
{
    Variant var;
    std::cout << "Var type: " << var.type() << "\n";
    var = 55;
    std::cout << "Var type: " << var.type() << ", value=" << var.integral() << "\n";
    var = "hey"s;
    std::cout << "Var type: " << var.type() << ", value=" << var.string() << "\n";
    var = 42;
    std::cout << "Var type: " << var.type() << ", value=" << var.integral() << "\n";
    var = Variant{};
    std::cout << "Var type: " << var.type() << "\n";
}