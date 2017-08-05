#include <iostream>
#include "DummyVector.h"
#include "Dummy.h"

int main()
{
    std::vector<int> vector{1, 2, 3, 4, 5};
    int value = 0;

    DummyVector copyInit = DummyVector<int>{};
    DummyVector initList{5.0, .3, .1, 5.67};
    DummyVector initFromVec(vector.begin(), vector.end());

    // Раскомментируйте, чтобы получить ошибку
    //Dummy dummy = {value, 1};
    Dummy dummy{value, 1};
}
