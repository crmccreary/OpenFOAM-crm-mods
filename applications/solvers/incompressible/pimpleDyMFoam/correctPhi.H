{
    if (mesh.changing())
    {
        forAll(U.boundaryField(), patchi)
        {
            if (U.boundaryField()[patchi].fixesValue())
            {
                U.boundaryField()[patchi].initEvaluate();
            }
        }

        forAll(U.boundaryField(), patchi)
        {
            if (U.boundaryField()[patchi].fixesValue())
            {
                U.boundaryField()[patchi].evaluate();

                phi.boundaryField()[patchi] =
                U.boundaryField()[patchi] & mesh.Sf().boundaryField()[patchi];
            }
        }
    }

    wordList pcorrTypes
    (
        p.boundaryField().size(),
        zeroGradientFvPatchScalarField::typeName
    );

    for (label i=0; i<p.boundaryField().size(); i++)
    {
        if(p.boundaryField()[i].fixesValue())
        {
            pcorrTypes[i] = fixedValueFvPatchScalarField::typeName;
        }
    }

    volScalarField pcorr
    (
        IOobject
        (
            "pcorr",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedScalar("pcorr", p.dimensions(), 0.0),
        pcorrTypes
    );

    for(int nonOrth=0; nonOrth<=nNonOrthCorr; nonOrth++)
    {
        fvScalarMatrix pcorrEqn
        (
            fvm::laplacian(rAU, pcorr) == fvc::div(phi)
        );

        pcorrEqn.setReference(pRefCell, pRefValue);
        pcorrEqn.solve();

        if (nonOrth == nNonOrthCorr)
        {
            phi -= pcorrEqn.flux();
        }
    }
}

#include "continuityErrs.H"
