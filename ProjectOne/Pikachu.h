/**
 * \file Pikachu.h
 *
 * \author Haitai Ng 
 *
 *  Class that implements a pokemon of type Pikachu. 
 */

#pragma once
#include "Item.h"
#include <memory>
#include "Pokemon.h"

 /**
 * Implements a Pokemon/ Pikachu. Pikachu is a fire pokemon derived from Pokemon
 */
class CPikachu :
	public CPokemon
{
public:

	///Constructor 
	CPikachu(COrbit *orbit);

	/// Default Constructor disabled  
	CPikachu() = delete;

	/// Copy constructor (disabled)
	CPikachu(const CPikachu &) = delete;

	/// Destructor 
	virtual ~CPikachu();
};
