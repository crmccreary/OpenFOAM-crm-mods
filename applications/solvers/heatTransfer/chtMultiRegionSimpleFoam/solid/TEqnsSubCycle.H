if (nTSubCycles > 1)
{
    dimensionedScalar totalDeltaT = runTime.deltaT();
 
    for
    (
        subCycle<volScalarField> TSubCycle(T, nTSubCycles);
        !(++TSubCycle).end();
    )
    {
#       include "solveSolid.H"
    }
}
else
{
#       include "solveSolid.H"
}

