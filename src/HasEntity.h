#include "CheckConcept.h"

#define GENERATE_HAS_FUNCTION(name, functionExpression) \
    template <typename T> \
    using HasMember ## name ## Cooncept_t = decltype(std::declval<T>().functionExpression); \
    template <typename T> \
    constexpr bool HasFunction ## name ## _v = CheckConcept<T, HasMember ## name ## Cooncept_t>::value;
