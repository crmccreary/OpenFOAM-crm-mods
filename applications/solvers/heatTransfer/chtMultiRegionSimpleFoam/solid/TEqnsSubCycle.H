if (nTSubCycles > 1)
{
    for
    (
        subCycle<volScalarField> TSubCycle(T, nTSubCycles);
        !(++TSubCycle).end();
    )
    {
#       include "setRegionSolidFields.H"
#       include "solveSolid.H"
        runTime++;
    }
}
else
{
#       include "setRegionSolidFields.H"
#       include "solveSolid.H"
}

