#pragma once
#include <string>
#include <type_traits>

union Variant
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
    template<typename T>
    requires std::is_scalar_v<T> || std::is_standard_layout_v<T>
    struct Member
    {
	    Type type;
        T value;
    };
private:
    Member<int> m_Integral;
    Member<std::string> m_String;
};
