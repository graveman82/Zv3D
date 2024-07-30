#ifndef ZV3D_ENGINE_ENGINE_H
#define ZV3D_ENGINE_ENGINE_H

// Zv3D Engine. (C) 2012-2024 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: base types, relative constants and small routines definitions.
/*
	25-Jan-2013	grv creation.
*/

#include "Core/Common/Zv3DError.h"


//-----------------------------------------------------------------------------
// 
class ZvdEngine_t
{
public:
	ZvdRetVal_t initialize();
	ZvdRetVal_t terminate();
	ZvdRetVal_t mainLoop();

private:
};

#endif // ZV3D_ENGINE_ENGINE_H
