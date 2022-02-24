#pragma once

#include <algorithm>
#include <array>
#include <typeindex>

template<typename... Types>
class Variant;

namespace Details
{
    class StorageBase
    {
    public:
        virtual std::unique_ptr<StorageBase> clone() const = 0;
        virtual void* data() = 0;
        virtual std::type_index typeIndex() = 0;
        virtual ~StorageBase() = default;
    };

    template<typename T>
    class StorageImpl final: public StorageBase
    {
    public:
        explicit StorageImpl(const T& data):
            m_Data{data}
        {
        }

        std::unique_ptr<StorageBase> clone() const override
        {
            return std::make_unique<StorageImpl<T>>(m_Data);
        }

        void* data() override
        {
            return &m_Data;
        }

        std::type_index typeIndex() override
        {
            return typeid(T);
        }
    private:
        T m_Data;
    };

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
private:
    void _copy(const Variant& rhs);
private:
    int m_TypeIndex = -1;
    std::unique_ptr<Details::StorageBase> m_Storage;
};

template<typename... Ts>
template<typename T>
    requires (Details::getTypeIndex<T, Ts...>() != -1)
Variant<Ts...>::Variant(T&& value):
    m_TypeIndex{Details::getTypeIndex<T, Ts...>()},
    m_Storage{std::make_unique<Details::StorageImpl<T>>(value)}
{
}

template<typename... Ts>
Variant<Ts...>::Variant(const Variant& rhs)
{
    _copy(rhs);
}

template<typename... Ts>
Variant<Ts...>& Variant<Ts...>::operator=(const Variant& rhs)
{
    _copy(rhs);
    return *this;
}

template<typename... Ts>
template<typename T>
    requires (Details::getTypeIndex<T, Ts...>() != -1)
const T& Variant<Ts...>::get() const
{
    if(is<T>())
        return *(reinterpret_cast<const T*>(m_Storage->data()));
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
    return m_Storage->typeIndex() == typeid(T);
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
void Variant<Ts...>::_copy(const Variant& rhs)
{
    if(rhs.m_TypeIndex != -1)
        m_Storage = rhs.m_Storage->clone();
    else
        m_Storage.reset();
    m_TypeIndex = rhs.m_TypeIndex;
}