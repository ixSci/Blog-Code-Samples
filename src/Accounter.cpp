#include "Accounter.h"

Accounter::Accounter(const Accounter& other)
{
    m_Copies = other.copies() + 1;
    m_Moves = other.moves();
}

Accounter::Accounter(Accounter&& other)
{
    m_Moves = other.moves() + 1;
    m_Copies = other.copies();
}

Accounter& Accounter::operator=(const Accounter& other)
{
    m_Copies = other.copies() + 1;
    m_Moves = other.moves();
    return *this;
}

Accounter& Accounter::operator=(Accounter&& other)
{
    m_Moves = other.moves() + 1;
    m_Copies = other.copies();
    return *this;
}

size_t Accounter::copies() const noexcept
{
    return m_Copies;
}

size_t Accounter::moves() const noexcept
{
    return m_Moves;
}
