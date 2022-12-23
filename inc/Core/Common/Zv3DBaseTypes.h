#ifndef ZV3D_CORE_COMMON_BASETYPES_H
#define ZV3D_CORE_COMMON_BASETYPES_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: base types, relative constants and small routines definitions.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DIntDefs.h"
#include "Core/Common/Zv3DStringify.h"

//-----------------------------------------------------------------------------
// Null Pointer for legacy externals

#define kZVD_NULL 0

// define ZVD_T() and related macros
/*
   ZVD_T ("dm text") macro turns a literal string constant into a wide char
   or narrow char constant.
 */
#ifndef ZVD_T
#   ifdef ZVD_CHARTYPE_WIDE
#       define ZVD_T(x) ZVD_WIDECHAR(x)

#   else // ASCII
#       define ZVD_T(x) ZVD_NARROWCHAR(x)

#   endif // ASCII/Unicode

#endif // !defined(ZVD_T)

 /* ------------------------------------------------------------------------- */
 /* define ZvdChar type                                                       */
 /* ------------------------------------------------------------------------- */

#ifdef ZVD_CHARTYPE_WIDE
typedef wchar_t ZvdChar_t;
#else
typedef char ZvdChar_t;
#endif // ASCII/Unicode

#endif //ZV3D_CORE_COMMON_BASETYPES_H
