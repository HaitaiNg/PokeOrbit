/**
 * \file Blastoise.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Blastoise.h"
#include <string>

using namespace std;
using namespace Gdiplus; 

 /// Fish filename 
const wstring BlastoiseImageName(L"images/blastoise.png");


//! Maximum speed in the X direction in
//! in pixels per second
const double MaxSpeedX = 6;

//! Minimum speed in the X direction in
//! in pixels per second
const double MinSpeedX = 2;

//! Maximum speed in the Y direction in
//! in pixels per second
const double MaxSpeedY = 2;

//! Minimum speed in the Y direction in
//! in pixels per second
const double MinSpeedY = 5;

 /** Constructor
 * \param aquarium The aquarium this is a member of
 */
CBlastoise::CBlastoise(COrbit *orbit) :
	CPokemon(orbit, BlastoiseImageName)
{
	SetSpeed(MinSpeedX, MaxSpeedX, MinSpeedY, MaxSpeedY);
}


/**
 * Destructor 
 */
CBlastoise::~CBlastoise()
{
}
