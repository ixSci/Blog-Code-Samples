#pragma once

#include <vector>
#include <initializer_list>
#include <iterator>

template <typename T>
class DummyVector
{
public:
    DummyVector() = default;
    DummyVector(std::initializer_list<T> list):
            m_Storage{list}
    {
    }

    template<typename Iter>
    DummyVector(Iter begin, Iter end):
            m_Storage{begin, end}
    {
    }
private:
    std::vector<T> m_Storage;
};

template<typename Iter>
DummyVector(Iter begin, Iter end) ->
    DummyVector<typename std::iterator_traits<Iter>::value_type>;
