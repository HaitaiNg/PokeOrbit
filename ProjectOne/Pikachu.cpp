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
}

/**
* Destructor
*/
CPikachu::~CPikachu()
{
}

