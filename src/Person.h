#pragma once

#include <string>
#include <vector>

class Person
{
public:
    Person() = default;
    Person(size_t memberNumber, size_t memberSize);
    Person(const Person& rhs);
    Person(Person&& rhs) noexcept;
    Person& operator=(const Person& rhs);
    Person& operator=(Person&& rhs) noexcept;
private:
    std::vector<std::string> m_Members;
    size_t m_Size{};
};