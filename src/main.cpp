#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "EnableIf.h"
#include "HasFunction.h"

using namespace std;

template<typename Container>
typename EnableIf<HasFunctionSort<Container>::value, void>::type
sort(Container& container)
{
    cout << "Calling member sort function\n";
    container.sort();
}

template<typename Container>
typename EnableIf<!HasFunctionSort<Container>::value, void>::type
sort(Container& container)
{
    cout << "Calling std::sort function\n";
    sort(container.begin(), container.end());
}

int main()
{
    vector<int> vector;
    list<int> list;
    sort(vector);
    sort(list);
}