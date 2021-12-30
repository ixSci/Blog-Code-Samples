#pragma once
#include <string>
#include <type_traits>

union Variant
{
public:
    enum Type{None, Integral, String};
public:
    Variant();
    explicit Variant(int integral);
    explicit Variant(const std::string& string);
    Variant(const Variant& rhs);
    Variant& operator=(const Variant& rhs);
    ~Variant();
    Type type() const;
    int integral() const;
    const std::string& string() const;
private:
    template<typename T>
    struct Member
    {
	    Type type;
        T value;
        static_assert(std::is_scalar_v<T> || std::is_standard_layout_v<T>,
            "T should be of scalar or standard-layout type");
    };
private:
    Member<int> m_Integral;
    Member<std::string> m_String;
};
