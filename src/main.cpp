#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <type_traits>
#include "HasEntity.h"

using namespace std;

GENERATE_HAS_FUNCTION(Sort, sort())

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