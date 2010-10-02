    fvMesh& mesh = solidRegions[i];
    const dictionary& SolidRegionSubCycleControl = mesh.solutionDict().subDict("SolidRegionSubCycleControl");

    int maxDeltaTForSolidRegion =
        SolidRegionSubCycleControl.lookupOrDefault<int>("nTSubCycles", 0);
