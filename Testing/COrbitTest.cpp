/**
 * \file COrbitTest.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Orbit.h"
#include "Blastoise.h"

#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std; 

namespace Testing
{
	TEST_CLASS(COrbitTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCOrbitConstruct)
		{
			COrbit orbit;
		}


		TEST_METHOD(TestCOrbitHitTest)
		{
			COrbit orbit;

			Assert::IsTrue(orbit.HitTest(100, 200) == nullptr,
				L"Testing empty orbit");

			shared_ptr<CBlastoise> blastoise1 = make_shared<CBlastoise>(&orbit);
			blastoise1->SetLocation(100, 200);
			orbit.Add(blastoise1);

			Assert::IsTrue(orbit.HitTest(100, 200) == blastoise1,
				L"Testing blastoise at 100, 200");

			// Test to ensure nullptr if we hit away from any image
			Assert::IsTrue(orbit.HitTest(0, 200) == nullptr, L"Testing blastoise at 00, 200");

			// Add two overlapping fish
			shared_ptr<CBlastoise> blastoise2 = make_shared<CBlastoise>(&orbit);
			blastoise2->SetLocation(400, 400);
			orbit.Add(blastoise2);

			shared_ptr<CBlastoise> blastoise3 = make_shared<CBlastoise>(&orbit);
			blastoise3->SetLocation(400, 400);
			orbit.Add(blastoise3);

			// Ensure the top one is found
			Assert::IsTrue(orbit.HitTest(400, 400) == blastoise3, L"Testing overlapping blastoise");
		
		}
	};
}