#include <iostream>
#include <utility>
#include <string>
#define CUSTOM_INVOKE
#include "Function.h"

using std::cout;
using std::string;
using namespace std::string_literals;

int main()
{
    Function<size_t(const string&)> func{&string::size};
    auto str{"Hey!"s};
    cout << func(str) << "\n";
#ifndef CUSTOM_INVOKE
    Function<size_t(string* const)> func2{&string::size};
    cout << func2(&str) << "\n";
#endif
    Function<void(const string&)> printer{[](auto str) { cout << str << "\n";}};
    printer("ho ho");
}