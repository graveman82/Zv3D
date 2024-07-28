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
#	define ZVD_COMPILER_MSVC
#	define ZVD_COMPILER_MSVC_VERSION _MSC_VER
#	define ZVD_COMPILER_MSVC2019 1921
#	if (ZVD_COMPILER_MSVC_VERSION < ZVD_COMPILER_MSVC2019)
#		error "you need VC 2019 (16.1) or higher"
#	endif


#else // error
#   if !(defined(ZVD_COMPILER_GNUC) || \
         defined(ZVD_COMPILER_MSVC))
#       error "unsupported compiler"
#   endif
#endif // end of compiler detection


//-----------------------------------------------------------------------------
// C++ standard detection

// In Visual Studio add:
// /Zc:__cplusplus
// in project command line additional parameters field
// https://learn.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=msvc-170
#if (__cplusplus==202302L)
#   define ZVD_CPP __cplusplus
#   define ZVD_CPP23 __cplusplus
#   define ZVD_CPP20 202002L
#   define ZVD_CPP17 201703L
#   define ZVD_CPP14 201402L
#   define ZVD_CPP11 201103L
#   define ZVD_CPP03 199711L

#elif(__cplusplus == 202002L)
#   define ZVD_CPP __cplusplus
#   define ZVD_CPP20 __cplusplus
#   define ZVD_CPP17 201703L
#   define ZVD_CPP14 201402L
#   define ZVD_CPP11 201103L
#   define ZVD_CPP03 199711L

#elif(__cplusplus == 201703L)
#   define ZVD_CPP __cplusplus
#   define ZVD_CPP17 __cplusplus
#   define ZVD_CPP14 201402L
#   define ZVD_CPP11 201103L
#   define ZVD_CPP03 199711L

#elif(__cplusplus == 201402L)
#   define ZVD_CPP __cplusplus
#   define ZVD_CPP14 __cplusplus
#   define ZVD_CPP11 201103L
#   define ZVD_CPP03 199711L

#elif(__cplusplus == 201103L)
#   define ZVD_CPP11 __cplusplus
#   define ZVD_CPP03 199711L

#elif(__cplusplus == 199711L)
#   define ZVD_CPP __cplusplus
#   define ZVD_CPP03 __cplusplus

#endif // C++ standard detection end

#ifndef ZVD_CPP
#   error "No required C++ standard is supported by current compiler!"
#endif

#endif // ZV3D_CORE_COMMON_COMPILER_H