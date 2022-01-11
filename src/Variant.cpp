#include <cassert>
#include <memory>
#include "Variant.h"

using std::construct_at;
using std::destroy_at;

Variant::Variant(int integral):
	m_Type{Integral},
    m_Container{integral}
{
}

Variant::Variant(const std::string& string):
	m_Type{String},
	m_Container{string}
{
}

Variant::Variant(const Variant& rhs)
{
    _copy(rhs);
}

Variant& Variant::operator=(const Variant& rhs)
{
    if(type() == String)
        destroy_at(&m_Container.string);
    _copy(rhs);
    return *this;
}

Variant::~Variant()
{
    if(type() == String)
	    destroy_at(&m_Container.string);
}

Variant::Type Variant::type() const
{
    return m_Type;
}

int Variant::integral() const
{
    assert(type() == Integral);
    return m_Container.integral;
}

const std::string& Variant::string() const
{
    assert(type() == String);
    return m_Container.string;
}

void Variant::_copy(const Variant& rhs)
{
    if(rhs.type() == String)
        construct_at(&m_Container.string, rhs.m_Container.string);
    else if(rhs.type() == Integral)
        construct_at(&m_Container.integral, rhs.m_Container.integral);
    m_Type = rhs.type();
}

Variant::Container::Container()
{
}

Variant::Container::Container(int val):
	integral{val}
{
}

Variant::Container::Container(const std::string& val):
	string{val}
{
}

Variant::Container::~Container()
{
}


