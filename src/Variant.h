#pragma once
#include <string>

struct Variant
{
public:
    enum Type{None, Integral, String};
public:
    Variant();
    Variant(int integral);
    Variant(const std::string& string);
    Variant(const Variant& rhs);
    Variant& operator=(const Variant& rhs);
    ~Variant();
    Type type() const;
    int integral() const;
    const std::string& string() const;
private:
    union
    {
	    int m_Integral;
        std::string m_String;
    };
private:
    void _copy(const Variant& rhs);
private:
    Type m_Type;
};
