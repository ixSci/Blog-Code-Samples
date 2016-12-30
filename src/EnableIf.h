#pragma once

template <bool condition, typename Type = void>
struct EnableIf;

template <typename Type>
struct EnableIf<true, Type>
{
    typedef Type type;
};