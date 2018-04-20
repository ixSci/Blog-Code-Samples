#include <iostream>
#include "Accounter.h"
#include "CopyMover.h"
#include "Indirectors.h"

using std::cout;

void testLvalue()
{
    Accounter byRefer;
    Accounter byValuer;
    Accounter byValuerAndNotMover;
    CopyMover copyMover;

    copyMover.setByRefer(byRefer);
    copyMover.setByValuer(byValuer);
    copyMover.setByValuerAndNotMover(byValuerAndNotMover);

    copyMover.print();
}

void testLvalueIndirect()
{
    Accounter byRefer;
    Accounter byValuer;
    Accounter byValuerAndNotMover;
    CopyMover copyMover;

    setByRefer(byRefer, copyMover);
    setByValuer(byValuer, copyMover);
    setByValuerAndNotMover(byValuerAndNotMover, copyMover);

    copyMover.print();
}

void testRvalue()
{
    CopyMover copyMover;

    copyMover.setByRefer(Accounter{});
    copyMover.setByValuer(Accounter{});
    copyMover.setByValuerAndNotMover(Accounter{});
    copyMover.setRvaluer(Accounter{});

    copyMover.print();
}

void testRvalueIndirect()
{
    CopyMover copyMover;

    setByRefer(Accounter{}, copyMover);
    setByValuer(Accounter{}, copyMover);
    setByValuerAndNotMover(Accounter{}, copyMover);
    setRvaluer(Accounter{}, copyMover);

    copyMover.print();
}

int main()
{
    cout << "---- TEST LVALUE: \n\n";
    testLvalue();
    cout << "\n";
    cout << "---- TEST LVALUE INDIRECT: \n\n";
    testLvalueIndirect();
    cout << "\n";
    cout << "---- TEST RVALUE: \n\n";
    testRvalue();
    cout << "\n";
    cout << "---- TEST RVALUE INDIRECT: \n\n";
    testRvalueIndirect();
    cout << "\n";
}