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
	kZvdUnk = 0,			///< nothing known about some error case
	kZvdNone,				///< no error, but nothing had happened
	kZvdOk,					///< success
	kZvdFatal,				///< operation failed (seriouos case, app can be crashed)
	kZvdWarn,				///< success, but there are some warnings
	kZvdError,				///< error case that can be solved
	kZvdCancel,				///< operation canceled
	kZvdResultStatusCount
};

const ZvdChar_t* ZvdToString(ZvdResultStatus_t status);

ZvdResultStatus_t ZvdErrorStatus(ZvdRetVal_t);

//-----------------------------------------------------------------------------
class ZvdErrorEval_t
{
public:
	ZvdErrorEval_t(ZvdRetVal_t retVal);
	ZvdErrorEval_t& operator=(ZvdRetVal_t retVal);

	bool Ok() const;
	bool HasWarnings() const;
	bool Critical() const;

	ZvdRetVal_t RetVal() const { return m_retVal; }
	operator ZvdRetVal_t() const { return m_retVal; }
private:
	void Evaluate();

	ZvdRetVal_t m_retVal;
	ZvdUInt32_t m_evalFlags{};
};

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

ZvdRetVal_t ZvdMakeOk(ZvdErrorCategory_t cat);

//-----------------------------------------------------------------------------
class ZvdErrorList_t
{
public:
	enum Code : ZvdUInt16_t
	{
		kSuccess,
		kInvalidArg,
		kInvalidUsage,
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
	ZvdErrorInfo_t(ZvdResultStatus_t status, ZvdErrorCategory_t cat, ZvdErrorList_t::Code code);

	ZvdRetVal_t RetVal() const { return m_retVal; }
	ZvdResultStatus_t Status() const;
	ZvdErrorCategory_t Category() const;
	ZvdErrorList_t::Code Code() const;

	static ZvdErrorInfo_t Ok();
private:
	static void Format(ZvdRetVal_t& retVal, ZvdResultStatus_t status, ZvdErrorCategory_t cat, ZvdErrorList_t::Code code);
	ZvdRetVal_t m_retVal;
};
#endif // ZV3D_CORE_COMMON_ERROR_H