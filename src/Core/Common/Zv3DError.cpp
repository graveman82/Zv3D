// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: error handling utils (impl).
/*
	23-Dec-2022	grv creation.
*/

#include "stdafx.h"
#include "Core/Common/Zv3DError.h"
#include "Core/Common/Zv3DAssert.h"
#include "Core/Common/Zv3DByteUtils.h"

namespace zvd
{
	namespace err
	{
		static const ZvdChar_t* s_textualDesc[ZvdErrorList_t::kCount] =
		{
			ZVD_T("Success"),
			ZVD_T("Invalid arguments passed"),
			ZVD_T("Not enough memory in system"),
			ZVD_T("Out of range"),
		};
	}
	
}

const ZvdChar_t* ZvdToString(ZvdResultStatus_t status)
{
	static const ZvdChar_t* textualDesc[kZvdResultStatusCount] =
	{
		ZVD_T("Unknown"),
		ZVD_T("None"),
		ZVD_T("Ok"),
		ZVD_T("Fail"),
		ZVD_T("Warning"),
		ZVD_T("Error"),
		ZVD_T("Cancel")
	};
	if (status == kZvdUnk)
	{
		return textualDesc[0];
	}
	return textualDesc[status + 1];
}

bool ZvdIsOk(ZvdResultStatus_t status)
{
	switch (status)
	{
	case kZvdOk:
	case kZvdWarn:
	case kZvdNone:
		return true;
	default:
		return false;
	}
}

const ZvdChar_t* ZvdToString(ZvdErrorCategory_t cat)
{
	static const ZvdChar_t* textualDesc[static_cast<ZvdSize_t>(ZvdErrorCategory_t::kCount)] =
	{
		ZVD_T("Core"),
		ZVD_T("Lang library"),
		ZVD_T("Engine"),
		ZVD_T("System"),
		ZVD_T("Memory manager"),
		ZVD_T("Graphics device")
	};
	
	return textualDesc[static_cast<ZvdSize_t>(cat)];
}

//-----------------------------------------------------------------------------
const ZvdChar_t* ZvdErrorList_t::GetText(ZvdErrorList_t::Code code)
{
	ZVD_ASSERT_HIGH_NOMSG(code < ZvdErrorList_t::kCount);
	return zvd::err::s_textualDesc[code];
}

//-----------------------------------------------------------------------------
void ZvdErrorInfo_t::Format(ZvdResultStatus_t status, ZvdErrorCategory_t cat, ZvdErrorList_t::Code code)
{
	ZvdRetVal_t retVal;
	ZVD_BYTE0(retVal) = status;
	ZVD_BYTE1(retVal) = static_cast<ZvdByte_t>(cat);
	ZVD_WORD1(retVal) = static_cast<ZvdUInt16_t>(code);

}

//-----------------------------------------------------------------------------
ZvdResultStatus_t ZvdErrorInfo_t::Status() const
{
	return static_cast<ZvdResultStatus_t>(ZVD_BYTE0(m_retVal));
}

//-----------------------------------------------------------------------------
ZvdErrorCategory_t ZvdErrorInfo_t::Category() const
{
	return static_cast<ZvdErrorCategory_t>(ZVD_BYTE1(m_retVal));
}

//-----------------------------------------------------------------------------
ZvdErrorList_t::Code ZvdErrorInfo_t::Code() const
{
	return static_cast<ZvdErrorList_t::Code>(ZVD_WORD1(m_retVal));
}