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
	void VisitPokemon(CPokemon *pokemon) override;

	/** Have any blastoise been caught? 
	* \return double  */
	double GetBlastoiseCount() { return mBlastoiseCaught; }

	/** Have any charmeleon been caught?
	* \return double  */
	double GetCharmeleonCount() { return mCharmeleonCaught; }

	/** Have any Pikachu been caught?
	* \return double  */
	double GetPikachuCount() { return mPikachuCaught; }

private: 

	double mBlastoiseCaught; ///< number of blastoise that have been caught 
	double mCharmeleonCaught; ///< number of charmeleon that have been caught 
	double mPikachuCaught; ///< number of pikachu that have been caught 
};

