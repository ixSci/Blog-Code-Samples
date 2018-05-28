#pragma once

#include <functional>
#include <string>

struct Printers
{
    std::function<void(const std::string&)> stringPrinter;
    std::function<void(int)> intPrinter;
    std::function<void(float)> floatPrinter;
};