/**
 * \file Pokemon.h
 *
 * \author Haitai Ng 
 *
 *  
 */

#pragma once
#include "Item.h"
#include "RotationalItem.h"

/**
 * Base class for a Pokemon 
 * This applies to all of the Pokemon, but not the Pokestops
 * items in the orbit. 
 */
class CPokemon :
	public CRotationalItem
{
public:

	/// Default constructor (disabled) 
	CPokemon() = delete; 

	/// Copy Constructor (disabled) 
	CPokemon(const CPokemon &) = delete; 

	/// Destructor 
	virtual ~CPokemon();

protected:
	/// Constructor 
	CPokemon(COrbit * orbit, const std::wstring & filename);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitPokemon(this); }
};

