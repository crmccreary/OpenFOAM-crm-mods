    const dictionary& SolidRegionSubCycleControl = mesh.solutionDict().subDict("SolidRegionSubCycleControl");

    int nTSubCycles =
        SolidRegionSubCycleControl.lookupOrDefault<int>("nTSubCycles", 0);
