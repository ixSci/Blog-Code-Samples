#include <iostream>
#include "Pods.h"
#include "Person.h"

using namespace std;

void decomposeArrayCopyExample();
void decomposeArrayRefExample();
void decomposeStructExample();
void decomposePersonExample();

int main(int argc, char* argv[])
{
    decomposeArrayCopyExample();
    decomposeArrayRefExample();
    decomposeStructExample();
    decomposePersonExample();
    return 0;
}

void decomposeArrayCopyExample()
{
    cout << "=== Copy Example ===\n";
    int array[] = {1, 3, 5, 7, 9};
    auto [a1, a2, a3, a4, a5] = array;
    cout << "Third element before: " << a3 << "(" << array[2] << ")\n";
    a3 = 4;
    cout << "Third element after: " << a3 << "(" << array[2] << ")\n";
}

void decomposeArrayRefExample()
{
    cout << "=== Reference Example ===\n";
    int array[] = {1, 3, 5, 7, 9};
    auto& [a1, a2, a3, a4, a5] = array;
    cout << "Third element before: " << a3 << "(" << array[2] << ")\n";
    a3 = 4;
    cout << "Third element after: " << a3 << "(" << array[2] << ")\n";
}

void decomposeStructExample()
{
    cout << "=== Structs Example ===\n";
    auto [f, s, t] = SimpleStruct{};
    cout << "first: " << f
         << ", second: " << s
         << ", third: " << t << "\n";
    ComplexStruct complexStruct{};
    auto& [simple, answer] = complexStruct;
    complexStruct.simple.third = 3.33f;
    cout << "simple.third: " << simple.third
         << ", answer: " << answer << "\n";
}

void decomposePersonExample()
{
    cout << "=== Person Example ===\n";
    Person einstain{"Albert", "Einstein", 997};
    const auto [id, first, last] = einstain;
    cout << "ID: " << id
         << ", First name: " << first
         << ", Last name: " << last << "\n";
}
