/**
 * \file RotationalItem.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "RotationalItem.h"

 /// Maximum range up and down. This is 
 /// the maximum distance the item will move in pixels
const double MaxYRange = 500;

/// Maximum range side to side. This is 
/// the maximum distance the item will move in pixels
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
	mX = mRadius * cos(mAngle * mSpeedRatio);
	mY = -mRadius * sin(mAngle * mSpeedRatio);

	sn = sin(mAngle * mSpeedRatio);
	cs = cos(mAngle * mSpeedRatio);

	newX = cs * mX + sn * mY;
	newY = -sn * mX + cs * mY;

	mAngle += 0.01;

	SetLocation(newX, newY);

}


/**
 * Set speed for the object 
 * \param minX 
 * \param maxX 
 * \param minY 
 * \param maxY 
 */
void CRotationalItem::SetSpeed(double minX, double maxX, double mThreshold, double maxY)
{

	mSpeedRatio = mThreshold + ((double) rand() / RAND_MAX) * (maxX - minX); 
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


/**
 * Return the x position for the emitter class 
 * \returns position x 
 */
double CRotationalItem::ReturnXPosition()
{
	return mX; 
}

/**
* Return the y position for the emitter class
* \returns position y
*/
double CRotationalItem::ReturnYPosition()
{
	return mY;
}