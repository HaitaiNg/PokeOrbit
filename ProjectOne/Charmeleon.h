/**
 * \file Charmeleon.h
 *
 * \author Haitai Ng 
 *
 * Class for a pokemon Charmeleon type. Class that implements a Charmeleon 
 */

#pragma once
#include "Item.h"
#include <memory>
#include "Pokemon.h"

/**
 * Implements a Pokemon/ Charmeleon. Charmeleon is a fire pokemon derived from Pokemon 
 */
class CCharmeleon :
	public CPokemon
{
public:

	///Constructor 
	CCharmeleon(COrbit *orbit);

	/// Default Constructor disabled  
	CCharmeleon() = delete ;

	/// Copy constructor (disabled)
	CCharmeleon(const CCharmeleon &) = delete;

	/// Destructor 
	virtual ~CCharmeleon();

};

