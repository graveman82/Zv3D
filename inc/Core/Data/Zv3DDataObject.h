#ifndef ZV3D_CORE_DATA_DATAOBJECT_H
#define ZV3D_CORE_DATA_DATAOBJECT_H

// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: data object base class.
/*
	24-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DBaseTypes.h"
#include "Core/Common/Zv3DError.h"

/// <summary>
/// This is a base class for all objects in engine that represent some data.
/// Naming notes for derived classes: 
///  prefix "Ob" ("Data [Ob]ject"). We omit "D" and leave the "ob" only. For example, ZvdObWorldMesh.
/// </summary>
class ZvdDataObject
{
public:
	virtual ~ZvdDataObject();
	/// <summary>
	/// Loads data by specified loader.
	/// </summary>
	/// <param name="pLoader"></param>
	/// <returns></returns>
	virtual ZvdRetVal_t Load(IZvdDataLoader* pLoader) = 0;
};
#endif // ZV3D_CORE_DATA_DATAOBJECT_H
