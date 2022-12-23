#ifndef ZV3D_CORE_COMMON_DEBUGUTILS_H
#define ZV3D_CORE_COMMON_DEBUGUTILS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: debugging tools declarations.
/*
	19-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/Common/Zv3DAssert.h"
//-----------------------------------------------------------------------------

#if (ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_HIGH)
	void ZvdAssertNotNull(void* p);
	void ZvdAssertNull(void* p);
#else
#	define ZvdAssertNotNull(p) ((void) 0)
#	define ZvdAssertNull(p) ((void) 0)
#endif


#endif // ZV3D_CORE_COMMON_DEBUGUTILS_H
