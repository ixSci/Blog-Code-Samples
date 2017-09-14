#include <vector>
#include <list>
#include <string>
#include "MixStaticWithDynamic.h"
#include "Sort.h"
#include "ReturnHeadache.h"
#include "StaticIf.h"

using namespace std::string_literals;
using namespace std;

void mixStaticWithDynamicExample();
void sortExample();
void returnTypesExample();
void staticIfExample();

int main(int argc, char* argv[])
{
    mixStaticWithDynamicExample();
    sortExample();
    returnTypesExample();
    staticIfExample();
    return 0;
}

void mixStaticWithDynamicExample()
{
    mixStaticWithDynamicCorrect(1);
    mixStaticWithDynamicCorrect("clone"s);
    mixStaticWithDynamicCorrect("unique"s);
    mixStaticWithDynamicCorrect(1.0);
}

void sortExample()
{
    vector<int> vector;
    list<int> list;
    sort(vector);
    sort(list);
}

void returnTypesExample()
{
    static_assert(std::is_same_v<decltype(returnHeadache("string"s)), int>);
    static_assert(std::is_same_v<decltype(returnHeadache(1)), std::string>);
}

void staticIfExample()
{
    StaticIf<int>::branch("stinger");
    // Раскомментируйте, чтобы получить ошибку
    //StaticIf<float>::branch("stinger");
    StaticIf<float>::branch(282);
}


