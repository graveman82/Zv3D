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
	typename TMemoryAllocator = std::allocator<T>
>
class ZvdPodDynamicArray_t
{
public:
	using size_type = ZvdSize_t;

	ZvdRetVal_t reserve(size_type nNewCap)
	{
		if (nNewCap <= m_nCapacity)
			return ZvdErrorInfo_t::Ok().RetVal();

		nNewCap = std::max(nNewCap, calculateCapacity(m_nCount));

		if (0 == m_nCapacity)
		{
			void* p{};
			ZvdErrorInfo_t errorInfo(TMemoryAllocator::allocate(sizeof(T) * nNewCap, &p));
			if (errorInfo.Status() != kZvdOk)
			{
				return errorInfo.RetVal();
			}

			m_pElements = reinterpret_cast<T*>(p);
			m_nCapacity = nNewCap;
			return ZvdErrorInfo_t::Ok().RetVal();
		}
		
		// capacity() > 0
		void* p{};
		ZvdErrorInfo_t errorInfo(TMemoryAllocator::reallocate(m_pElements, sizeof(T) * nNewCap, &p));
		if (errorInfo.Status() != kZvdOk)
		{
			return errorInfo.RetVal();
		}

		m_pElements = reinterpret_cast<T*>(p);
		m_nCapacity = nNewCap;
		return ZvdErrorInfo_t::Ok().RetVal();
	}
private:
	size_type calculateCapacity(size_type nCount)
	{
		size_type nCap = 8;
		while (nCap < nCount)
		{
			nCap += (nCap >> 1);
		}
		
		return nCap;
	}

	T* m_pElements{};
	size_type m_nCount{};
	size_type m_nCapacity{};
};
#endif // ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H