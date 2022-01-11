#include <cassert>
#include <memory>
#include "Variant.h"

using std::construct_at;
using std::destroy_at;

Variant::Variant():
	m_Integral{None, 0}
{
}

Variant::Variant(int integral):
    m_Integral{Integral, integral}
{
}

Variant::Variant(const std::string& string):
	m_String{String, string}
{
}

Variant::Variant(const Variant& rhs)
{
    if(rhs.type() == String)
        construct_at(&m_String, rhs.m_String);
    else
        construct_at(&m_Integral, rhs.m_Integral);
}

Variant& Variant::operator=(const Variant& rhs)
{
    if(type() == String)
        destroy_at(&m_String);
    if(rhs.type() == String)
        construct_at(&m_String, rhs.m_String);
    else
        construct_at(&m_Integral, rhs.m_Integral);
    return *this;
}

Variant::~Variant()
{
    if(type() == String)
	    destroy_at(&m_String);
}

Variant::Type Variant::type() const
{
    return m_Integral.type;
}

int Variant::integral() const
{
    assert(type() == Integral);
    return m_Integral.value;
}

const std::string& Variant::string() const
{
    assert(type() == String);
    return m_String.value;
}
