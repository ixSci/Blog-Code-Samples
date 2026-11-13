#pragma once

#include <ostream>
#include <gtest/gtest.h>

template<typename T>
concept PrintableToTest = requires (T value, ::std::ostream* os) { PrintToTest(value, os); };

template<typename T>
    requires true
void PrintTo(const T& value, std::ostream* os)
{
    if constexpr(PrintableToTest<T>)
        PrintToTest(value, os);
    else
    {
#ifdef DISABLE_GTEST_BLACKHOLE
        static_assert(false, "Provide PrintToTest function");
#else
        testing::internal::PrintTo(value, os);
#endif
    }
}

void PrintToTest(PrintableToTest auto* ptr, std::ostream* os)
{
    PrintToTest(*ptr, os);
}
