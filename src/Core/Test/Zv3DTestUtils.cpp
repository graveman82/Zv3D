// Zv3D Engine. (C) 2012-2022 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: test utils impl.
/*
	23-Dec-2022	grv creation.
*/

#include "Core/Common/Zv3DAssert.h"

#include <iostream>

void ZvdTestWaitKey()
{
	std::cout << "Press any key to continue..." << std::endl;
	std::string qs;
	std::cin >> qs;
}