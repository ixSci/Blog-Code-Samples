#include <cassert>
#include "Variant.h"

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
        new (&m_String) Member{rhs.m_String};
    else
        new (&m_Integral) Member{rhs.m_Integral};
}

Variant& Variant::operator=(const Variant& rhs)
{
    if(type() == String)
        m_String.value.~basic_string();
    if(rhs.type() == String)
        new (&m_String) Member{rhs.m_String};
    else
        new (&m_Integral) Member{rhs.m_Integral};
    return *this;
}

Variant::~Variant()
{
    if(type() == String)
	    m_String.value.~basic_string();
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
