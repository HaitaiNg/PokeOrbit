/**
 * \file Blastoise.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Blastoise.h"
#include <string>

using namespace std;
using namespace Gdiplus; 

 /// Fish filename 
const wstring BlastoiseImageName(L"images/blastoise.png");

 /**
 * Constructor
 * \param orbit Orbit this Pokemon is a member of
 */
CBlastoise::CBlastoise(COrbit *orbit) : CItem(orbit)
{
	mBlastoiseImage = unique_ptr<Bitmap>(Bitmap::FromFile(BlastoiseImageName.c_str()));
	if (mBlastoiseImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += BlastoiseImageName;
		AfxMessageBox(msg.c_str());
	}
}


/**
 * Destructor 
 */
CBlastoise::~CBlastoise()
{
}


/**
* Draw this item
* \param graphics Graphics device to draw on
*/
void CBlastoise::Draw(Gdiplus::Graphics *graphics)
{
	double wid = mBlastoiseImage->GetWidth();
	double hit = mBlastoiseImage->GetHeight();
	graphics->DrawImage(mBlastoiseImage.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		(float)mBlastoiseImage->GetWidth(), (float)mBlastoiseImage->GetHeight());
}

/**
* Test to see if we hit this object with a mouse.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CBlastoise::HitTest(int x, int y)
{
	double wid = mBlastoiseImage->GetWidth();
	double hit = mBlastoiseImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mBlastoiseImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mBlastoiseImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}