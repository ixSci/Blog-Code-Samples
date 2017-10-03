#pragma once

#include <string>
#include <tuple>
#include <iostream>

class Person
{
public:
    Person(const std::string& first, const std::string& last, size_t id):
            m_FirstName{first},
            m_LastName{last},
            m_Id{id}
    {
    }

    const std::string& firstName() const noexcept
    {
        return m_FirstName;
    }

    const std::string& lastName() const noexcept
    {
        return m_LastName;
    }

    size_t id() const noexcept
    {
        return m_Id;
    }
private:
    std::string m_FirstName;
    std::string m_LastName;
    size_t m_Id;
};

template <size_t Position>
decltype(auto) get(const Person& person)
{
    if constexpr(Position == 0)
        return person.id();
    else if constexpr(Position == 1)
        return person.firstName();
    else if constexpr(Position == 2)
        return person.lastName();
};

namespace std
{
    template<>
    struct tuple_size<Person>: std::integral_constant<size_t, 3>
    {
    };

    template<>
    struct tuple_element<0, Person>
    {
        using type = size_t;
    };

    template<>
    struct tuple_element<1, Person>
    {
        using type = std::string;
    };

    template<>
    struct tuple_element<2, Person>
    {
        using type = std::string;
    };
}

