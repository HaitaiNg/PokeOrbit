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

CPokeBall::CPokeBall(COrbit *orbit) :
	CLinearMovement(orbit, PokeBallImageName)
{
	
}


CPokeBall::~CPokeBall()
{
}
