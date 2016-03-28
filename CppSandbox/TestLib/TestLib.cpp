// Test2.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TestLib.h"

// NB: Do not define Templates here, they must be defined in header
// as they are interpreted at runtime (that's the whole point...) and
// therefore must not be compiled here!

// This is the constructor of a class that has been exported.
// see Test2.h for the class definition
MathsUtils::MathsUtils()
{
    return;
}
