#pragma once

#include <type_traits>

template <typename Type>
struct HasFunctionSort
{
    template<typename T>
    static auto test(T&&) -> decltype(std::declval<T>().sort(), std::true_type{});
    static std::false_type test(...);

    static constexpr bool value = std::is_same<decltype(test(std::declval<Type>())), std::true_type>::value;
};

template <typename T>
constexpr bool HasFunctionSort_v = HasFunctionSort<T>::value;