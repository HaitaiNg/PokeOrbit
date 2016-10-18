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
	mPosX += mSpeedX * elapsed ;
	mPosY += mSpeedY * elapsed ;

	/// Check if the object needs to be destroyed 
	DestroyObject();
	SetLocation(mPosX, mPosY);
}


/**
* Determine if the object should be destroyed. If Pokeball is 500 pixels away from center, destroy it.
* \returns bool
*/
bool CLinearMovement::DestroyObject()
{
	/// Radius formula 
	mRadius = sqrt(GetX() * GetX() + GetY() * GetY());

	/// Determine if the Pokeball is 500 pixels away from center
	if ((abs(mRadius) >= 480))
	{
		return true; ///< If pokeball is to far, destroy it 
	}

	return false;
}
