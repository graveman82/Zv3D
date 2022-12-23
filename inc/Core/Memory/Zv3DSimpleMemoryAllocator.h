#ifndef ZV3D_CORE_MEMORY_SIMPLEMEMORYALLOCATOR_H
#define ZV3D_CORE_MEMORY_SIMPLEMEMORYALLOCATOR_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: simple memory allocator class definition.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/Common/Zv3DError.h"

//-----------------------------------------------------------------------------
//
class Zv3DSimpleMemoryAllocator_t
{
public:
	ZvdRetVal_t Allocate(void** pRet, ZvdSize_t nBytes);
	ZvdRetVal_t Reallocate(void** pRet, void* pOld, ZvdSize_t nBytes);
	ZvdRetVal_t Free(void* p);
};
#endif // ZV3D_CORE_MEMORY_SIMPLEMEMORYALLOCATOR_H