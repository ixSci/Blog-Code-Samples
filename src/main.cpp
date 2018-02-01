#include <iostream>
#include "Printer.h"

using namespace std;

class IntPrinter
{
public:
    void operator()(int i)
    {
        cout << "Int passed: " << i << "\n";
    }
};

class FloatPrinter
{
public:
    void operator()(float f)
    {
        cout << "Float passed: " << f << "\n";
    }
};

int main()
{
    Cpp14::Printer<IntPrinter, FloatPrinter> printer14;
    printer14(55);
    printer14(55.1f);
    Cpp17::Printer<FloatPrinter, IntPrinter> printer17;
    printer17(1111);
    printer17(0.001f);
};