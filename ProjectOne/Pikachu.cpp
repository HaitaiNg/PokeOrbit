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
const double MaxSpeedX = 0.06;

//! Minimum speed in the X direction in
//! in pixels per second
const double MinSpeedX = 0.06;

//! Maximum speed in the Y direction in
//! in pixels per second
const double MaxSpeedY = 0.06;

//! Minimum speed in the Y direction in
//! in pixels per second
const double MinSpeedY = 0.06;


/**
* Constructor
* \param orbit Orbit this Pokemon is a member of
*/
/** Constructor
* \param aquarium The aquarium this is a member of
*/
CPikachu::CPikachu(COrbit *orbit) :
	CPokemon(orbit, PikachuImageName)
{
	SetSpeed(MinSpeedX, MaxSpeedX, MinSpeedY, MaxSpeedY);
}

/**
* Destructor
*/
CPikachu::~CPikachu()
{
}

