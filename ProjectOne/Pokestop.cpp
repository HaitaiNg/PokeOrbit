/**
 * \file Pokestop.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Pokestop.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring PokestopImageName(L"images/pokestop.png");

/**
* Constructor
* \param aquarium The aquarium we are in
* \param filename Filename for the image we use
*/
CPokestop::CPokestop(COrbit *orbit):
	CRotationalItem(orbit, PokestopImageName)
{

}


/**
 * Destructor 
 */
CPokestop::~CPokestop()
{
}


