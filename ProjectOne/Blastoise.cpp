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

 /** Constructor
 * \param aquarium The aquarium this is a member of
 */
CBlastoise::CBlastoise(COrbit *orbit) :
	CPokemon(orbit, BlastoiseImageName)
{
}


/**
 * Destructor 
 */
CBlastoise::~CBlastoise()
{
}
