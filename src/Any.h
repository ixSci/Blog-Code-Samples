#pragma once

#include <typeindex>
#include <stdexcept>
#include <utility>
#include <memory>
#include <type_traits>

namespace Details
{
    class AnyBase
    {
    public:
        virtual void* getData() = 0;
        virtual std::unique_ptr<AnyBase> clone() const = 0;
        virtual ~AnyBase() = default;
    };

    template <typename T>
    class AnyBaseImpl final: public AnyBase
    {
    public:
        AnyBaseImpl(const T& value):
            m_Data{value}
        {}

        AnyBaseImpl(T&& value):
            m_Data{std::move(value)}
        {}

        void* getData() override
        {
            return &m_Data;
        }

        std::unique_ptr<AnyBase> clone() const override
        {
            return std::make_unique<AnyBaseImpl<T>>(m_Data);
        }
    private:
        T m_Data;
    };
}

class Any final
{
public:
    template<typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, Any>>>
    Any(T&& var):
        m_AnyImpl{std::make_unique<Details::AnyBaseImpl<std::decay_t<T>>>(std::forward<T>(var))}
    {}

    Any(const Any& rhs):
        m_AnyImpl{rhs.m_AnyImpl->clone()}
    {
    }

    Any(Any&& rhs) = default;

    Any& operator=(const Any& rhs)
    {
        Any tmp{rhs};
        swap(*this, tmp);
        return *this;
    }

    Any& operator=(Any&& rhs) = default;

    template <typename T>
    friend T AnyCast(const Any& any);
    friend void swap(Any& lhs, Any& rhs)
    {
        using std::swap;
        swap(lhs.m_AnyImpl, rhs.m_AnyImpl);
    }
private:
    std::unique_ptr<Details::AnyBase> m_AnyImpl;
};

template <typename T>
T AnyCast(const Any& any)
{
    if(dynamic_cast<Details::AnyBaseImpl<T>*>(any.m_AnyImpl.get()))
        return *(static_cast<T*>(any.m_AnyImpl->getData()));
    throw std::logic_error("Any doesn't hold object of specified type");
}