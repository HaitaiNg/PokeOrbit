/**
 * \ file LinearMovement.cpp
 * 
 * \ author Quan Zhou
 *
 */

#include "stdafx.h"
#include "LinearMovement.h"
#include "Orbit.h"

/**
 * constructor
 */
CLinearMovement::CLinearMovement(COrbit *orbit, const std::wstring &filename) :
	CItem(orbit, filename)
{
	mSpeedX = 0;
	mSpeedY = 0;
}

/** 
 * Destructor
 */
CLinearMovement::~CLinearMovement()
{
}

/**
* Handle updates in time of our linearmovement
*
* This is called before we draw and allows us to
* move our pokeball. We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CLinearMovement::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);
}
