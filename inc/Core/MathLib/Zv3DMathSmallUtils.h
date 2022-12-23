#ifndef ZV3D_CORE_MATH_SMALLUTILS_H
#define ZV3D_CORE_MATH_SMALLUTILS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: small math utils.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"


//=============================================================================
// Some simple math

//-----------------------------------------------------------------------------
/// Returns the lesser of the two values.
template <typename T>
inline T ZvdMin(T a, T b)
{
    return a < b ? a : b;
}

//-----------------------------------------------------------------------------
/// Returns the greater of the two values.
template <typename T>
inline T ZvdMax(T a, T b)
{
    return a > b ? a : b;
}

//-----------------------------------------------------------------------------
/// Returns the absolute value of the value.
template <typename T>
inline T ZvdAbs(T a)
{
    return a >= 0 ? a : -a;
}

//-----------------------------------------------------------------------------
/// Swap two values.
template <typename T>
inline void ZvdSwap(T& a, T& b)
{
    T tmp(a);
    a = b;
    b = tmp;
}
#endif // ZV3D_CORE_MATH_SMALLUTILS_H
