// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: string utils implementation.
/*
	19-May-2024	grv creation.
*/


#include "Core/Common/Zv3DStringUtils.h"
#include <cstring>
#include <cwchar>

//-----------------------------------------------------------------------------

template <>
ZvdSize_t ZvdLength(const char* src)
{
	if (!src)
		return 0u;
	return std::strlen(src);
}

template <>
ZvdSize_t ZvdLength(const wchar_t* src)
{
	if (!src)
		return 0u;
	return std::wcslen(src);
}

//-----------------------------------------------------------------------------

template <>
char ZvdGetNullChar()
{
	return '\0';
}

template <>
wchar_t ZvdGetNullChar()
{
	return L'\0';
}