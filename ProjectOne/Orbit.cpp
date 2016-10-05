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

}


/**
 * Destructor
 */
COrbit::~COrbit()
{
}



/**
* Draw the game area
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
	//graphics->DrawArc(&pen, radius, radius, radius * 2, radius * 2, 0, 360);


	/// Iterate through collection and draw them 
	for (auto item : mItems) ///< auto figures out the type automatically 
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