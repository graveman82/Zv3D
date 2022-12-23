#ifndef ZV3D_CORE_MEMORY_MEMGROWSTRATEGIES_H
#define ZV3D_CORE_MEMORY_MEMGROWSTRATEGIES_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: mem grow strategies.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/MathLib/Zv3DMathSmallUtils.h"

struct Zv3DDefaultMemoryGrowStrategyParameters_t
{
	enum { kInitValue = 16 };
};

template <typename TParam = Zv3DDefaultMemoryGrowStrategyParameters_t>
class Zv3DDefaultMemoryGrowStrategy_t
{
public:
	ZvdSize_t NewCapacity(ZvdSize_t nOldCapacity)
	{
		if (nOldCapacity < 4)
		{
			return ZvdMax(ZvdSize_t(TParam::kInitValue), ZvdSize_t(4));
		}

		ZvdSize_t nNewCapacity = nOldCapacity + (nOldCapacity >> 1);
		if (nNewCapacity < TParam::kInitValue)
		{
			nNewCapacity = TParam::kInitValue;
		}
		return nNewCapacity;
	}
};
#endif // ZV3D_CORE_MEMORY_MEMGROWSTRATEGIES_H