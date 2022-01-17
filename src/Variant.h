#pragma once

#include <cassert>
#include <memory>

template<typename FirstT, typename SecondT>
class Variant
{
public:
    Variant();
    Variant(const FirstT& value);
    Variant(const SecondT& value);
    Variant(const Variant& rhs);
    Variant& operator=(const Variant& rhs);
    ~Variant();
    template<typename Type>
    const Type& value() const;
private:
    union
    {
	    FirstT m_First;
        SecondT m_Second;
    };
    enum Type{None, First, Second};
private:
    void _copy(const Variant& rhs);
    void _destroy();
private:
    Type m_Type;
};

template<typename FirstT, typename SecondT>
Variant<FirstT, SecondT>::Variant():
	m_Type{None}
{
}

template<typename FirstT, typename SecondT>
Variant<FirstT, SecondT>::Variant(const FirstT& value):
	m_Type{First},
	m_First{value}
	
{
}

template<typename FirstT, typename SecondT>
Variant<FirstT, SecondT>::Variant(const SecondT& value):
	m_Type{Second},
	m_Second{value}
	
{
}

template<typename FirstT, typename SecondT>
Variant<FirstT, SecondT>::Variant(const Variant& rhs)
{
    _copy(rhs);
}

template<typename FirstT, typename SecondT>
Variant<FirstT, SecondT>& Variant<FirstT, SecondT>::operator=(const Variant& rhs)
{
    _destroy();
    _copy(rhs);
    return *this;
}

template<typename FirstT, typename SecondT>
Variant<FirstT, SecondT>::~Variant()
{
    _destroy();
}

template <typename FirstT, typename SecondT>
template <typename Type>
const Type& Variant<FirstT, SecondT>::value() const
{
    if constexpr(std::is_same_v<Type, FirstT>)
    {
	    if(m_Type == First)
            return m_First;
    }
    else if constexpr(std::is_same_v<Type, SecondT>)
    {
	    if(m_Type == Second)
            return m_Second;
    }
    assert(false);
    throw std::logic_error{"oops?!"};
}

template<typename FirstT, typename SecondT>
void Variant<FirstT, SecondT>::_copy(const Variant& rhs)
{
    if(rhs.m_Type == First)
        std::construct_at(&m_First, rhs.m_First);
    else if(rhs.m_Type == Second)
        std::construct_at(&m_Second, rhs.m_Second);
    m_Type = rhs.m_Type;
}

template <typename FirstT, typename SecondT>
void Variant<FirstT, SecondT>::_destroy()
{
	if(m_Type == First)
		std::destroy_at(&m_First);
	else if(m_Type == Second)
		std::destroy_at(&m_Second);
}
