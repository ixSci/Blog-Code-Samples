#include <utility>
#include "Indirectors.h"

void setByValuer(Accounter byValuer, CopyMover& copyMover)
{
    copyMover.setByValuer(std::move(byValuer));
}

void setByValuerAndNotMover(Accounter byValuerAndNotMover, CopyMover& copyMover)
{
    copyMover.setByValuerAndNotMover(byValuerAndNotMover);
}

void setByRefer(const Accounter& byRefer, CopyMover& copyMover)
{
    copyMover.setByRefer(byRefer);
}

void setRvaluer(Accounter&& rvaluer, CopyMover& copyMover)
{
    copyMover.setRvaluer(std::move(rvaluer));
}
