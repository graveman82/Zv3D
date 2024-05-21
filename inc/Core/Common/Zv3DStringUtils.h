#ifndef ZV3D_CORE_COMMON_STRINGUTILS_H
#define ZV3D_CORE_COMMON_STRINGUTILS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: string utils declarations.
/*
	19-May-2024	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"

//-----------------------------------------------------------------------------
// Template versions of standard lib utils.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/* Returns length of the null-terminated string.
*/
template <typename TChar>
ZvdSize_t ZvdLength(const TChar* src);

template <>
ZvdSize_t ZvdLength(const char* src);

template <>
ZvdSize_t ZvdLength(const wchar_t* src);


//-----------------------------------------------------------------------------
template <typename TChar>
TChar ZvdGetNullChar();

template <>
char ZvdGetNullChar();

template <>
wchar_t ZvdGetNullChar();

namespace zvd
{
	template <typename TChar>
	size_t length(const TChar* src)
	{
		return ZvdLength(src);
	}

	template <typename TChar>
	TChar getNullChar()
	{
		return ZvdGetNullChar<TChar>();
	}
} // end of zvd
#endif // ZV3D_CORE_COMMON_STRINGUTILS_H