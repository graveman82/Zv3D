#ifndef ZV3D_CORE_COMMON_STRINGIFY_H
#define ZV3D_CORE_COMMON_STRINGIFY_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: stringification.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DPlatform.h"

//-----------------------------------------------------------------------------
/** Stringify tools.
Example of using:
    @code
    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>
    void WaitKeyAndQuit()
    {
        std::string q;
        std::cout << "Press any key followed Enter to quit..." << std::endl;
        std::cin >> q;
    }

    void Test01();
    int main()
    {
        Test01();
        WaitKeyAndQuit();
        return 0;
    }

    #define ZVD_CHARTYPE_WIDE
    #define ZVD_DEBUG_CHARTYPE_WIDE
    #include "base/dmStringify.h"

    #define DUMMY_YEAR 2022
    class Dummy
    {
        Dummy(const char* name) : m_name(name) {}
        std::string m_name;
    };
    void Test01()
    {
        std::vector<Dummy> dummies01;


        wprintf(L"%s\n", ZVD_STRINGIFY_SIMPLE(dummies01.push_back(Dummy("Pupkin"));));
        wprintf(L"%s\n", ZVD_STRINGIFY(dummies01.push_back(Dummy("Pupkin")); return DUMMY_YEAR));

        wprintf(L"%s\n", ZVD_FILE_AND_LINE);
        wprintf(L"%s\n", ZVD_DEBUG_STRINGIFY(dummies01.push_back(Dummy("Pupkin")); return DUMMY_YEAR));
    }
    @endcode
*/

//-- L concatenators ---------------------------------------------------------[
#define ZVD_WIDECHAR(expr)       ZVD_WIDECHAR_(expr)
#define ZVD_WIDECHAR_(expr)      L ## expr
#define ZVD_NARROWCHAR(expr)     expr
//----------------------------------------------------------------------------]

//-- Simple stringification for code without macros --------------------------[
#ifdef ZVD_CHARTYPE_WIDE
#   define ZVD_STRINGIFY_SIMPLE(expr) L ## #expr
#else
#   define ZVD_STRINGIFY_SIMPLE(expr) #expr
#endif
//----------------------------------------------------------------------------]

//-- Make a string literal from expression which can include macros ----------[
#define ZVD_STRINGIFY_INTERNAL(expr, LConcatenatorIfW)     ZVD_STRINGIFY_INTERNAL_(expr, LConcatenatorIfW)
#define ZVD_STRINGIFY_INTERNAL_(expr, LConcatenatorIfW) LConcatenatorIfW(#expr)

#ifdef ZVD_CHARTYPE_WIDE
#   define ZVD_STRINGIFY(expr)  ZVD_STRINGIFY_INTERNAL(expr,ZVD_WIDECHAR)
#else
#   define ZVD_STRINGIFY(expr)  ZVD_STRINGIFY_INTERNAL(expr,ZVD_NARROWCHAR)
#endif
//----------------------------------------------------------------------------]

//-- Debug stringify tools ---------------------------------------------------[
#define ZVD_FILE_AND_LINE_(LConcatenatorIfW)\
  LConcatenatorIfW(__FILE__) LConcatenatorIfW("[") ZVD_STRINGIFY_INTERNAL(__LINE__, LConcatenatorIfW) LConcatenatorIfW("]")

#ifdef ZVD_DEBUG_CHARTYPE_WIDE
#   define ZVD_FILE_AND_LINE       ZVD_FILE_AND_LINE_(ZVD_WIDECHAR)
#   define ZVD_DEBUG_STRINGIFY(expr)  ZVD_STRINGIFY_INTERNAL(expr,ZVD_WIDECHAR)
#else
#   define ZVD_FILE_AND_LINE       ZVD_FILE_AND_LINE_(ZVD_NARROWCHAR)
#   define ZVD_DEBUG_STRINGIFY(expr)  ZVD_STRINGIFY_INTERNAL(expr,ZVD_NARROWCHAR)
#endif
//----------------------------------------------------------------------------]
#endif // ZV3D_CORE_COMMON_STRINGIFY_H
