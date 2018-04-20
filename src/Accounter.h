#pragma once

#include <cstddef>

class Accounter
{
public:
    Accounter() = default;
    Accounter(const Accounter&);
    Accounter(Accounter&&);
    Accounter& operator=(const Accounter&);
    Accounter& operator=(Accounter&&);
    size_t copies() const noexcept;
    size_t moves() const noexcept;
private:
    size_t m_Copies{0};
    size_t m_Moves{0};
};