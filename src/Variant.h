#pragma once
#include <string>

struct Variant
{
public:
    enum Type{None, Integral, String};
public:
    Variant() = default;
    Variant(int integral);
    Variant(const std::string& string);
    Variant(const Variant& rhs);
    Variant& operator=(const Variant& rhs);
    ~Variant();
    Type type() const;
    int integral() const;
    const std::string& string() const;
private:
    union Container
    {
        Container();
        Container(int val);
        Container(const std::string& val);
        ~Container();
	    int integral;
        std::string string;
    };
private:
    void _copy(const Variant& rhs);
private:
    Type m_Type = None;
    Container m_Container;
};
