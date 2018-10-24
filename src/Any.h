#pragma once

#include <typeindex>
#include <stdexcept>
#include <utility>

struct Any
{
private:
    enum Action {Copy, Delete};
    using MagicHandler_t = void*(*)(void*, Action);
public:
    template<typename T>
    Any(const T& var) :
        m_Data{new T{var}},
        m_Type{typeid(var)},
        m_MagicHandler{[](void* ptr, Action action)
        {
            void* result = nullptr;
            if(action == Copy)
                result =  new T(*static_cast<T*>(ptr));
            else
                delete static_cast<T*>(ptr);
            return result;
        }}
    {}

    Any(const Any& rhs):
        m_Data{rhs.m_MagicHandler(rhs.m_Data, Copy)},
        m_Type{rhs.m_Type},
        m_MagicHandler{rhs.m_MagicHandler}
    {
    }

    Any(Any&& rhs):
        m_Data{rhs.m_Data},
        m_Type{rhs.m_Type},
        m_MagicHandler{rhs.m_MagicHandler}
    {
        rhs.m_MagicHandler = [](void*, Action) -> void* { return nullptr; };
    }

    Any& operator=(const Any& rhs)
    {
        Any tmp{rhs};
        swap(*this, tmp);
        return *this;
    }

    Any& operator=(Any&& rhs)
    {
        swap(*this, rhs);
        return *this;
    }

    ~Any()
    {
        m_MagicHandler(m_Data, Delete);
    }

    template <typename T>
    friend T AnyCast(const Any& any);
    friend void swap(Any& lhs, Any& rhs)
    {
        using std::swap;
        swap(lhs.m_Data, rhs.m_Data);
        swap(lhs.m_Type, rhs.m_Type);
        swap(lhs.m_MagicHandler, rhs.m_MagicHandler);
    }
private:
    void* m_Data;
    std::type_index m_Type;
    MagicHandler_t m_MagicHandler;
};

template <typename T>
T AnyCast(const Any& any)
{
    if(any.m_Type == typeid(T))
        return *(static_cast<T*>(any.m_Data));
    throw std::logic_error("Any doesn't hold object of specified type");
}