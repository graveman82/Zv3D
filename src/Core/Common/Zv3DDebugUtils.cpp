// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: debugging tools declarations.
/*
	19-Dec-2022	grv creation.
*/

#include "stdafx.h"
#include "Core/Common/Zv3DDebugUtils.h"

//-----------------------------------------------------------------------------

#if (ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_HIGH)
void ZvdAssertNotNull(void* p)
{
	ZVD_ASSERT_HIGH_NOMSG(p);
}

void ZvdAssertNull(void* p)
{
	ZVD_ASSERT_HIGH_NOMSG(nullptr == p);
}
#endif