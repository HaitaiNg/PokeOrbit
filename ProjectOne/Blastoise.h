/**
 * \file Blastoise.h
 *
 * \author Haitai Ng 
 *
 *  Class for a pokemon Blastoise type. Class that implements a Blastoise 
 */

#pragma once
#include <memory>
#include "Item.h"
#include "Pokemon.h"

/**
 * Implements a Pokemon/Blastoise. Blastoise is the slowest Pokemon. Blastoise is derived from Pokemon 
 */
class CBlastoise : public CPokemon
{
public:
	///Constructor 
	CBlastoise(COrbit *orbit); 

	/// Default constructor (disabled)
	CBlastoise() = delete;

	/// Copy constructor (disabled)
	CBlastoise(const CBlastoise &) = delete;

	/// Destructor 
	virtual ~CBlastoise();

};

