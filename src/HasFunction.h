#pragma once

#include <type_traits>

template <typename Type, typename = void>
struct HasFunctionSort : std::false_type {};

template <typename Type>
struct HasFunctionSort<Type, std::void_t<decltype(std::declval<Type>().sort())>> : std::true_type {};

template <typename T>
constexpr bool HasFunctionSort_v = HasFunctionSort<T>::value;