#pragma once

#include <type_traits>
#include <iostream>
#include <algorithm>

template <typename Type, typename = void>
struct HasFunctionSort : std::false_type {};

template <typename Type>
struct HasFunctionSort<Type, std::void_t<decltype(std::declval<Type>().sort())>> : std::true_type {};

template <typename T>
constexpr bool HasFunctionSort_v = HasFunctionSort<T>::value;


template<typename Container>
void sort(Container& container)
{
    if constexpr(HasFunctionSort_v<Container>)
    {
        std::cout << "Calling member sort function\n";
        container.sort();
    }
    else
    {
        std::cout << "Calling std::sort function\n";
        sort(begin(container), end(container));
    }
}
