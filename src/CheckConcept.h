#pragma once

#include <type_traits>

template <typename Type, template<typename> class Concept, typename = void>
struct CheckConcept : std::false_type {};

template <typename Type, template<typename> class Concept>
struct CheckConcept<Type, Concept, std::void_t<Concept<Type>>> : std::true_type {};
