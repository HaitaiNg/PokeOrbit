/**
 * \file Pikachu.cpp
 *
 * \author Haitai Ng 
 */

 /**
 * \file Blastoise.cpp
 *
 * \author Haitai Ng
 */

#include "stdafx.h"
#include "Pikachu.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring PikachuImageName(L"images/pikachu.png");

//! Maximum speed in the X direction in
//! in pixels per second
const double MaxSpeedX = 1.5;

//! Minimum speed in the X direction in
//! in pixels per second
const double MinSpeedX = 1;

//! Maximum speed in the Y direction in
//! in pixels per second
const double MaxSpeedY = 0.09;

//! Minimum speed in the Y direction in
//! in pixels per second
const double SpeedMin = 1;


/**
* Constructor
* \param orbit Orbit this Pokemon is a member of
*/
/** Constructor
* \param orbit The orbit this is a member of
*/
CPikachu::CPikachu(COrbit *orbit) :
	CPokemon(orbit, PikachuImageName, Pikachu)
{
	SetSpeed(MinSpeedX, MaxSpeedX, SpeedMin, MaxSpeedY);
	SetRadius();
	SetAngle(); 
}

/**
* Destructor
*/
CPikachu::~CPikachu()
{
}

