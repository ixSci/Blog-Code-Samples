#include <utility>
#include "Storage.h"

using std::string;
using std::move;

void Storage::setSessionIdByRef(const string& id)
{
    m_SessionId = id;
}

void Storage::setSessionIdByVal(string id)
{
    m_SessionId = move(id);
}

void Storage::addPersonByRef(const Person& person)
{
    m_Persons.emplace_back(person);
}

void Storage::addPersonByVal(Person person)
{
    m_Persons.emplace_back(move(person));
}

void Storage::setPersonByRef(const Person& person)
{
    m_ThePerson = person;
}

void Storage::setPersonByVal(Person person)
{
    m_ThePerson = move(person);
}

void Storage::setPrintersByRef(const Printers& printers)
{
    m_Printers = printers;
}

void Storage::setPrintersByVal(Printers printers)
{
    m_Printers = move(printers);
}

void Storage::setBlobByRef(const Blob& blob)
{
    m_Blob = blob;
}

void Storage::setBlobByVal(Blob blob)
{
    m_Blob = move(blob);
}
