#ifndef ZV3D_CORE_COMMON_LANGLIB_H
#define ZV3D_CORE_COMMON_LANGLIB_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: lang supported library routines declarations.
/*
	20-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DIntDefs.h"

//-----------------------------------------------------------------------------
/* Desc "Lang" prefix follows used for either CRT or STD types or routines.
Its depends on macro ZVD_LANG_LIB.
*/

// mutually exclusive macro constants
#define ZVD_CRT_USED 1 // used crt routines
#define ZVD_STD_USED 2 // used std routines

// define ZVD_LANG_LIB for some compilers
#if defined ZVD_COMPILER_MSVC
#	if (ZVD_COMPILER_MSVC_VERSION == ZVD_COMPILER_MSVC_NET20037X1)
#		define ZVD_LANG_LIB ZVD_CRT_USED
#	endif

#endif // ZVD_COMPILER_MSVC

#ifndef ZVD_LANG_LIB
#	define ZVD_LANG_LIB ZVD_CRT_USED
#endif

//-----------------------------------------------------------------------------
// lang lib integers
#if (ZVD_LANG_LIB == ZVD_CRT_USED)
#	include "Core/Common/Zv3DCrtDefs.h"
#endif

#endif // ZV3D_CORE_COMMON_LANGLIB_H