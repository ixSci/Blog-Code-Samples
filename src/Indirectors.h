#pragma once

#include "Accounter.h"
#include "CopyMover.h"

void setByValuer(Accounter byValuer, CopyMover& copyMover);
void setByValuerAndNotMover(Accounter byValuerAndNotMover, CopyMover& copyMover);
void setByRefer(const Accounter& byRefer, CopyMover& copyMover);
void setRvaluer(Accounter&& rvaluer, CopyMover& copyMover);


