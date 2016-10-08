/**
 * \file PokemonVisitor.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "PokemonVisitor.h"
#include "Pokemon.h"


/**
 * Constructor 
 */
CPokemonVisitor::CPokemonVisitor()
{
}


/**
 * Destructor 
 */
CPokemonVisitor::~CPokemonVisitor()
{
}


/**
 * Visit a Pokemon object 
 * \param pokemon The Pokemon we are visiting 
 */
void CPokemonVisitor::VisitPokemon(CPokemon *pokemon)
{
	///** Help: This is the code I would like to implement. However pokemon is being treated as an Item.  

	///mRadius = pokemon->ReturnRadius(); 

	/// I speculate that the reason this is not working is because the constructor for CPokemon accepts two parameters, as opposed to one

}
