#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <type_traits>
#include "HasSortFunction.h"

using namespace std;

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