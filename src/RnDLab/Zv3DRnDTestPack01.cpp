// Zv3D Engine. (C) 2012-2024 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: test pack 1 in RnD.
/*
	04-Jan-2023	grv creation.
*/

#include "RnDLab/Zv3DRnDTestBase.h"
#include "RnDLab/Zv3DRnDTestPack01.h"

namespace zvd
{
	namespace rnd
	{
		namespace testpack01
		{
			class Test01 : public TestBase
			{
			public:
				Test01(const char* pName, const char* pDescription = "")
					: TestBase(pName, pDescription)
				{}

				int runImpl(int argc = 0, char** argv = nullptr) override
				{
					ZVD_UNUSED(argc);
					ZVD_UNUSED(argv);
					std::cout << "Hello, man!" << std::endl;
					return 0;
				}

			};
		}
	} // eof rnd
} // eof zvd

namespace zvd
{
	namespace rnd
	{
		namespace testpack01
		{
			int run(int testIndex, int argc, char**  argv)
			{
				if (1 == testIndex)
				{
					Test01 test("RndLab, pack01, test01, sfinae caps");
					int result = test.run(argc, argv);
					return result;
				}
			}
		}
	}
}