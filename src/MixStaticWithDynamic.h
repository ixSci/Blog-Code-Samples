#pragma once

#include <type_traits>
#include <iostream>
#include <string>

template <typename T>
void mixStaticWithDynamicIncorrect(T val)
{
    if constexpr(std::is_integral<T>::value)
        std::cout << "Integral passed.";
    else if(val == std::string{"clone"})
        std::cout << "Known string passed.";
    else if constexpr(std::is_same_v<T, std::string>)
        std::cout << "General string passed.";
    else
        std::cout << "Unknown type variable passed.";
    std::cout << "\n";
}

template <typename T>
void mixStaticWithDynamicCorrect(T val)
{
    if constexpr(std::is_integral<T>::value)
        std::cout << "Integral passed.";
    else if constexpr(std::is_same_v<T, std::string>)
    {
        if(val == std::string{"clone"})
            std::cout << "Known string passed.";
        else
            std::cout << "General string passed.";
    }
    else
        std::cout << "Unknown type variable passed.";
    std::cout << "\n";
}