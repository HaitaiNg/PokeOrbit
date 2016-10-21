/**
 * \file Pokemon.h
 *
 * \author Haitai Ng 
 *
 *  Base class for all of our Pokemon. 
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

	/** Return true if an object is a pokemon
	* \return True */
	bool IsPokemon() { return true;  }

	/// The possible Pokemon types
	enum PokemonType {Blastoise, Charmeleon, Pikachu};
	
	/// Get the Pokemon type 
	PokemonType GetPokemonCaught() { return mType; }

	/// Determine the Pokemon type
	void DeterminePokemonType();

	/// Return the number of blastoise caught 
	double ReturnBlastoiseCount();

	/// Return the number of charmeleon caught
	double ReturnCharmeleonCount();

	/// Return the number of pikachu caught
	double ReturnPikachuCount(); 

protected:
	/// Constructor 
	CPokemon(COrbit * orbit, const std::wstring & filename, PokemonType type);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitPokemon(this); }

private: 
	/// The pokemon type, default is Pikachu 
	PokemonType mType = Pikachu; 

	/// Blastoise caught 
	long mBlastoiseCaught = 0; 

	/// Charmeleon caught
	long mCharmeleonCaught = 0; 

	/// Pikachu caught 
	long mPikachuCaught = 0; 
};

