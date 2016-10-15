/**
 * \file Pokemon.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Pokemon.h"
#include "RotationalItem.h"


/**
* Constructor
* \param aquarium The aquarium we are in
* \param filename Filename for the image we use
*/
CPokemon::CPokemon(COrbit *orbit, const std::wstring &filename) :
	CRotationalItem(orbit, filename)
{

}

/**
 * Destructor 
 */
CPokemon::~CPokemon()
{
}

