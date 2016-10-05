/**
 * \file Pokemon.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Pokemon.h"
#include "Orbit.h"

/**
* Constructor
* \param aquarium The aquarium we are in
* \param filename Filename for the image we use
*/
CPokemon::CPokemon(COrbit *orbit, const std::wstring &filename) :
	CItem(orbit, filename)
{
	mSpeedX = 200; 
	mSpeedY = 0;
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
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);
}