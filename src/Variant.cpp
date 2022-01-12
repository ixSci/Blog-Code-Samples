#include <cassert>
#include <memory>
#include "Variant.h"

using std::construct_at;
using std::destroy_at;

Variant::Variant():
	m_Type{None}
{
}

Variant::Variant(int integral):
	m_Type{Integral},
    m_Integral{integral}
{
}

Variant::Variant(const std::string& string):
	m_Type{String},
	m_String{string}
{
}

Variant::Variant(const Variant& rhs)
{
    _copy(rhs);
}

Variant& Variant::operator=(const Variant& rhs)
{
    if(type() == String)
        destroy_at(&m_String);
    _copy(rhs);
    return *this;
}

Variant::~Variant()
{
    if(type() == String)
	    destroy_at(&m_String);
}

Variant::Type Variant::type() const
{
    return m_Type;
}

int Variant::integral() const
{
    assert(type() == Integral);
    return m_Integral;
}

const std::string& Variant::string() const
{
    assert(type() == String);
    return m_String;
}

void Variant::_copy(const Variant& rhs)
{
    if(rhs.type() == String)
        construct_at(&m_String, rhs.m_String);
    else if(rhs.type() == Integral)
        construct_at(&m_Integral, rhs.m_Integral);
    m_Type = rhs.type();
}
