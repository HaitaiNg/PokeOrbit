/**
 * \file Pokemon.h
 *
 * \author Haitai Ng 
 *
 *  
 */

#pragma once
#include "Item.h"


/**
 * Base class for a Pokemon 
 * This applies to all of the Pokemon, but not the Pokestops
 * items in the orbit. 
 */
class CPokemon :
	public CItem
{
public:

	
	/// Default constructor (disabled) 
	CPokemon() = delete; 

	/// Copy Constructor (disabled) 
	CPokemon(const CPokemon &) = delete; 

protected:
	/// Constructor 
	CPokemon(COrbit * orbit, const std::wstring & filename);

	/// Destructor 
	virtual ~CPokemon();

	/// Handle updates in time of our fish 
	void Update(double elapsed);

private: 
	/// Pokemon speed in the X direction
	double mSpeedX;

	/// Pokemon speed in the Y direction
	double mSpeedY;

};

