/**
 * \file Charmeleon.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Charmeleon.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring CharmeleonImageName(L"images/charmeleon.png");

//! Maximum speed in the X direction in
//! in pixels per second
const double MaxSpeedX = 60;

//! Minimum speed in the X direction in
//! in pixels per second
const double MinSpeedX = 20;

//! Maximum speed in the Y direction in
//! in pixels per second
const double MaxSpeedY = 20;

//! Minimum speed in the Y direction in
//! in pixels per second
const double MinSpeedY = 50;


/** Constructor
* \param aquarium The aquarium this is a member of
*/
CCharmeleon::CCharmeleon(COrbit *orbit) :
	CPokemon(orbit, CharmeleonImageName)
{
	SetSpeed(MinSpeedX, MaxSpeedX, MinSpeedY, MaxSpeedY);
}


/**
* Destructor
*/
CCharmeleon::~CCharmeleon()
{
}
