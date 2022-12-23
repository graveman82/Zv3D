#ifndef ZV3D_CORE_COMMON_BYTEUTILS_H
#define ZV3D_CORE_COMMON_BYTEUTILS_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: byte modification utils.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"

#ifdef ZVD_BIG_ENDIAN
#	define ZVD_HIBYTE(x)   (*((ZvdByte_t*)&(x)))   		// low byte in word
#	define ZVD_HIWORD(x)   (*((ZvdUInt16_t*)&(x)))   	// low word in dword
#	define ZVD_HIDWORD(x)  (*((ZvdUInt32_t*)&(x)))  	// low dword in qword

#	define ZVD_LOBYTE(x)   (*((ZvdByte_t*)&(x)+1)) 		// high byte in word
#	define ZVD_LOWORD(x)   (*((ZvdUInt16_t*)&(x)+1)) 	// high word in dword
#	define ZVD_LODWORD(x)  (*((ZvdUInt32_t*)&(x)+1))	// high dword in qword
#else // LE
#	define ZVD_LOBYTE(x)   (*((ZvdByte_t*)&(x)))   		// low byte in word
#	define ZVD_LOWORD(x)   (*((ZvdUInt16_t*)&(x)))   	// low word in dword
#	define ZVD_LODWORD(x)  (*((ZvdUInt32_t*)&(x)))  	// low dword in qword

#	define ZVD_HIBYTE(x)   (*((ZvdByte_t*)&(x)+1)) 		// high byte in word
#	define ZVD_HIWORD(x)   (*((ZvdUInt16_t*)&(x)+1)) 	// high word in dword
#	define ZVD_HIDWORD(x)  (*((ZvdUInt32_t*)&(x)+1))	// high dword in qword

#	define ZVD_BYTEn(x, n)   (*((ZvdByte_t*)&(x)+n))
#	define ZVD_WORDn(x, n)   (*((ZvdUInt16_t*)&(x)+n))
#	define ZVD_BYTE0(x)   ZVD_BYTEn(x,  0)
#	define ZVD_BYTE1(x)   ZVD_BYTEn(x,  1)
#	define ZVD_BYTE2(x)   ZVD_BYTEn(x,  2)
#	define ZVD_BYTE3(x)   ZVD_BYTEn(x,  3)
#	define ZVD_BYTE4(x)   ZVD_BYTEn(x,  4)
#	define ZVD_BYTE5(x)   ZVD_BYTEn(x,  5)
#	define ZVD_BYTE6(x)   ZVD_BYTEn(x,  6)
#	define ZVD_BYTE7(x)   ZVD_BYTEn(x,  7)
#	define ZVD_BYTE8(x)   ZVD_BYTEn(x,  8)
#	define ZVD_BYTE9(x)   ZVD_BYTEn(x,  9)
#	define ZVD_BYTE10(x)  ZVD_BYTEn(x, 10)
#	define ZVD_BYTE11(x)  ZVD_BYTEn(x, 11)
#	define ZVD_BYTE12(x)  ZVD_BYTEn(x, 12)
#	define ZVD_BYTE13(x)  ZVD_BYTEn(x, 13)
#	define ZVD_BYTE14(x)  ZVD_BYTEn(x, 14)
#	define ZVD_BYTE15(x)  ZVD_BYTEn(x, 15)
#	define ZVD_WORD0(x)   ZVD_WORDn(x,  0)
#	define ZVD_WORD1(x)   ZVD_WORDn(x,  1)
#	define ZVD_WORD2(x)   ZVD_WORDn(x,  2)
#	define ZVD_WORD3(x)   ZVD_WORDn(x,  3)
#	define ZVD_WORD4(x)   ZVD_WORDn(x,  4)
#	define ZVD_WORD5(x)   ZVD_WORDn(x,  5)
#	define ZVD_WORD6(x)   ZVD_WORDn(x,  6)
#	define ZVD_WORD7(x)   ZVD_WORDn(x,  7)

// now signed macros (the same but with sign extension)
#	define ZVD_SLOBYTE(x)   (*((ZvdInt8_t*)&(x)))
#	define ZVD_SLOWORD(x)   (*((ZvdInt16_t*)&(x)))
#	define ZVD_SLODWORD(x)  (*((ZvdInt32_t*)&(x)))

#	define ZVD_SHIBYTE(x)   (*((ZvdInt8_t*)&(x)+1))
#	define ZVD_SHIWORD(x)   (*((ZvdInt16_t*)&(x)+1))
#	define ZVD_SHIDWORD(x)  (*((ZvdInt32_t*)&(x)+1))

#	define ZVD_SBYTEn(x, n)   (*((int8*)&(x)+n))
#	define ZVD_SWORDn(x, n)   (*((int16*)&(x)+n))
#	define ZVD_SBYTE0(x)   ZVD_SBYTEn(x,  0)
#	define ZVD_SBYTE1(x)   ZVD_SBYTEn(x,  1)
#	define ZVD_SBYTE2(x)   ZVD_SBYTEn(x,  2)
#	define ZVD_SBYTE3(x)   ZVD_SBYTEn(x,  3)
#	define ZVD_SBYTE4(x)   ZVD_SBYTEn(x,  4)
#	define ZVD_SBYTE5(x)   ZVD_SBYTEn(x,  5)
#	define ZVD_SBYTE6(x)   ZVD_SBYTEn(x,  6)
#	define ZVD_SBYTE7(x)   ZVD_SBYTEn(x,  7)
#	define ZVD_SBYTE8(x)   ZVD_SBYTEn(x,  8)
#	define ZVD_SBYTE9(x)   ZVD_SBYTEn(x,  9)
#	define ZVD_SBYTE10(x)  ZVD_SBYTEn(x, 10)
#	define ZVD_SBYTE11(x)  ZVD_SBYTEn(x, 11)
#	define ZVD_SBYTE12(x)  ZVD_SBYTEn(x, 12)
#	define ZVD_SBYTE13(x)  ZVD_SBYTEn(x, 13)
#	define ZVD_SBYTE14(x)  ZVD_SBYTEn(x, 14)
#	define ZVD_SBYTE15(x)  ZVD_SBYTEn(x, 15)
#	define ZVD_SWORD0(x)   ZVD_SWORDn(x,  0)
#	define ZVD_SWORD1(x)   ZVD_SWORDn(x,  1)
#	define ZVD_SWORD2(x)   ZVD_SWORDn(x,  2)
#	define ZVD_SWORD3(x)   ZVD_SWORDn(x,  3)
#	define ZVD_SWORD4(x)   ZVD_SWORDn(x,  4)
#	define ZVD_SWORD5(x)   ZVD_SWORDn(x,  5)
#	define ZVD_SWORD6(x)   ZVD_SWORDn(x,  6)
#	define ZVD_SWORD7(x)   ZVD_SWORDn(x,  7)
#endif // BE/LE

#endif // ZV3D_CORE_COMMON_BYTEUTILS_H
