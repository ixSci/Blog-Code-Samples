#pragma once

#include <string>

class CopyMover
{
public:
    void setByValuer(Accounter byValuer);
    void setByValuerAndNotMover(Accounter byValuerAndNotMover);
    void setByRefer(const Accounter& byRefer);
    void setRvaluer(Accounter&& rvaluer);
    const Accounter& byValuer() const noexcept;
    const Accounter& byValuerAndNotMover() const noexcept;
    const Accounter& byRefer() const noexcept;
    const Accounter& rvaluer() const noexcept;
    void print();
private:
    void _printData(const Accounter& accounter, const std::string& trail);
private:
    Accounter m_ByValuer;
    Accounter m_ByValuerAndNotMover;
    Accounter m_ByRefer;
    Accounter m_Rvaluer;
};