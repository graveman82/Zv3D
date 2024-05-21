// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: assert impl.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DAssert.h"

#ifndef ZVD_USE_TEMPLATE_ARGS_FOR_PRINT
#   include <cstdarg>
#else
#   error "Feature is not implemented yet"
#endif

#include "Core/Common/Zv3DAssert.h"

#ifdef ZVD_USE_MSGBOX_FOR_ASSERT
#   ifndef ZVD_OS_WINDOWS
#       error "message box for assert messaging is unsupported on nowindows platforms"
#   endif
#   include <windows.h>
#endif // ZVD_USE_MSGBOX_FOR_ASSERT

#include <string>
#include <new>

namespace zvd
{

    namespace debug
    {

        AssertPoint_t* AssertPointCtor_t::operator()(void* p)
        {
            return ::new(p) AssertPoint_t();
        }

        typedef std::basic_string<AssertPoint_t::CharType> CStdString;

        //-----------------------------------------------------------------------------
        // Implementation of output assert message function.
#ifndef ZVD_USE_TEMPLATE_ARGS_FOR_PRINT
        void OutputAssertMessage(AssertPoint_t::CStringType fmt, ...)
        {

            if (!AssertPoint_t::Instance().Exp())
            {
                return;
            }

            CStdString strMsg = ZVD_ASSERT_TEXT("[ASSERT]: \"");
            strMsg += AssertPoint_t::Instance().Exp();
            strMsg += ZVD_ASSERT_TEXT("\" failed in \"");
            strMsg += AssertPoint_t::Instance().FileAndLine();
            strMsg += ZVD_ASSERT_TEXT(".\"\n");
            AssertPoint_t::Instance().Clear();

            if (fmt)
            {
                va_list args;
                va_start(args, fmt);

                // evaluating buffer size for "details"
                va_list args2;
                va_copy(args2, args);
#ifdef ZVD_DEBUG_CHARTYPE_WIDE
                int nBufSize = _vscwprintf(fmt, args2) + 1;
#else
                int nBufSize = _vscprintf(fmt, args2) + 1;
#endif
                va_end(args2);

                const int kStaticBufSize = 256;
                AssertPoint_t::CharType static_buf[kStaticBufSize] = {};
                AssertPoint_t::CharType* p = static_buf;
                bool fStaticBuf = true;
                if (nBufSize > kStaticBufSize)
                {
                    p = new AssertPoint_t::CharType[nBufSize];
                    fStaticBuf = false;
                }
#ifdef ZVD_DEBUG_CHARTYPE_WIDE
#   ifdef ZVD_COMPILER_MSVC
                nBufSize = _vsnwprintf_s(p, nBufSize, _TRUNCATE, fmt, args);
#   else
                nBufSize = _vsnwprintf(p, nBufSize, fmt, args);
#   endif

#else
                nBufSize = _vsnprintf(p, nBufSize, fmt, args);
#endif
                va_end(args);

                if (nBufSize == -1)
                {
                    if (!fStaticBuf)
                        delete[] p;
                    return;
                }

                strMsg += ZVD_ASSERT_TEXT("Details: ");
                strMsg += p;
                strMsg += ZVD_ASSERT_TEXT("\n");
                if (!fStaticBuf)
                    delete[] p;
            }

#ifdef ZVD_USE_MSGBOX_FOR_ASSERT
#   ifdef ZVD_DEBUG_CHARTYPE_WIDE
            ::MessageBoxW(0, strMsg.c_str(), ZVD_ASSERT_TEXT("Assert failed!"), MB_ICONERROR | MB_OK | MB_TOPMOST);
#   else
            ::MessageBoxA(0, strMsg.c_str(), ZVD_ASSERT_TEXT("Assert failed!"), MB_ICONERROR | MB_OK | MB_TOPMOST);
#   endif
#else
#   ifdef ZVD_DEBUG_CHARTYPE_WIDE
            wprintf(strMsg.c_str());
#   else
            printf(strMsg.c_str());
#   endif
#endif // ZVD_USE_MSGBOX_FOR_ASSERT

        }
#endif // ZVD_USE_TEMPLATE_ARGS_FOR_PRINT

    } // end of debug
} // end of zvd
