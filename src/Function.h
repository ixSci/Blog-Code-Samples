#include <memory>
#include <type_traits>
#include <utility>

namespace Details
{
    template<typename R, typename... Args>
    class FunctionBase
    {
    public:
        virtual R operator()(Args... args) const = 0;
        virtual std::unique_ptr<FunctionBase> clone() const = 0;
        virtual ~FunctionBase() = default;
    };

    template<typename Functor, typename R, typename... Args>
    class FunctionImpl final: public FunctionBase<R, Args...>
    {
    public:
        FunctionImpl(const Functor& functor):
            m_Functor{functor}
        {
        }

        FunctionImpl(Functor&& functor):
            m_Functor{std::move(functor)}
        {
        }

        R operator()(Args... args) const override
        {
            return m_Functor(args...);
        }

        std::unique_ptr<FunctionBase<R, Args...>> clone() const override
        {
            return std::make_unique<FunctionImpl>(m_Functor);
        }
    private:
        Functor m_Functor;
    };
}

template<typename>
class Function;

template<typename R, typename... Args>
class Function<R(Args...)> final
{
public:
    Function() = default;

    template<typename Functor,
        typename = std::enable_if_t<std::is_convertible_v<std::invoke_result_t<Functor, Args...>, R>>,
        typename = std::enable_if_t<!std::is_same_v<std::decay_t<Functor>, Function>>>
    Function(Functor&& functor):
        m_Functor{std::make_unique<Details::FunctionImpl<Functor, R, Args...>>(std::forward<Functor>(functor))}
    {
    }

    Function(const Function& rhs):
        m_Functor{rhs.m_Functor->clone()}
    {
    }

    Function(Function&& rhs) = default;

    Function& operator=(const Function& rhs)
    {
        Function tmp{rhs};
        swap(*this, tmp);
        return *this;
    }

    Function& operator=(Function&& rhs) = default;

    R operator()(Args... args) const
    {
        return (*m_Functor)(args...);
    }

    friend void swap(Function& lhs, Function& rhs)
    {
        std::swap(lhs.m_Functor, rhs.m_Functor);
    }
private:
    std::unique_ptr<Details::FunctionBase<R, Args...>> m_Functor;
};