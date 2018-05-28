#pragma once

#include <string>
#include <vector>
#include "Person.h"
#include "Printers.h"
#include "Blob.h"

class Storage
{
public:
    void setSessionIdByRef(const std::string& id);
    void setSessionIdByVal(std::string id);
    void addPersonByRef(const Person& person);
    void addPersonByVal(Person person);
    void setPersonByRef(const Person& person);
    void setPersonByVal(Person person);
    void setPrintersByRef(const Printers& printers);
    void setPrintersByVal(Printers printers);
    void setBlobByRef(const Blob& blob);
    void setBlobByVal(Blob blob);
private:
    std::string m_SessionId;
    std::vector<Person> m_Persons;
    Person m_ThePerson;
    Printers m_Printers;
    Blob m_Blob;
};
