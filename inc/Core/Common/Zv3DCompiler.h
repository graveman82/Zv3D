#ifndef ZV3D_CORE_COMMON_COMPILER_H
#define ZV3D_CORE_COMMON_COMPILER_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: compiler detection.
/*
	19-Dec-2022	grv creation.
*/

//-----------------------------------------------------------------------------
// Compiler detection.
#if defined (__GNUC__) && !defined (ZVD_COMPILER_GNUC)
#   define ZVD_COMPILER_GNUC
#   define ZVD_COMPILER_GNUC_VERSION (__GNUC__ * 10000 \
                                    + __GNUC_MINOR__ * 100 \
                                    + __GNUC_PATCHLEVEL__)
#	if ZVD_COMPILER_GNUC_VERSION < 80100
#		error "you need gcc 8.1 or higher"
#	endif

#elif defined (_MSC_VER)
#	if (_MSC_VER < 1310)
#		error "you need VC 2003.Net 7.1 or higher"
#	endif
#	define ZVD_COMPILER_MSVC
#	define ZVD_COMPILER_MSVC_VERSION _MSC_VER
#	define ZVD_COMPILER_MSVC_NET20037X1 1310

#else // error
#   if !(defined(ZVD_COMPILER_GNUC) || \
         defined(ZVD_COMPILER_MSVC))
#       error "unsupported compiler"
#   endif
#endif // end of compiler detection

#endif // ZV3D_CORE_COMMON_COMPILER_H