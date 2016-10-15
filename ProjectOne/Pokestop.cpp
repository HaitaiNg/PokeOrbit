/**
 * \file Pokestop.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Pokestop.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring PokestopImageName(L"images/pokestop.png");

/// Fish filename 
const wstring PokestopClickedName(L"images/pokestop-used.png");


/**
 * Constructor
 * \param orbit the orbit system this item is a part of
 */
CPokestop::CPokestop(COrbit *orbit):
	CRotationalItem(orbit, PokestopImageName)
{
	SetImage(PokestopImageName);

	Load(mClickedImage, PokestopClickedName);

	SetSpeed(0.02, 0.02, 0.02, 0.02);
	SetRadius();
	SetAngle();

}


/**
 * Destructor 
 */
CPokestop::~CPokestop()
{
}

/**
* Handle updates in time of our fish
*
* This is called before we draw and allows us to
* move our fish. We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CPokestop::Update(double elapsed)
{
	CItem::Update(elapsed);

	double x = mRadius * cos(mAngle);
	double y = -mRadius * sin(mAngle);

	double sn = sin(mAngle);
	double cs = cos(mAngle);

	double newX = cs * x + sn * y;
	double newY = -sn * x + cs * y;

	x += mSpeedX * x * elapsed;
	y += mSpeedX * y * elapsed;

	mAngle += 0.01;

	SetLocation(x, y);

	//SetLocation(GetX(),GetY());
}



/**
 * Load image file to be drawn
 * \param image 
 * \param name 
 */
void CPokestop::Load(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/**
 * Overriden draw to draw different states of pokestop
 * \param graphics 
 */
void CPokestop::Draw(Gdiplus::Graphics * graphics)
{
	CItem::Draw(graphics);

	if (mClicked)
	{
		int wid = mClickedImage->GetWidth();
		int hit = mClickedImage->GetHeight();

		graphics->DrawImage(mClickedImage.get(),
			(int)(GetX() - wid / 2), (int)(GetY() - hit / 2),
			wid, hit);
	}
}

/** Set the speed of this fish from some range
*
* This function is called from a derived fish constructor
* and allows us to set a speed for that fish in some
* range from min to max in each dimension.
* \param minX Minimum X value
* \param maxX Maximum X value
* \param minY Minimum Y value
* \param maxY Maximum Y value
*/
void CPokestop::SetSpeed(double minX, double maxX, double minY, double maxY)
{
	//mSpeedX = minX + ((double)rand() / RAND_MAX) * (maxX - minX);
	//mSpeedY = minY + ((double)rand() / RAND_MAX) * (maxX - minY);

	mSpeedX = -minX;
	//mSpeedY = -minY;
}

/**
 * Sets the radius of the item
 * \returns mRadius random radius in pixels
 */
double CPokestop::SetRadius()
{
	mRadius = (rand() % 300) + 120;
	return mRadius;
}


/**
 * Sets the angle of the item
 * \returns mAngle random angle between 0 and 360 degrees
 */
double CPokestop::SetAngle()
{
	mAngle = (rand() % 360);
	return mAngle;
}
