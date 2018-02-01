#pragma once

namespace Cpp17
{
    template<typename... Ts>
    class Printer: public Ts...
    {
    public:
        using Ts::operator()...;
    };
}

namespace Cpp14
{
    template<typename... Ts>
    class Printer;
    template<typename T, typename... Ts>
    class Printer<T, Ts...>: public T, Printer<Ts...>
    {
    public:
        using T::operator();
        using Printer<Ts...>::operator();
    };

    template<>
    class Printer<>
    {
    public:
        void operator()();
    };
}

