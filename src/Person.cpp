#include <algorithm>
#include <utility>
#include "Person.h"

using std::string;
using std::move;
using std::copy;

#define FORGED_IMPLEMENTATION 0

Person::Person(size_t memberNumber,
    size_t memberSize):
    m_Members{memberNumber, string(memberSize, 'N')}
{
}

Person::Person(const Person& rhs)
{
    m_Members.resize(rhs.m_Members.size());
    copy(rhs.m_Members.begin(), rhs.m_Members.end(), m_Members.begin());
}

Person::Person(Person&& rhs) noexcept
{
    m_Members.resize(rhs.m_Members.size());
    move(rhs.m_Members.begin(), rhs.m_Members.end(), m_Members.begin());
}

Person& Person::operator=(const Person& rhs)
{
#if FORGED_IMPLEMENTATION
    Person tmp{rhs};
    m_Members = move(tmp.m_Members);
#else
    if(m_Members.empty())
        m_Members.resize(rhs.m_Members.size());
    copy(rhs.m_Members.begin(), rhs.m_Members.end(), m_Members.begin());
#endif
    return *this;
}

Person& Person::operator=(Person&& rhs) noexcept
{
#if FORGED_IMPLEMENTATION
    Person tmp{move(rhs)};
    m_Members = move(tmp.m_Members);
#else
    if(m_Members.empty())
        m_Members.resize(rhs.m_Members.size());
    move(rhs.m_Members.begin(), rhs.m_Members.end(), m_Members.begin());
#endif
    return *this;
}
