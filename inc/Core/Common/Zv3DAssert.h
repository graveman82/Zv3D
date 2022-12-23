#ifndef ZV3D_CORE_COMMON_ASSERT_H
#define ZV3D_CORE_COMMON_ASSERT_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: assert decl.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/Common/Zv3DStaticSingleton.h"

//-----------------------------------------------------------------------------
// Debug level values
#define ZVD_DEBUG_LEVEL_NONE         0   ///< Debugging is off (for production builds).
#define ZVD_DEBUG_LEVEL_LOW          1   ///< Low cost debugging mode (for release builds).
#define ZVD_DEBUG_LEVEL_MEDIUM       2   ///< Developing mode when most of code is well tested.
#define ZVD_DEBUG_LEVEL_HIGH         3   ///< Developing mode for intensive bug catching.
#define ZVD_DEBUG_LEVEL_EXTRA        4   ///< To catch very serious bugs.
#define ZVD_DEBUG_LEVEL_PARANOIC     5   ///< Paranoidal bug catching mode.

// Default debug level setting.
#ifndef ZVD_DEBUG_LEVEL
/// Debug level - one of (NONE, LOW, MEDIUM, HIGH, EXTRA, PARANOIC with "ZVD_DEBUG_LEVEL_" prefix).
#   define ZVD_DEBUG_LEVEL ZVD_DEBUG_LEVEL_NONE
#endif

//-----------------------------------------------------------------------------
// Break point
#if ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_LOW
#   ifdef ZVD_COMPILER_MSVC
#       define ZVD_DEBUG_BP() do { __asm int 3 } while (0)

#   elif defined(ZVD_COMPILER_GCC)
#       define ZVD_DEBUG_BP() do {__asm__ ("int $3\n\t"); } while (0)

#   endif

#else
#   define ZVD_DEBUG_BP(skip) { do { ; } while (false); }

#endif // ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_LOW

//-----------------------------------------------------------------------------
// char type for assert messages
#ifdef ZVD_DEBUG_CHARTYPE_WIDE
#   define ZVD_ASSERT_CHARTYPE wchar_t
#else
#   define ZVD_ASSERT_CHARTYPE char
#endif

#define ZVD_ASSERT_TEXT(s) ZVD_DEBUG_STRINGIFY(s)
#define ZVD_DEBUG_TEXT(s) ZVD_DEBUG_STRINGIFY(s)
#define ZVD_DEBUG_EMPTY_TEXT ZVD_DEBUG_TEXT("")

namespace zvd
{
    namespace debug
    {

        // to exlude <new> I use this Pseudo constructor
        class AssertPoint_t;
        class AssertPointCtor_t
        {
        public:
            AssertPoint_t* operator()(void* p);
        };

        //-----------------------------------------------------------------------------
        // Auxiliary class to fix file and line where aseertion was failed (Don't use it directly!)
        class AssertPoint_t : public ZvdStaticSingleton_t<AssertPoint_t, sizeof(void*) * 4, AssertPointCtor_t>
        {
        public:
            typedef ZVD_ASSERT_CHARTYPE CharType;
            typedef const CharType* CStringType;

            friend class ZvdStaticSingleton_t<AssertPoint_t, sizeof(void*) * 4, AssertPointCtor_t>;
            friend class AssertPointCtor_t;

            void Set(CStringType exp, CStringType fileAndLine)
            {
                m_exp = exp;
                m_fileAndLine = fileAndLine;
            }

            void Clear() { Set(ZVD_ASSERT_TEXT(""), ZVD_ASSERT_TEXT("")); }

            CStringType Exp() const { return m_exp; }
            CStringType FileAndLine() const { return m_fileAndLine; }

        private:
            AssertPoint_t() : m_exp(ZVD_ASSERT_TEXT("")), m_fileAndLine(ZVD_ASSERT_TEXT("")) {}

            CStringType m_exp;
            CStringType m_fileAndLine;
        };

        //-----------------------------------------------------------------------------
        // Shows assert related info (Don't use it directly!).
        void OutputAssertMessage(AssertPoint_t::CStringType fmt, ...);

    } // end of debug
} // end of zvd

//-----------------------------------------------------------------------------
// Fixing assert failed point (Don't use it directly!)

#define ZVD_FIX_ASSERT_POINT(exp) { if (!(exp)) { zvd::debug::AssertPoint::Instance().Set(ZVD_DEBUG_STRINGIFY(exp), ZVD_FILE_AND_LINE); } }

