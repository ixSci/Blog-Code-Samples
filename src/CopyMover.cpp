#include <utility>
#include <string>
#include <iostream>
#include "Accounter.h"
#include "CopyMover.h"

using std::cout;

void CopyMover::setByValuer(Accounter byValuer)
{
    m_ByValuer = std::move(byValuer);
}

void CopyMover::setByValuerAndNotMover(Accounter byValuerAndNotMover)
{
    m_ByValuerAndNotMover = byValuerAndNotMover;
}

void CopyMover::setByRefer(const Accounter& byRefer)
{
    m_ByRefer = byRefer;
}

void CopyMover::setRvaluer(Accounter&& rvaluer)
{
    m_Rvaluer = std::move(rvaluer);
}

const Accounter& CopyMover::byValuer() const noexcept
{
    return m_ByValuer;
}

const Accounter& CopyMover::byValuerAndNotMover() const noexcept
{
    return m_ByValuerAndNotMover;
}

const Accounter& CopyMover::byRefer() const noexcept
{
    return m_ByRefer;
}

const Accounter& CopyMover::rvaluer() const noexcept
{
    return m_Rvaluer;
}

void CopyMover::print()
{
    _printData(m_ByRefer, "const reference");
    _printData(m_ByValuer, "value");
    _printData(m_ByValuerAndNotMover, "value w/o move");
    _printData(m_Rvaluer, "rvalue reference");
}

void CopyMover::_printData(const Accounter& accounter, const std::string& trail)
{
    cout << "==== Object accepted by " << trail << " ====\n";
    cout << "Moves: " << accounter.moves() << ", ";
    cout << "Copies: " << accounter.copies() << "\n";
    cout << "\n";
}
