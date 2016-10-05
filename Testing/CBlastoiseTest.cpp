/**
* \file CBlastoiseTest.cpp
*
* \author Haitai Ng
*/

#include "stdafx.h"
#include "CppUnitTest.h"

#include "Orbit.h"
#include "Blastoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CBlastoiseTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCBlastoiseConstruct)
		{
			COrbit orbit;
			CBlastoise blastoise(&orbit); 
		}

		TEST_METHOD(TestCBlastoiseHitTest)
		{
			// Create a Pokemon to test
			COrbit orbit; 
			CBlastoise blastoise(&orbit);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			blastoise.SetLocation(100, 200);

			// Center of the pokemon should be a true
			Assert::IsTrue(blastoise.HitTest(100, 200));

			// Left of the pokemon
			Assert::IsFalse(blastoise.HitTest(10, 200));

			// Right of the pokemon
			Assert::IsFalse(blastoise.HitTest(200, 200));

			// Above the pokemon
			Assert::IsFalse(blastoise.HitTest(100, 0));

			// Below the pokemon
			Assert::IsFalse(blastoise.HitTest(100, 300));

			// Of pokemon transparent pixel
			Assert::IsFalse(blastoise.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}
	};
}