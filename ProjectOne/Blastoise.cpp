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
const double MaxSpeedX = 0.005;

//! Minimum speed in the X direction in
//! in pixels per second
const double MinSpeedX = 0.02;

//! Maximum speed in the Y direction in
//! in pixels per second
const double MaxSpeedY = 0.01;

//! Minimum speed in the Y direction in
//! in pixels per second
const double MinSpeedY = 0.03;

 /** Constructor
 * \param orbit The orbit this is a member of
 */
CBlastoise::CBlastoise(COrbit *orbit) :
	CPokemon(orbit, BlastoiseImageName, Blastoise)
{
	SetSpeed(MinSpeedX, MaxSpeedX, MinSpeedY, MaxSpeedY);
	SetRadius();
	SetAngle(); 
}


/**
 * Destructor 
 */
CBlastoise::~CBlastoise()
{
}
