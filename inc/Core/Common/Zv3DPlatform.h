#ifndef ZV3D_CORE_COMMON_PLATFORM_H
#define ZV3D_CORE_COMMON_PLATFORM_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: platform specific macros ant definitions.
/*
	19-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DCompiler.h"

//-----------------------------------------------------------------------------
/* Windows OS detection if gnu C.
*/
#if defined ZVD_COMPILER_GNUC
#   if defined (_WIN32) && !defined (ZVD_OS_WINDOWS)
#       define ZVD_OS_WINDOWS
#       define ZVD_OS_WINDOWS32
#       if defined (_WIN64)
#           define ZVD_OS_WINDOWS64
#           if !defined (ZVD_OS_64)
#               define ZVD_OS_64
#           endif
#       endif
#   endif   // end of Windows OS detection in gnu C

#elif defined ZVD_COMPILER_MSVC
#   if defined (_WIN32) && !defined (ZVD_OS_WINDOWS)
#       define ZVD_OS_WINDOWS
#       define ZVD_OS_WINDOWS32
#       if defined (_WIN64)
#           define ZVD_OS_WINDOWS64
#           if !defined (ZVD_OS_64)
#               define ZVD_OS_64
#           endif
#       endif
#   endif   // end of Windows OS detection in MSVC

#endif      // if gnu C

#endif // ZV3D_CORE_COMMON_PLATFORM_H