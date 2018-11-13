#include <iostream>
#include <utility>
#include "Function.h"

using std::cout;

int main()
{
    Function<void()> def{};
    Function<void()> func{[]{ cout << "It lives!\n";}};
    func();
    Function<long(int)> square([](int i) { return i*i; });
    auto square2 = std::move(square);
    auto square3 = square2;
    cout << "2^2=" << square2(2) << "\n";
    cout << "3^2=" << square3(3) <<  "\n";
}