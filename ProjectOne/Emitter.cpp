/**
 * \file Emitter.cpp
 *
 * \author Quan Zhou 
 */


#include "stdafx.h"
#include "Emitter.h"
#include "Orbit.h"
#include "Blastoise.h"
#include "Charmeleon.h"
#include "Pokestop.h"
#include "Pikachu.h"


/// Minimum time to generate a pokemon.
const double PokemonTimeMin = 1;
/// Maximum time to generate a pokemon.
const double PokemonTimeMax = 5;

/// Minimum time to generate a pokestop.
const double PokestopTimeMin = 10;
/// Maximum time to generate a pokestop.
const double PokestopTimeMax = 60;

/// Minimum number of pokemon.
const int PokemonNumMin = 1;
/// Maximum number of pokemon.
const int PokemonNumMax = 4;


/**
 * Constructor 
 * \param orbit 
 */
CEmitter::CEmitter(COrbit *orbit) : mOrbit(orbit)
{
}


/**
 * Destructor 
 */
CEmitter::~CEmitter()
{
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CEmitter::Update(double elapsed)
{
	if (mPokemonEmitter > 0)
	{
		mPokemonEmitter -= elapsed;
	}
	else
	{
		EmitPokemon();
		mPokemonEmitter = PokemonTimeMin + ((double)rand() / RAND_MAX) * (PokemonTimeMax - PokemonTimeMin);
	}

	if (mPokestopEmitter > 0)
	{
		mPokestopEmitter -= elapsed;
	}
	else
	{
		EmitPokestop();
		mPokestopEmitter = PokestopTimeMin + ((double)rand() / RAND_MAX) * (PokestopTimeMax - PokestopTimeMin);
	}
}

/**
 * Generate Pokemon 
 */
void CEmitter::EmitPokemon()
{
	mPokemonNum = rand() % PokemonNumMax; 

	std::shared_ptr<CRotationalItem> pokemon;

	switch (mPokemonNum)
	{
	case 1:
		pokemon = std::make_shared<CCharmeleon>(mOrbit);
		break;
	case 2:
		pokemon = std::make_shared<CBlastoise>(mOrbit);
		break;
	case 3:
		pokemon = std::make_shared<CPikachu>(mOrbit);
		break;
	default: 
		break;
	}
	if (pokemon != nullptr)
	{
		mOrbit->Add(pokemon);
		mX = pokemon->ReturnXPosition();
		mY = pokemon->ReturnYPosition();
		pokemon->SetLocation(mX, mY);
	}
}

/**
* Generate Pokemon
*/
void CEmitter::EmitPokestop()
{
	std::shared_ptr<CPokestop> pokestop;
	pokestop = std::make_shared<CPokestop>(mOrbit);
	mOrbit->Add(pokestop);
	mX = pokestop->ReturnXPosition();
	mY = pokestop->ReturnYPosition();
	pokestop->SetLocation(mX, mY);
}
