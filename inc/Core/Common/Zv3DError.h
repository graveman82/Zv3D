#ifndef ZV3D_CORE_COMMON_ERROR_H
#define ZV3D_CORE_COMMON_ERROR_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: error handling utils (decl).
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"

//-----------------------------------------------------------------------------
//
// Use it to return from functions.
typedef ZvdUInt32_t ZvdRetVal_t;

//-----------------------------------------------------------------------------
enum ZvdResultStatus_t : ZvdByte_t
{
	kZvdUnk = 255,			///< nothing known about some error case
	kZvdNone = 0,			///< no error, but nothing had happened
	kZvdOk = 1,				///< success
	kZvdFail = 2,			///< operation failed (seriouos case, app can be crashed)
	kZvdWarn,				///< success, but there are some warnings
	kZvdErr,				///< error case that can be solved
	kZvdCancel,				///< operation canceled
	kZvdResultStatusCount = 7
};

const ZvdChar_t* ZvdToString(ZvdResultStatus_t status);

bool ZvdIsOk(ZvdResultStatus_t status);
//-----------------------------------------------------------------------------
enum class ZvdErrorCategory_t : ZvdByte_t
{
	kCore,
	kLangLib,
	kEngine,
	kSystem,
	kMemMng,
	kGfxDev,
	kCount
};

const ZvdChar_t* ZvdToString(ZvdErrorCategory_t cat);

//-----------------------------------------------------------------------------
class ZvdErrorList_t
{
public:
	enum Code : ZvdUInt16_t
	{
		kSuccess,
		kInvalidArg,
		kNoMemory,
		kOutOfRange,
		kCount
	};

	static const ZvdChar_t* GetText(Code code);

};

//-----------------------------------------------------------------------------
class ZvdErrorInfo_t
{
public:
	ZvdErrorInfo_t(ZvdRetVal_t retVal) : m_retVal{ retVal } {}
	ZvdErrorInfo_t(ZvdResultStatus_t status, ZvdErrorCategory_t cat, ZvdErrorList_t::Code code) { Format(status, cat, code); }

	ZvdRetVal_t RetVal() const { return m_retVal; }
	ZvdResultStatus_t Status() const;
	ZvdErrorCategory_t Category() const;
	ZvdErrorList_t::Code Code() const;
private:
	void Format(ZvdResultStatus_t status, ZvdErrorCategory_t cat, ZvdErrorList_t::Code code);
	ZvdRetVal_t m_retVal;
};
#endif // ZV3D_CORE_COMMON_ERROR_H