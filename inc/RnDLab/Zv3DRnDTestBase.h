// Zv3D Engine. (C) 2012-2024 Marat Sungatullin (aka graveman, aka mrsung)
//
// License: double license GPLv3 and zlib (see "Zv3DLicense.txt").
// 
// Purpose: base class for test classes in RnD.
/*
	04-Jan-2023	grv creation.
*/

#ifndef ZV3D_RNDLAB_TEST_BASE_H
#define ZV3D_RNDLAB_TEST_BASE_H

#include <iostream>
#include "Core/Common/Zv3DCompiler.h"
#include "Core/Common/Zv3DCommonUtils.h"

namespace zvd
{
	namespace rnd
	{
		class TestBase
		{
		public:
			TestBase(const char* pName, const char* pDescription = "")
				: m_pName{ pName }
				, m_pDescription{pDescription}
			{
				
			}

			virtual ~TestBase()
			{

			}

			virtual int run(int argc = 0, char** argv = nullptr)
			{
				if (m_state)
					return 0;
				m_state = true;
				printHeader();
				int retVal = runImpl(argc, argv);
				printFooter();
				m_state = false;
				return retVal;
			}

		protected:

			virtual int runImpl(int argc = 0, char** argv = nullptr) = 0;

			void printHeader()
			{
				std::cout << getMainBorder();
				std::cout << getEmptyComment();
				std::cout << getCommentStart() << "Test \"" << m_pName << "\" started." << std::endl;
				std::cout << getCommentStart() << getCppInfo() << std::endl;
				std::cout << getCommentStart() << "Info:";
				if (m_pDescription[0])
					std::cout << "\n" << m_pDescription;
				std::cout << std::endl;
				std::cout << getEmptyComment();
				std::cout << getMainBorder() << std::endl;
			}

			void printFooter()
			{
				std::cout << getMainBorder();
				std::cout << getEmptyComment();
				std::cout << getCommentStart() << "Test \"" << m_pName << "\" ended." << std::endl;
				std::cout << getMainBorder() << std::endl;
			}

			const char* getCppInfo()
			{
#if defined(ZVD_CPP) && ZVD_CPP == ZVD_CPP03
				return"C++ 03";
#elif defined(ZVD_CPP) && ZVD_CPP == ZVD_CPP11
				return"C++ 11";
#elif defined(ZVD_CPP) && ZVD_CPP == ZVD_CPP14
				return"C++ 14";
#elif defined(ZVD_CPP) && ZVD_CPP == ZVD_CPP17
				return"C++ 17";
#elif defined(ZVD_CPP) && ZVD_CPP == ZVD_CPP20
				return"C++ 20";
#else
				return "no C++";
#endif
			}

			const char* getMainBorder()
			{
				return "///////////////////////////////////////////////////////////////////////////////\n";
			}

			const char* getBorder()
			{
				return "-------------------------------------------------------------------------------\n";
			}

			const char* getCommentStart() 
			{ return "// * "; }

			const char* getEmptyComment()
			{
				return "// *\n";
			}

			const char* getIndent1(bool bPreDashed = false)
			{
				if (bPreDashed)
				{
					return " -- ";
				}
				return "    ";
			}

			const char* getIndent2(bool bPreDashed = false)
			{
				if (bPreDashed)
				{
					return " --  -- ";
				}
				return "        ";
			}
		private:
			bool m_state{  };
			const char* m_pName{ "" };
			const char* m_pDescription{ "" };
		};

		class ExampleTest : public TestBase
		{
		public:
			ExampleTest(const char* pName, const char* pDescription = "")
				: TestBase(pName, pDescription)
			{}

			int runImpl(int argc = 0, char** argv = nullptr) override
			{
				ZVD_UNUSED(argc);
				ZVD_UNUSED(argv);
				std::cout << "Hello, world!" << std::endl;
				return 0;
			}

		};
	} // eof rnd
}
#endif // ZV3D_RNDLAB_TEST_BASE_H