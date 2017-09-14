#pragma once

#include <type_traits>
#include <string>

template<typename T>
auto returnHeadache(T val)
{
    if constexpr(std::is_same_v<T, std::string>)
        return 0;
    else
        return std::string{"str"};
    // Раскомментируйте, чтобы получить ошибку
    //return std::vector{1, 2, 3};
}
