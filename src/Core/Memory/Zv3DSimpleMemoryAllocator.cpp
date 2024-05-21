// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: simple memory allocator class implementation.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Memory/Zv3DSimpleMemoryAllocator.h"
#include "Core/Common/Zv3DAssert.h"
#include <cstdlib>

//-----------------------------------------------------------------------------


ZvdRetVal_t Zv3DSimpleMemoryAllocator_t::Allocate(void** pRet, ZvdSize_t nBytes)
{
	void* p = std::malloc(nBytes);
	if (!p)
	{
		return ZvdErrorInfo_t(kZvdFatal, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kNoMemory).RetVal();
	}
	ZVD_ASSERT_HIGH_NOMSG(pRet);
	*pRet = p;
	return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
}

ZvdRetVal_t Zv3DSimpleMemoryAllocator_t::Reallocate(void** pRet, void* pOld, ZvdSize_t nBytes)
{
	ZVD_ASSERT_HIGH_NOMSG(pOld);
	void* p = std::realloc(pOld, nBytes);
	if (!p)
	{
		return ZvdErrorInfo_t(kZvdFatal, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kNoMemory).RetVal();
	}
	ZVD_ASSERT_HIGH_NOMSG(pRet);
	*pRet = p;
	return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
}

ZvdRetVal_t Zv3DSimpleMemoryAllocator_t::Free(void* p)
{
	ZVD_ASSERT_HIGH_NOMSG(p);
	std::free(p);
	return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
}