#ifndef ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H
#define ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: dynamic array for PODs.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/Common/Zv3DDebugUtils.h"
#include "Core/Common/Zv3DError.h"

#include <algorithm>
#include <stdexcept>

//-----------------------------------------------------------------------------
//


//-----------------------------------------------------------------------------
template<
	typename T,
	typename TAllocator = std::allocator<T>
>
class ZvdPodDynamicArray_t
{
public:
	using size_type = ZvdSize_t;
private:
	T* m_pElements{};
	size_type m_nCount{};
	size_type m_nCapacity{};
};
#endif // ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H