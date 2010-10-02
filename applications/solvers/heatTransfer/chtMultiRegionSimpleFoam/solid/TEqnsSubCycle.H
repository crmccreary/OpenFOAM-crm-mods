if (nTSubCycles > 1)
{
    PtrList<volScalarField> TSum(solidRegions.size());
    dimensionedScalar totalDeltaT = runTime.deltaT();
 
    for
    (
        subCycle<volScalarField> TSubCycle(Ts, nTSubCycles);
        !(++TSubCycle).end();
    )
    {
#       include "solveSolid.H"
        TSum += (runTime.deltaT()/totalDeltaT)*T;
    }
 
    T = TSum;
}
else
{
#       include "solveSolid.H"
}

