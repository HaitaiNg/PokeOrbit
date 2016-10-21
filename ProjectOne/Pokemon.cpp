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
* \param orbit The orbit we are in
* \param filename Filename for the image we use
* \param type The pokemon type (blastoise, charmeleon, pikachu 
*/
CPokemon::CPokemon(COrbit *orbit, const std::wstring &filename, PokemonType type) :
	CRotationalItem(orbit, filename)
{
	///mType is equal to the type of the Pokemon 
	mType = type; 
}

/**
 * Destructor 
 */
CPokemon::~CPokemon()
{
}

/**
* Determine Pokemon Type
*/
void CPokemon::DeterminePokemonType()
{
	/// If a pokemon is a blastoise 
	if (mType == Blastoise)
	{
		mBlastoiseCaught++; ///< increment blastoise count 
	}
 	
	/// If a pokemon is a charmeleon
	if (mType == Charmeleon)
	{
		mCharmeleonCaught++; ///< increment charmeleon count 
	}

	/// If a pokemon is a pikachu 
	if (mType == Pikachu)
	{
		mPikachuCaught++; ///< increment pikachu count 
	}  

}


/**
 * Determine whether the caught pokemon is a blastoise 
 * \returns double The amount of blastoise caught 
 */
double CPokemon::ReturnBlastoiseCount()
{
	DeterminePokemonType();
	return mBlastoiseCaught; 
}

/**
* Determine whether the caught pokemon is a charmeleon
* \returns double The amount of charmeleon caught
*/
double CPokemon::ReturnCharmeleonCount()
{
	DeterminePokemonType();
	return mCharmeleonCaught;
}

/**
* Determine whether the caught pokemon is a pikachu
* \returns double The amount of pikachu caught
*/
double CPokemon::ReturnPikachuCount()
{
	DeterminePokemonType();
	return mPikachuCaught;
}