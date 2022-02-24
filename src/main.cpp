#include <iostream>
#include <string>
#include <vector>
#include "Variant.h"

using std::cout;
using namespace std::string_literals;

template<class... Ts>
struct overloaded: Ts...
{
    using Ts::operator()...;
};
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

using Variant_t = Variant<int, std::string, float, double, char>;

int main()
{
    Variant_t var{55};
    std::cout << "Var value=" << var.get<int>() << "\n";
    var = "hey"s;
    std::cout << "Var value=" << var.get<std::string>() << "\n";
    var = 42.;
    std::cout << "Var value=" << var.get<double>() << "\n";
    var = {};
    std::vector<Variant_t> variants = {{11}, {'C'}, {"string me"s}};
    for(const auto& var : variants )
    {
        var.match(overloaded {
            [](auto arg) { cout << "generic: " << arg << '\n';},
            [](int arg) { cout << "int: " << arg << '\n'; },
            [](char arg) { cout << "char: " << arg << '\n'; },
            [](const std::string& arg) { cout << "string: " << arg << '\n'; }
        });
    }
}