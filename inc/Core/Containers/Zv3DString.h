#ifndef ZV3D_CORE_CONTAINERS_STRING_H
#define ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: string class definition and implementation.
/*
	23-Dec-2018	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/Common/Zv3DDebugUtils.h"
#include "Core/Common/Zv3DError.h"

#include <algorithm>
#include <stdexcept>

#include "Core/Common/Zv3DStringUtils.h"
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
template<typename TChar>
class ZvdString_t
{
public:
	using size_type = zvd::Size_t;
	enum Config : size_type
	{
		kMinCap = 8;
	};
public:
	~ZvdString_t()
	{
		deallocate();
	}

	ZvdString_t()
	{
		reallocate(1);
		m_pData[0] = zvd::getNullChar<TChar>();
	}

	ZvdString_t(const TChar* src)
	{
		copyFrom(src);
	}

	ZvdString_t(const ZvdString_t<TChar>& src)
	{
		copyFrom(src);
	}

	ZvdString_t& operator=(const TChar* src)
	{
		copyFrom(src);
		return *this;
	}

	ZvdString_t& operator=(const ZvdString_t& src)
	{
		if (this != &src)
		{
			copyFrom(src);
		}
		
		return *this;
	}

	ZvdString_t& operator+=(const ZvdString_t& src)
	{
		return append(src);
	}

	ZvdString_t& append(const ZvdString_t& src)
	{
		size_type nLen = length();
		size_type nToAppend = src.length();
		size_type nNewCount = nLen + nToAppend + 1;
		if (nNewCount > m_nCapacity)
			reallocate(nNewCount);

		std::memcpy(m_pData + nLen, src.m_pData, sizeof(TChar) * nToAppend);
		m_pData[nLen + nToAppend] = zvd::getNullChar<TChar>();
		m_nCount += nToAppend;
		return *this;
	}


	void clear() noexcept
	{
		m_nCount = 0;
		if (m_pData)
			m_pData[0] = zvd::getNullChar<TChar>();
	}

	size_type length() const noexcept 
	{ 
		return m_pData ? m_nCount - 1 : 0u; 
	}
private:
	void copyFrom(const TChar* src)
	{
		size_type nNewCount = zvd::length(src) + 1;
		if (nNewCount > m_nCapacity)
			reallocate(nNewCount);

		std::memcpy(m_pData, src, sizeof(TChar) * nNewCount);

		m_nCount = nNewCount;
	}

	void copyFrom(const ZvdString_t& src)
	{
		size_type nNewCount = src.length() + 1;
		if (nNewCount > m_nCapacity)
			reallocate(nNewCount);

		std::memcpy(m_pData, src.m_pData, sizeof(TChar) * nNewCount);

		m_nCount = nNewCount;
	}

	void reallocate(size_type nNewCount)
	{
		if (!m_pData)
		{
			allocate(nNewCount);
		}
		else
		{
			reallocateNonEmpty(nNewCount);
		}
	}

	void reallocateNonEmpty(size_type nNewCount)
	{
		size_type nNewCapacity = m_nCapacity;
		if (0 == nNewCapacity)
			nNewCapacity = kMinCap;

		while (nNewCapacity < nNewCount)
		{
			nNewCapacity += nNewCapacity >> 1;
		}

		TChar* pNewData = new TChar[nNewCapacity];
		std::memcpy(pNewData, m_pData, sizeof(TChar) * m_nCount);
		delete[] m_pData;
		m_pData = pNewData;
		m_nCapacity = nNewCapacity;
	}

	void allocate(size_type nNewCount)
	{
		size_type nNewCapacity = kMinCap;

		while (nNewCapacity < nNewCount)
		{
			nNewCapacity += nNewCapacity >> 1;
		}

		m_pData = new TChar[nNewCapacity];
		m_nCapacity = nNewCapacity;
	}

	void deallocate()
	{
		delete[] m_pData;
		m_pData = nullptr;
		m_nCapacity = 0u;
		m_nCount = 0u;
	}

	TChar* m_pData{};
	size_type m_nCount{};
	size_type m_nCapacity{};
};
#endif // ZV3D_CORE_CONTAINERS_PODDYNAMICARRAY_H