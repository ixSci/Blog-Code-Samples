#include <string>
#include <benchmark/benchmark.h>
#include "Storage.h"
#include "Printers.h"

using std::string;
using namespace std::string_literals;
using benchmark::State;

const Printers c_Printers = {[](const string&){}, [](int) {}, [](float) {}};

static void String_SetByConstRef(State& state) 
{
    const string str(static_cast<size_t>(state.range(0)), 'C');
    Storage storage;
    for(auto _ : state)
        storage.setSessionIdByRef(str);
}

static void String_SetByValue(State& state) 
{
    const string str(static_cast<size_t>(state.range(0)), 'C');
    Storage storage;
    for(auto _ : state)
        storage.setSessionIdByVal(str);
}

static void Person_AddByConstRef(State& state)
{
    const Person person{15, static_cast<size_t>(state.range(0))};
    Storage storage;
    for(auto _ : state)
        storage.addPersonByRef(person);
}

static void Person_AddByValue(State& state)
{
    const Person person{15, static_cast<size_t>(state.range(0))};
    Storage storage;
    for(auto _ : state)
        storage.addPersonByVal(person);
}

static void Person_SetByConstRef(State& state)
{
    const Person person{10, static_cast<size_t>(state.range(0))};
    Storage storage;
    for(auto _ : state)
        storage.setPersonByRef(person);
}

static void Person_SetByValue(State& state)
{
    const Person person{10, static_cast<size_t>(state.range(0))};
    Storage storage;
    for(auto _ : state)
        storage.setPersonByVal(person);
}

static void Printers_SetByConstRef(State& state)
{
    Storage storage;
    for(auto _ : state)
        storage.setPrintersByRef(c_Printers);
}

static void Printers_SetByValue(State& state)
{
    Storage storage;
    for(auto _ : state)
        storage.setPrintersByVal(c_Printers);
}

static void Blob_SetByConstRef(State& state)
{
    const Blob blob{};
    Storage storage;
    for(auto _ : state)
        storage.setBlobByRef(blob);
}

static void Blob_SetByValue(State& state)
{
    const Blob blob{};
    Storage storage;
    for(auto _ : state)
        storage.setBlobByVal(blob);
}

BENCHMARK(String_SetByValue)->Range(15, 1024);
BENCHMARK(String_SetByConstRef)->Range(15, 1024);
BENCHMARK(Person_AddByValue)->Range(15, 1024);
BENCHMARK(Person_AddByConstRef)->Range(15, 1024);
BENCHMARK(Person_SetByValue)->Range(15, 1024);
BENCHMARK(Person_SetByConstRef)->Range(15, 1024);
BENCHMARK(Printers_SetByValue);
BENCHMARK(Printers_SetByConstRef);
BENCHMARK(Blob_SetByValue);
BENCHMARK(Blob_SetByConstRef);

BENCHMARK_MAIN();