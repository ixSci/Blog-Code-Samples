#include <iostream>
#include <string>
#include "Variant.h"

using namespace std::string_literals;

int main()
{
    Variant<int, std::string> var{55};
    std::cout << "Var value=" << var.value<int>() << "\n";
    var = "hey"s;
    std::cout << "Var value=" << var.value<std::string>() << "\n";
    var = 42;
    std::cout << "Var value=" << var.value<int>() << "\n";
    var = {};;
}