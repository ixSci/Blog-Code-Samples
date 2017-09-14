#pragma once

#include <type_traits>
#include <iostream>
#include <string>

template<typename T>
class StaticIf
{
public:
    template<typename U = T, typename = std::enable_if_t<std::is_integral_v<U>>>
    static void branch(std::string str)
    {
        std::cout << "String branch.\n";
    }

    template<typename U = T, typename = std::enable_if_t<!std::is_integral_v<U>>>
    static void branch(int)
    {
        std::cout << "Integer branch.\n";
    }
};