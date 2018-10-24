#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "Any.h"

using std::cout;
using std::vector;
using std::string;
using std::move;
using namespace std::string_literals;

int main()
{
    vector strings{"one"s, "two"s, "three"s, "four"s};
    Any first{strings};
    Any second = first;
    Any third{move(second)};
    Any fourth{vector<string>{}};
    fourth = move(third);
    auto result = AnyCast<decltype(strings)>(fourth);
    for(size_t i = 0; i < result.size(); ++i)
        result[i] = std::to_string(i + 1);
    for(size_t i = 0; i < result.size(); ++i)
        cout << "[" <<  result[i] << " - " << strings[i] << "]" << "\n";
}