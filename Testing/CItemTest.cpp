#include "stdafx.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Orbit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// Blastoise filename 
const std::wstring BlastoiseImageName(L"images/blastoise.png");

namespace Testing
{
	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		/** Constructor
		* \param aquarium The aquarium this is a member of */
		CItemMock(COrbit *orbit) :
			CItem(orbit, BlastoiseImageName) {}

		/** Draw the item
		* \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics *graphics) {}

		/** Test to see if we clicked on this item
		* \param x X location
		* \param y Y location
		* \returns true if we did click on the item */
		virtual bool HitTest(int x, int y) { return false; }
	};

	/** \breif Class that tests the class CItemTest */
	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCItemConstruct)
		{
			COrbit orbit;
			CItemMock item(&orbit);
		}


		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			COrbit orbit;
			CItemMock item(&orbit);


			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}

	};
}
