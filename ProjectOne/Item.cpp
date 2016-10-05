/**
 * \file Item.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "Item.h"
#include "Orbit.h"


/** Constructor
* \param aquarium The aquarium this item is a member of
*/
CItem::CItem(COrbit *aquarium) : mOrbit(aquarium)
{
}


/**
 * Destructor 
 */
CItem::~CItem()
{
}
