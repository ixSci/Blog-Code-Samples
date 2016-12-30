#pragma once

typedef char False_t;
typedef char True_t[2];

template <typename Type>
struct HasFunctionSort
{
    typedef void (Type::*Signature)();
    template<typename T, Signature = &T::sort>
    class Dummy;

    template<typename T>
    static True_t& test(T*, Dummy<T>* = 0);
    static False_t& test(...);

    static const bool value = sizeof(test(static_cast<Type*>(0))) == sizeof(True_t);
};
