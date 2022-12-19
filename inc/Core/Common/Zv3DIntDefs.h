#ifndef ZV3D_CORE_COMMON_INTDEFS_H
#define ZV3D_CORE_COMMON_INTDEFS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: integer types, relative constants and small routines definitions.
/*
	19-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DPlatform.h"

//-----------------------------------------------------------------------------
// Fixed size integers.
#if defined (ZVD_COMPILER_MSVC)
	typedef __int8					ZvdInt8_t;
	typedef __int16					ZvdInt16_t;
	typedef __int32					ZvdInt32_t;
#	ifdef ZVD_OS_64
		typedef __int64				ZvdInt64_t;
#	endif
	typedef unsigned __int8			ZvdUInt8_t;
	typedef unsigned __int16		ZvdUInt16_t;
	typedef unsigned __int32		ZvdUInt32_t;
#	ifdef ZVD_OS_64
		typedef unsigned __int64	ZvdUInt64_t;
#	endif

#elif defined ZVD_COMPILER_GNUC
#   include <stdint.h>

	typedef int8_t					ZvdInt8_t;
	typedef int16_t					ZvdInt16_t;
	typedef int32_t					ZvdInt32_t;
#	ifdef ZVD_OS_64
		typedef int64_t				ZvdInt64_t;
#	endif
	typedef uint8_t					ZvdUInt8_t;
	typedef uint16_t				ZvdUInt16_t;
	typedef uint32_t				ZvdUInt32_t;
#	ifdef ZVD_OS_64
		typedef uint64_t			ZvdUInt64_t;
#	endif

#endif // msvc

//-----------------------------------------------------------------------------
/* Compiler-independent definitions.
*/
/// 8-bit byte.
typedef ZvdUInt8_t ZvdByte_t;
/// 16-bit word.
typedef ZvdUInt16_t ZvdWord_t;
/// 32-bit index type.
typedef ZvdUInt32_t ZvdIdx_t;
/// 32-bit size type.
typedef ZvdUInt32_t ZvdSize_t;

const ZvdIdx_t kZVD_NO_INDEX = ZvdIdx_t(-1);

#endif // ZV3D_CORE_COMMON_INTDEFS_H