//
#   define ZVD_ASSERT_IMPL_NOMSG(exp)               { if (!(exp)) { ZVD_FIX_ASSERT_POINT(exp); zvd::debug::OutputAssertMessage(""                            ); ZVD_DEBUG_BP(); } }
#   define ZVD_ASSERT_IMPL(exp,fmt)                 { if (!(exp)) { ZVD_FIX_ASSERT_POINT(exp); zvd::debug::OutputAssertMessage(fmt                           ); ZVD_DEBUG_BP(); } }
#   define ZVD_ASSERT_IMPL1(exp,fmt,a1)             { if (!(exp)) { ZVD_FIX_ASSERT_POINT(exp); zvd::debug::OutputAssertMessage(fmt, (a1)                     ); ZVD_DEBUG_BP(); } }
#   define ZVD_ASSERT_IMPL2(exp,fmt,a1,a2)          { if (!(exp)) { ZVD_FIX_ASSERT_POINT(exp); zvd::debug::OutputAssertMessage(fmt, (a1), (a2)               ); ZVD_DEBUG_BP(); } }
#   define ZVD_ASSERT_IMPL3(exp,fmt,a1,a2,a3)       { if (!(exp)) { ZVD_FIX_ASSERT_POINT(exp); zvd::debug::OutputAssertMessage(fmt, (a1), (a2), (a3)         ); ZVD_DEBUG_BP(); } }
#   define ZVD_ASSERT_IMPL4(exp,fmt,a1,a2,a3,a4)    { if (!(exp)) { ZVD_FIX_ASSERT_POINT(exp); zvd::debug::OutputAssertMessage(fmt, (a1), (a2), (a3), (a4)   ); ZVD_DEBUG_BP(); } }

//*****************************************************************************
// Assert macros for different debugging levels [--


//-----------------------------------------------------------------------------
// Dubug level: LOW
#if ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_LOW // [LOW, PARANOIC]

#   define ZVD_ASSERT_LOW_NOMSG(exp)               ZVD_ASSERT_IMPL_NOMSG(exp)
#   define ZVD_ASSERT_LOW(exp,fmt)                 ZVD_ASSERT_IMPL(exp,fmt)
#   define ZVD_ASSERT_LOW1(exp,fmt,a1)             ZVD_ASSERT_IMPL1(exp,fmt,a1)
#   define ZVD_ASSERT_LOW2(exp,fmt,a1,a2)          ZVD_ASSERT_IMPL2(exp,fmt,a1,a2)
#   define ZVD_ASSERT_LOW3(exp,fmt,a1,a2,a3)       ZVD_ASSERT_IMPL3(exp,fmt,a1,a2,a3)
#   define ZVD_ASSERT_LOW4(exp,fmt,a1,a2,a3,a4)    ZVD_ASSERT_IMPL4(exp,fmt,a1,a2,a3,a4)

#else

#   define ZVD_ASSERT_LOW_NOMSG(exp)               ((void) 0)
#   define ZVD_ASSERT_LOW(exp,fmt)                 ((void) 0)
#   define ZVD_ASSERT_LOW1(exp,fmt,a1)             ((void) 0)
#   define ZVD_ASSERT_LOW2(exp,fmt,a1,a2)          ((void) 0)
#   define ZVD_ASSERT_LOW3(exp,fmt,a1,a2,a3)       ((void) 0)
#   define ZVD_ASSERT_LOW4(exp,fmt,a1,a2,a3,a4)    ((void) 0)

#endif // ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_LOW

//-----------------------------------------------------------------------------
// Dubug level: MEDIUM
#if ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_MEDIUM // [MEDIUM - PARANOIC]

#   define ZVD_ASSERT_MEDIUM_NOMSG(exp)               ZVD_ASSERT_IMPL_NOMSG(exp)
#   define ZVD_ASSERT_MEDIUM(exp,fmt)                 ZVD_ASSERT_IMPL(exp,fmt)
#   define ZVD_ASSERT_MEDIUM1(exp,fmt,a1)             ZVD_ASSERT_IMPL1(exp,fmt,a1)
#   define ZVD_ASSERT_MEDIUM2(exp,fmt,a1,a2)          ZVD_ASSERT_IMPL2(exp,fmt,a1,a2)
#   define ZVD_ASSERT_MEDIUM3(exp,fmt,a1,a2,a3)       ZVD_ASSERT_IMPL3(exp,fmt,a1,a2,a3)
#   define ZVD_ASSERT_MEDIUM4(exp,fmt,a1,a2,a3,a4)    ZVD_ASSERT_IMPL4(exp,fmt,a1,a2,a3,a4)

#else

#   define ZVD_ASSERT_MEDIUM_NOMSG(exp)               ((void) 0)
#   define ZVD_ASSERT_MEDIUM(exp,fmt)                 ((void) 0)
#   define ZVD_ASSERT_MEDIUM1(exp,fmt,a1)             ((void) 0)
#   define ZVD_ASSERT_MEDIUM2(exp,fmt,a1,a2)          ((void) 0)
#   define ZVD_ASSERT_MEDIUM3(exp,fmt,a1,a2,a3)       ((void) 0)
#   define ZVD_ASSERT_MEDIUM4(exp,fmt,a1,a2,a3,a4)    ((void) 0)

#endif // ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_MEDIUM

//-----------------------------------------------------------------------------
// Dubug level: HIGH
#if ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_HIGH // [HIGH - PARANOIC]

