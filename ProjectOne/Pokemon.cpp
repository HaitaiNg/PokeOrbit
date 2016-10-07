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

/// The rate we swim up and down in radians per second
const double YSwimRate = 0.05 * 2 * 3.1415;

/// The rate we swim up and down in radians per second
const double XSwimRate = 0.05 * 2 * 3.1415;


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
	// What was the last sine value?
	double lastSine = sin(mTime * YSwimRate);

	double lastCos = cos(mTime * XSwimRate);

	// Update the time
	mTime += elapsed;

	// What is the new sine value?
	double newSine = sin(mTime * YSwimRate);

	double newCos = cos(mTime * XSwimRate);

	// How much the sine function changed is newSine - lastSine
	double sineChange = newSine - lastSine;

	double cosChange = newCos - lastCos;

	// And we can figure out the change to Y
	double newY = GetY() + sineChange * MaxYRange / 2;

	double newX = GetX() + cosChange * MaxXRange / 2; 

	/// modified sine wave - from step 3 
//	SetLocation(GetX() + mSpeedX * elapsed,
	//	newY);

	SetLocation(newX, newY);

	//SetLocation(GetX() + mSpeedX * elapsed,
		//GetY() + mSpeedY * elapsed);


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

	mSpeedX = minX;
	mSpeedY = minY;
}