#pragma once

#include <algorithm>
#include <array>

template<typename... Types>
class Variant;

namespace Details
{
    template<typename T, typename... Ts>
    consteval int getTypeIndex()
    {
        std::array answers{std::is_same_v<std::decay_t<T>, std::decay_t<Ts>>...};
        auto answer = std::find(answers.begin(), answers.end(), true);
        return answer != answers.end() ? std::distance(answers.begin(), answer) : -1;
    }

    template<unsigned currentIndex, typename T, typename... Tail, typename Variant, typename F>
    auto match(unsigned typeIndex, const Variant& variant, F&& function)
    {
        if(typeIndex == currentIndex)
            return std::invoke(function, variant.template get<currentIndex>());
        if constexpr(sizeof...(Tail) > 0)
            return match<currentIndex + 1, Tail...>(typeIndex, variant, std::forward<F>(function));
    }

    template<unsigned currentIndex, typename T, typename... Tail>
    void copy(unsigned sourceTypeIndex, const void* source, void* destination)
    {
        if(sourceTypeIndex == currentIndex)
            std::construct_at(static_cast<T*>(destination), *static_cast<const T*>(source));
        else if constexpr(sizeof...(Tail) > 0)
            copy<currentIndex + 1, Tail...>(sourceTypeIndex, source, destination);
    }

    template<unsigned currentIndex, typename T, typename... Tail>
    void destroy(unsigned typeIndex, void* storage)
    {
        if(typeIndex == currentIndex)
            std::destroy_at(static_cast<T*>(storage));
        else if constexpr(sizeof...(Tail) > 0)
            destroy<currentIndex + 1, Tail...>(typeIndex, storage);
    }
}

template<typename... Ts>
class Variant
{
public:
    Variant() = default;
    template<typename T> requires (Details::getTypeIndex<T, Ts...>() != -1)
    Variant(T&& value);
    Variant(const Variant& rhs);
    Variant& operator=(const Variant& rhs);
    template<typename T> requires (Details::getTypeIndex<T, Ts...>() != -1)
    const T& get() const;
    template<size_t Index> requires (Index < sizeof...(Ts))
    const auto& get() const;
    template<typename T> requires (Details::getTypeIndex<T, Ts...>() != -1)
    bool is() const;
    template<typename F>
    auto match(F&& function) const;
    ~Variant();
private:
    void _copy(const Variant& rhs);
    void _destroy();
private:
    int m_TypeIndex = -1;
    alignas(Ts...) std::byte m_Storage[std::max({sizeof(Ts)...})];
};

template<typename... Ts>
template<typename T>
requires (Details::getTypeIndex<T, Ts...>() != -1)
Variant<Ts...>::Variant(T&& value):
    m_TypeIndex{Details::getTypeIndex<T, Ts...>()}
{
    std::construct_at(reinterpret_cast<T*>(m_Storage), std::forward<T>(value));
}

template<typename... Ts>
Variant<Ts...>::Variant(const Variant& rhs)
{
    _copy(rhs);
}

template<typename... Ts>
Variant<Ts...>& Variant<Ts...>::operator=(const Variant& rhs)
{
    _destroy();
    _copy(rhs);
    return *this;
}

template<typename... Ts>
template<typename T>
	requires (Details::getTypeIndex<T, Ts...>() != -1)
const T& Variant<Ts...>::get() const
{
    if(is<T>())
        return *(reinterpret_cast<const T*>(m_Storage));
    throw std::logic_error("Wrong type!");
}

template <typename ... Ts>
template <size_t Index> requires (Index < sizeof...(Ts))
const auto& Variant<Ts...>::get() const
{
    using Type_t = std::tuple_element_t<Index, std::tuple<Ts...>>;
    return get<Type_t>();
}

template<typename... Ts>
template<typename T>
	requires (Details::getTypeIndex<T, Ts...>() != -1)
bool Variant<Ts...>::is() const
{
    return Details::getTypeIndex<T, Ts...>() == m_TypeIndex;
}

template<typename... Ts>
template<typename F>
auto Variant<Ts...>::match(F&& function) const
{
    if(m_TypeIndex == -1)
        return;
    return Details::match<0, Ts...>(m_TypeIndex, *this, std::forward<F>(function));
}

template<typename... Ts>
Variant<Ts...>::~Variant()
{
    _destroy();
}

template<typename... Ts>
void Variant<Ts...>::_copy(const Variant& rhs)
{
    if(rhs.m_TypeIndex != -1)
        Details::copy<0, Ts...>(rhs.m_TypeIndex, rhs.m_Storage, m_Storage);
    m_TypeIndex = rhs.m_TypeIndex;
}

template<typename... Ts>
void Variant<Ts...>::_destroy()
{
    if(m_TypeIndex != -1)
        Details::destroy<0, Ts...>(m_TypeIndex, m_Storage);
}