#   define ZVD_ASSERT_HIGH_NOMSG(exp)               ZVD_ASSERT_IMPL_NOMSG(exp)
#   define ZVD_ASSERT_HIGH(exp,fmt)                 ZVD_ASSERT_IMPL(exp,fmt)
#   define ZVD_ASSERT_HIGH1(exp,fmt,a1)             ZVD_ASSERT_IMPL1(exp,fmt,a1)
#   define ZVD_ASSERT_HIGH2(exp,fmt,a1,a2)          ZVD_ASSERT_IMPL2(exp,fmt,a1,a2)
#   define ZVD_ASSERT_HIGH3(exp,fmt,a1,a2,a3)       ZVD_ASSERT_IMPL3(exp,fmt,a1,a2,a3)
#   define ZVD_ASSERT_HIGH4(exp,fmt,a1,a2,a3,a4)    ZVD_ASSERT_IMPL4(exp,fmt,a1,a2,a3,a4)

#else

#   define ZVD_ASSERT_HIGH_NOMSG(exp)               ((void) 0)
#   define ZVD_ASSERT_HIGH(exp,fmt)                 ((void) 0)
#   define ZVD_ASSERT_HIGH1(exp,fmt,a1)             ((void) 0)
#   define ZVD_ASSERT_HIGH2(exp,fmt,a1,a2)          ((void) 0)
#   define ZVD_ASSERT_HIGH3(exp,fmt,a1,a2,a3)       ((void) 0)
#   define ZVD_ASSERT_HIGH4(exp,fmt,a1,a2,a3,a4)    ((void) 0)

#endif // ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_HIGH

//-----------------------------------------------------------------------------
// Dubug level: EXTRA
#if ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_EXTRA // [EXTRA - PARANOIC]

#   define ZVD_ASSERT_EXTRA_NOMSG(exp)               ZVD_ASSERT_IMPL_NOMSG(exp)
#   define ZVD_ASSERT_EXTRA(exp,fmt)                 ZVD_ASSERT_IMPL(exp,fmt)
#   define ZVD_ASSERT_EXTRA1(exp,fmt,a1)             ZVD_ASSERT_IMPL1(exp,fmt,a1)
#   define ZVD_ASSERT_EXTRA2(exp,fmt,a1,a2)          ZVD_ASSERT_IMPL2(exp,fmt,a1,a2)
#   define ZVD_ASSERT_EXTRA3(exp,fmt,a1,a2,a3)       ZVD_ASSERT_IMPL3(exp,fmt,a1,a2,a3)
#   define ZVD_ASSERT_EXTRA4(exp,fmt,a1,a2,a3,a4)    ZVD_ASSERT_IMPL4(exp,fmt,a1,a2,a3,a4)

#else

#   define ZVD_ASSERT_EXTRA_NOMSG(exp)               ((void) 0)
#   define ZVD_ASSERT_EXTRA(exp,fmt)                 ((void) 0)
#   define ZVD_ASSERT_EXTRA1(exp,fmt,a1)             ((void) 0)
#   define ZVD_ASSERT_EXTRA2(exp,fmt,a1,a2)          ((void) 0)
#   define ZVD_ASSERT_EXTRA3(exp,fmt,a1,a2,a3)       ((void) 0)
#   define ZVD_ASSERT_EXTRA4(exp,fmt,a1,a2,a3,a4)    ((void) 0)

#endif // ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_EXTRA

//-----------------------------------------------------------------------------
// Dubug level: PARANOIC
#if ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_PARANOIC // [PARANOIC]

#   define ZVD_ASSERT_PARANOIC_NOMSG(exp)               ZVD_ASSERT_IMPL_NOMSG(exp)
#   define ZVD_ASSERT_PARANOIC(exp,fmt)                 ZVD_ASSERT_IMPL(exp,fmt)
#   define ZVD_ASSERT_PARANOIC1(exp,fmt,a1)             ZVD_ASSERT_IMPL1(exp,fmt,a1)
#   define ZVD_ASSERT_PARANOIC2(exp,fmt,a1,a2)          ZVD_ASSERT_IMPL2(exp,fmt,a1,a2)
#   define ZVD_ASSERT_PARANOIC3(exp,fmt,a1,a2,a3)       ZVD_ASSERT_IMPL3(exp,fmt,a1,a2,a3)
#   define ZVD_ASSERT_PARANOIC4(exp,fmt,a1,a2,a3,a4)    ZVD_ASSERT_IMPL4(exp,fmt,a1,a2,a3,a4)

#else

#   define ZVD_ASSERT_PARANOIC_NOMSG(exp)               ((void) 0)
#   define ZVD_ASSERT_PARANOIC(exp,fmt)                 ((void) 0)
#   define ZVD_ASSERT_PARANOIC1(exp,fmt,a1)             ((void) 0)
#   define ZVD_ASSERT_PARANOIC2(exp,fmt,a1,a2)          ((void) 0)
#   define ZVD_ASSERT_PARANOIC3(exp,fmt,a1,a2,a3)       ((void) 0)
#   define ZVD_ASSERT_PARANOIC4(exp,fmt,a1,a2,a3,a4)    ((void) 0)

#endif // ZVD_DEBUG_LEVEL >= ZVD_DEBUG_LEVEL_PARANOIC

// -- ] Assert macros for different debugging levels

#endif //ZV3D_CORE_COMMON_ASSERT_H
