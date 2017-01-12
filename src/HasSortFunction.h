#pragma once

#include "CheckConcept.h"

template <typename T>
using HasMemberSortCooncept_t = decltype(std::declval<T>().sort());

template <typename T>
constexpr bool HasFunctionSort_v = CheckConcept<T, HasMemberSortCooncept_t>::value;