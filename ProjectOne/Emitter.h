/**
 * \file Emitter.h
 *
 * \author Haitai Ng 
 *
 *  Emitter class. This class will randomly add objects to the screen. It is not derived from any other classes,
 * rather is compatible with CItem & COrbit. 
 */

#pragma once

class COrbit;
/**
 * Class that used to generate item randmonly.
 */
class CEmitter
{
public:

	CEmitter(COrbit *orbit);
	/// Delete defaut constructor
	CEmitter() = delete;
	
	virtual ~CEmitter();
	
	void Update(double elapsed);

private:
	/// The orbit this item is in
	COrbit *mOrbit;
	
	/// A generator decides when to generator a pokemon,
	double mPokemonEmitter;

	/// A generator decides when to generator a pokestop,
	double mPokestopEmitter;

	/// How many pokemon can be generated once
	int mPokemonNum;

	void EmitPokemon();
	void EmitPokestop();

	//CEmitter mEmitter; 
};

