#pragma once

struct SimpleStruct
{
    std::string first {"first"};
    int second = 2;
    float third = 3.0;
};

struct ComplexStruct
{
    SimpleStruct simple;
    int answer = 24;
};