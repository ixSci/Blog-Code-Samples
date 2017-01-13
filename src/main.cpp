#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <type_traits>
#include <boost/tti/has_member_function.hpp>

using namespace std;

BOOST_TTI_HAS_MEMBER_FUNCTION(sort)
template<typename T>
constexpr bool HasFunctionSort_v = has_member_function_sort<T, void>::value;

template<typename Container>
enable_if_t <HasFunctionSort_v<Container>>
sort(Container& container)
{
    cout << "Calling member sort function\n";
    container.sort();
}

template<typename Container>
enable_if_t<!HasFunctionSort_v<Container>>
sort(Container& container)
{
    cout << "Calling std::sort function\n";
    sort(begin(container), end(container));
}

int main()
{
    vector<int> vector;
    list<int> list;
    sort(vector);
    sort(list);
}