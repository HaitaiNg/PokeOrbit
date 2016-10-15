/**
 * \file RotationalItem.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "RotationalItem.h"

 /// Maximum range up and down. This is 
 /// the maximum distance the fish will swim
 /// up and down in pixels
const double MaxYRange = 500;
const double MaxXRange = 500;


/**
 * Constructor 
 * \param orbit 
 * \param filename 
 */
CRotationalItem::CRotationalItem(COrbit *orbit, const std::wstring &filename):
	CItem(orbit, filename)
{
}


/**
 * Destructor 
 */
CRotationalItem::~CRotationalItem()
{
}

/// Handle updates for animation
/// \param elapsed The time since the last update
void CRotationalItem::Update(double elapsed)
{
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

}


/**
 * Set speed for the object 
 * \param minX 
 * \param maxX 
 * \param minY 
 * \param maxY 
 */
void CRotationalItem::SetSpeed(double minX, double maxX, double minY, double maxY)
{
	mSpeedX = -minX;
}


/**
 * Calculate a random radius for the object 
 * \returns radius  
 */
double CRotationalItem::SetRadius()
{
	mRadius = (rand() % 300) + 120;
	return mRadius;
}


/**
 * Calculate a random angle for the object 
 * \returns angle 
 */
double CRotationalItem::SetAngle()
{
	mAngle = (rand() % 360);
	return mAngle;
}

