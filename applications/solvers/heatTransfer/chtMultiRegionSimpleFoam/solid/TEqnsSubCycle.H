#include "setRegionSolidFields.H"
if (nTSubCycles > 1)
{
    for
    (
        subCycle<volScalarField> TSubCycle(T, nTSubCycles);
        !(++TSubCycle).end();
    )
    {
#       include "solveSolid.H"
        runTime++;
    }
}
else
{
#       include "solveSolid.H"
}

