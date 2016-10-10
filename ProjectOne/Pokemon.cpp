/**
 * \file Pokemon.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Pokemon.h"
#include "RotationalItem.h"


 /// Maximum range up and down. This is 
 /// the maximum distance the fish will swim
 /// up and down in pixels
const double MaxYRange = 500; 
const double MaxXRange = 500;


/**
* Constructor
* \param aquarium The aquarium we are in
* \param filename Filename for the image we use
*/
CPokemon::CPokemon(COrbit *orbit, const std::wstring &filename) :
	CRotationalItem(orbit, filename)
{

}

/**
 * Destructor 
 */
CPokemon::~CPokemon()
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
void CPokemon::Update(double elapsed)
{
	double x = mRadius * cos(mAngle);
	double y = -mRadius * sin(mAngle);

	double sn = sin(mAngle);
	double cs = cos(mAngle);

	double newX = cs * x + sn * y; 
	double newY = -sn * x + cs * y; 

	x +=  mSpeedX * x * elapsed;
	y +=  mSpeedX * y * elapsed;

	mAngle += 0.01; 

	SetLocation(x, y);
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
void CPokemon::SetSpeed(double minX, double maxX, double minY, double maxY)
{
	//mSpeedX = minX + ((double)rand() / RAND_MAX) * (maxX - minX);
	//mSpeedY = minY + ((double)rand() / RAND_MAX) * (maxX - minY);

	mSpeedX = -minX;
	//mSpeedY = -minY;
}

double CPokemon::SetRadius()
{
	mRadius = (rand() % 300) + 120;
	return mRadius; 
}


double CPokemon::SetAngle()
{
	mAngle = (rand() % 360);
	return mAngle; 
}
