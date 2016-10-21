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

	///Constructor 
	CEmitter(COrbit *orbit);

	/// Delete defaut constructor
	CEmitter() = delete;
	
	/// Virtal destructor 
	virtual ~CEmitter();
	
	/// Update the animation 
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

	/// Create Pokemon 
	void EmitPokemon();

	/// Create Pokestop 
	void EmitPokestop();

	
};

