/**
 * \file PokemonVisitor.h
 *
 * \author Haitai Ng 
 *
 * 
 */

#pragma once
#include "ItemVisitor.h"

/**
 * Visitor class to determine the initial radius of the Pokemon relative to the center (0,0) 
 */
class CPokemonVisitor :
	public CItemVisitor
{
public:
	/// constructor 
	CPokemonVisitor();

	/// destructor 
	virtual ~CPokemonVisitor();

	/// visit pokemon
	void VisitPokemon(CPokemon *pokemon);

	/// return the radius (this will be used in childview when setting the initial location of the pokemon) 
	double GetRadius() { return mRadius; }

private: 
	double mRadius; ///< when a pokemon is created, make sure the distance is correct from the center 
};

