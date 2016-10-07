/** 
 * \file PokeBall.cpp
 *
 * \ author Quan Zhou
 *
 */

#include "stdafx.h"
#include "PokeBall.h"
#include <string>

using namespace std;
using namespace Gdiplus;

///PokeBall Image
const wstring PokeBallImageName(L"images/pokeball.png");

/// Speed for the pokeball in X direction
const double SpeedX = 50;

/// Speed for the pokeball in Y direction
const double SpeedY = 50;

CPokeBall::CPokeBall(COrbit *orbit) :
	CLinearMovement(orbit, PokeBallImageName)
{
	setspeed(SpeedX, SpeedY);
}


CPokeBall::~CPokeBall()
{
}
