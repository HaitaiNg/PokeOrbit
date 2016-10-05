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

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CCharmeleon::CCharmeleon(COrbit *orbit) :
	CPokemon(orbit, CharmeleonImageName)
{
}


/**
* Destructor
*/
CCharmeleon::~CCharmeleon()
{
}
