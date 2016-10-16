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

/// Handle updates for animation
/// \param elapsed The time since the last update
void CPokestop::Update(double elapsed)
{
	CRotationalItem::Update(elapsed);

	// Timer if pokestop is clicked on
	if (mClicked)
	{
		LARGE_INTEGER frequency;
		LARGE_INTEGER end;
		double elapsedSeconds;
		QueryPerformanceFrequency(&frequency);
		

		QueryPerformanceCounter(&end);
		elapsedSeconds = (end.QuadPart - mStartTime) / (double)frequency.QuadPart;

		if (elapsedSeconds > 15)
		{
			mClicked = false;
		}
	}
}

/**
 * If pokestop is not in clicked state and is clicked on, change start and initialize timer
 */
void CPokestop::IsClicked()
{
	if (!mClicked)
	{
		mClicked = true;

		LARGE_INTEGER start;
		QueryPerformanceCounter(&start);
		mStartTime = start.QuadPart;
	}
}

