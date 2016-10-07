/**
 * \file Orbit.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Orbit.h"
#include "Blastoise.h"
#include <cmath>

using namespace std; 
using namespace Gdiplus;

/// Playing area width in virtual pixels
const static int Width = 1400;

/// Playing area height in virtual pixels
const static int Height = 1100;

/// Radius of the playing read in virtual pixels
const static int Radius = 500;

/**
 * Constructor 
 */
COrbit::COrbit()
{
	/**It uses the static member function Bitmap::FromFile to load
	the image from the disk. Then it checks to ensure it loaded okay.
	If not, it displays an error message using the message function box */
	mAshImage = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/ash.png"));
	if (mAshImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/ash.png");
	}
}


/**
 * Destructor
 */
COrbit::~COrbit()
{
}



/**
* Draw the game area & ash 
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void COrbit::OnDraw(Gdiplus::Graphics *graphics, int width, int height)
{
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	float scale = min(scaleX, scaleY);
	float radius = COrbit::Radius;

	float xOffset = width / 2.0f;
	float yOffset = height / 2.0f;

	graphics->TranslateTransform(xOffset, yOffset);
	graphics->ScaleTransform(scale, scale);

	// From here on you are drawing virtual pixels...

	//
	// And the circle so you can see how this works...
	//
	Pen pen(Color::Green);
	graphics->DrawArc(&pen, -radius, -radius, radius * 2, radius * 2, 0, 360);

	/// Get the width and height for mAshImage 
	int mAshImageHeight = (mAshImage->GetHeight()); 
	int mAshImageWidth = (mAshImage->GetWidth()); 

	/// Apply the conversion to the width and height values so they can become coordinates  
	int mAshImageY = -1 * mAshImageHeight / 2; 
	int mAshImageX = -1 * (mAshImageWidth / 2); 

	/// This will draw Ash Ketchum. Ash is located in the center of the orbit. 
	/// Shift the image a little bit. (-ashimagewidth /2, -ashimageheight/2
	graphics->DrawImage(mAshImage.get(), mAshImageX, mAshImageY,
		mAshImage->GetWidth(), mAshImage->GetHeight());

}


/**
* Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void COrbit::Draw(Gdiplus::Graphics *graphics)
{
	//Iterate through collection and draw them. 
	for (auto item : mItems) ///< auto figures out the type automatically( try to use auto as much as possible) 
	{
		item->Draw(graphics);
	}
}


/**
* Add an item to the aquarium
* \param item New item to add
*/
void COrbit::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}



/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> COrbit::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


/** Move an item to the front of the list of items.
*
* Removes item from the list and adds it to the end so it
* will display last.
* \param item The item to move
*/
void COrbit::MoveToFront(std::shared_ptr<CItem> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}

	mItems.push_back(item);
}


/** Handle updates for animation
* \param elapsed The time since the last update
*/
void COrbit::Update(double elapsed)
{
	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}