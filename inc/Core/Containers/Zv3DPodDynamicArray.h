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
struct ZvdToConstructTag
{
	enum {kValue = 1};
};

struct ZvdToNotConstructTag
{
	enum { kValue = 0 };
};

//-----------------------------------------------------------------------------
template<typename T, typename TMemAllocator, typename TGrowStrategy, typename TToConstruct = ZvdToConstructTag>
class ZvdPodDynamicArray_t
{
	struct Header_t
	{
		ZvdSize_t nCount{};
		ZvdSize_t nCapacity{};
	};
public:

	typedef T* Iterator;
	typedef const T* ConstIterator;

	ZvdRetVal_t Append()
	{
		ZvdSize_t nOldCount;
		ZvdRetVal_t retVal = Grow(1, &nOldCount, false);

		ZvdErrorInfo_t errorInfo(retVal);
		if (errorInfo.Status() != kZvdOk)
		{
			return retVal;
		}

		return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
	}

	ZvdRetVal_t Append(const T& value)
	{
		ZvdSize_t nOldCount;
		ZvdRetVal_t retVal = Grow(1, &nOldCount, false);

		ZvdErrorInfo_t errorInfo(retVal);
		if (errorInfo.Status() != kZvdOk)
		{
			return retVal;
		}

		::new ((void*)(CastToByte(RawData()) + nOldCount * sizeof(T))) T(value);
		return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
	}

	ZvdRetVal_t Grow(ZvdSize_t nGrowBy, ZvdSize_t* pNOldCount, bool bToConstruct = true)
	{
		ZvdSize_t nOldCount = Count();
		if (pNOldCount) *pNOldCount = nOldCount;
		ZvdSize_t nNewCount = nOldCount + nGrowBy;
		if (nNewCount > Capacity())
		{
			ZvdRetVal_t retVal = Reserve(nNewCount);
			ZvdErrorInfo_t errorInfo(retVal);
			if (errorInfo.Status() != kZvdOk)
			{
				return retVal;
			}
		}
		
		Header()->nCount = nNewCount;

		if (TToConstruct::kValue && bToConstruct)
		{
			std::fill(Begin() + nOldCount, End(), T());
		}

		return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
	}

	T& At(ZvdIndex_t nIndex)
	{
		if (nIndex < 0 || nIndex >= Count())
			throw std::out_of_range;
		return *(Data() + nIndex);
	}

	const T& At(ZvdIndex_t nIndex) const
	{
		if (nIndex < 0 || nIndex >= Count())
			throw std::out_of_range;
		return *(Data() + nIndex);
	}

	ZvdSize_t Count() const
	{
		if (!m_pData)
		{
			return 0;
		}
		const Header_t* pHeader = Header();
		return pHeader->nCount;
	}

	ZvdSize_t Capacity() const
	{
		if (!m_pData)
		{
			return 0;
		}
		const Header_t* pHeader = Header();
		return pHeader->nCapacity;
	}

	T* Data()
	{
		if (!RawData())
		{
			return nullptr;
		}
		return reinterpret_cast<T*>(CastToByte(RawData()));
	}

	const T* Data() const
	{
		if (!RawData())
		{
			return nullptr;
		}
		return reinterpret_cast<T*>(CastToByte(RawData()));
	}

	Iterator Begin()
	{
		return Data();

	}

	ConstIterator Begin() const
	{
		return Data();
	}

	Iterator End()
	{
		return Data() + Count();
	}

	ConstIterator End() const
	{
		return Data() + Count();
	}

private:
	void* RawData() { return m_pData; }
	const void* RawData() const { return m_pData; }

	Header_t* Header()
	{
		ZvdAssertNotNull(m_pData);
		ZvdByte_t* pDataBytes = CastToByte(m_pData);
		pDataBytes -= sizeof(Header_t);
		return reinterpret_cast<Header_t*>(pDataBytes);
	}

	const Header_t* Header() const
	{
		ZvdAssertNotNull(m_pData);
		ZvdByte_t* pDataBytes = CastToByte(m_pData);
		pDataBytes -= sizeof(Header_t);
		return reinterpret_cast<Header_t*>(pDataBytes);
	}

	static ZvdByte_t* CastToByte(void* p)
	{
		return reinterpret_cast<ZvdByte_t*>(p);
	}

	static const ZvdByte_t* CastToByte(const void* p)
	{
		return reinterpret_cast<const ZvdByte_t*>(p);
	}

	bool IsAllocated() const
	{
		return m_pData != nullptr;
	}

	ZvdRetVal_t FreeMemory()
	{
		if (RawData())
		{
			TMemAllocator alcr;
			alcr.Free(Header());
			m_pData = nullptr;
		}
		return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
	}
	/// <summary>
	///  Reserve memory for array if it is not allocated yet.
	/// </summary>
	/// <param name="nCapacity"> required capacity </param>
	/// <returns></returns>
	ZvdRetVal_t ReserveIfNull(ZvdSize_t nCapacity)
	{
		ZvdAssertNull(m_pData);
		ZvdSize_t nRequiredBytes = sizeof(T) * nCapacity;
		nRequiredBytes += sizeof(Header_t);

		TMemAllocator alcr;
		void* pNewMem{};
		ZvdRetVal_t retVal = alcr.Allocate(&pNewMem, nRequiredBytes);
		ZvdErrorInfo_t errorInfo(retVal);
		auto status = errorInfo.Status();
		if (errorInfo.Status() != kZvdOk)
		{
			return retVal;
		}
		ZvdAssertNotNull(pNewMem);
		Header_t* pHeader = reinterpret_cast<Header_t*>(CastToByte(pNewMem));
		pHeader->nCapacity = nCapacity;
		pHeader->nCount = 0;
		m_pData = pHeader + 1;
		return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
	}

	ZvdSize_t CalculateCapacity(ZvdSize_t nRequiredCapacity)
	{
		TGrowStrategy strategy;
		ZvdSize_t nNewCapacity = strategy.NewCapacity(Capacity());
		while (nNewCapacity < nRequiredCapacity)
		{
			nNewCapacity = strategy.NewCapacity(nNewCapacity);
		}
		return nNewCapacity;
	}

	ZvdRetVal_t Reserve(ZvdSize_t nCapacity)
	{
		if (!IsAllocated())
		{
			ZvdSize_t nNewCapacity = CalculateCapacity(nCapacity);
			return ReserveIfNull(nNewCapacity);
		}

		// we have early allocated data
		nCapacity = CalculateCapacity(nCapacity);
		ZvdSize_t nRequiredBytes = sizeof(T) * nCapacity;
		nRequiredBytes += sizeof(Header_t);

		TMemAllocator alcr;
		void* pNewMem{};
		ZvdRetVal_t retVal = alcr.Reallocate(&pNewMem, Header(), nRequiredBytes);
		ZvdErrorInfo_t errorInfo(retVal);
		if (errorInfo.Status() != kZvdOk)
		{
			return retVal;
		}
		ZvdAssertNotNull(pNewMem);

		Header_t* pHeader = reinterpret_cast<Header_t*>(CastToByte(pNewMem));
		pHeader->nCapacity = nCapacity;
		m_pData = pHeader + 1;
		return ZvdErrorInfo_t(kZvdOk, ZvdErrorCategory_t::kCore, ZvdErrorList_t::kSuccess).RetVal();
	}

	void* m_pData{};
};
#endif // ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H