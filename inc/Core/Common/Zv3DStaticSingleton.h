#ifndef ZV3D_CORE_COMMON_STATICSINGLETON_H
#define ZV3D_CORE_COMMON_STATICSINGLETON_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: static singleton class.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"

//-----------------------------------------------------------------------------
/** @class StaticAllocatedSingleton
    An object instance is allocated in static buffer.
*/
template <typename T, ZvdSize_t kBufferSize, typename TPseudoCtor>
class ZvdStaticSingleton_t
{
public:
    ZvdStaticSingleton_t() = default;

    /// Returns reference to a single instance of given template type.
    static T& Instance()
    {
        if (!m_pInstance)
        {
            TPseudoCtor construct;
            m_pInstance = construct(&m_buffer[0]);
        }
        return *m_pInstance;
    }

    /// Destroys the instance explicitly.
    static void Destroy()
    {
        if (m_pInstance)
        {
            m_pInstance->~T();
            m_pInstance = nullptr;
        }
    }

private:

    // not allowed
    ZvdStaticSingleton_t(const ZvdStaticSingleton_t<T, kBufferSize, TPseudoCtor>&) = delete;
    ZvdStaticSingleton_t& operator=(const ZvdStaticSingleton_t<T, kBufferSize, TPseudoCtor>&) = delete;

    static T* m_pInstance;
    static ZvdByte_t m_buffer[kBufferSize];
};

//-----------------------------------------------------------------------------
template <typename T, ZvdSize_t kBufferSize, typename TPseudoCtor>
T* ZvdStaticSingleton_t<T, kBufferSize, TPseudoCtor>::m_pInstance = nullptr;

//-----------------------------------------------------------------------------
template <typename T, ZvdSize_t kBufferSize, typename TPseudoCtor>
ZvdByte_t ZvdStaticSingleton_t<T, kBufferSize, TPseudoCtor>::m_buffer[kBufferSize];
#endif // ZV3D_CORE_COMMON_STATICSINGLETON_H
