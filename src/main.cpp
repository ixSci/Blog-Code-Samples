#include <iostream>

using namespace std;

class Int
{
public:
    Int() = default;

    Int(int val):
            m_Value{val}
    {
    }

    Int operator++(int)
    {
        Int tmp{*this};
        ++m_Value;
        return tmp;
    }

    bool operator&&(const Int& rhs) const
    {
        return m_Value && rhs.m_Value;
    }
private:
    int m_Value = 0;
};

template <typename T>
bool cleverFun(T& value)
{
    return (cout << "first\n", value++) &&
           (cout << "second\n", value++);
}

int main()
{
    int i = -1;
    Int complexI{-1};
    cout << "==========SIMPLE INT============\n";
    cleverFun(i);
    cout << "==========COMPLEX INT============\n";
    cleverFun(complexI);
};