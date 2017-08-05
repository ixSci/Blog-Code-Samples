#pragma once

template <typename T>
class Dummy
{
public:
    template <typename U>
    Dummy(T&& t, U&& u)
    {
    }
};


template <typename T, typename U>
explicit Dummy(T&&, U&&) -> Dummy<T>;
