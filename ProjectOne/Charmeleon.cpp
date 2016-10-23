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
const double MaxSpeedX = 0.75;

//! Minimum speed in the X direction in
//! in pixels per second
const double MinSpeedX = 0.6;

//! Maximum speed in the Y direction in
//! in pixels per second
const double MaxSpeedY = 0.04;

//! Minimum speed in the Y direction in
//! in pixels per second
const double SpeedMin = 0.6;

/** Constructor
* \param orbit The orbit this is a member of
*/
CCharmeleon::CCharmeleon(COrbit *orbit) :
	CPokemon(orbit, CharmeleonImageName, Charmeleon)
{
	SetSpeed(MinSpeedX, MaxSpeedX, SpeedMin, MaxSpeedY);
	SetRadius();
	SetAngle(); 
}


/**
* Destructor
*/
CCharmeleon::~CCharmeleon()
{
}
