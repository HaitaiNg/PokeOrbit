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

protected:
	/// Constructor 
	CPokemon(COrbit * orbit, const std::wstring & filename);

	/// Destructor 
	virtual ~CPokemon();

	/// Handle updates in time of our fish 
	void Update(double elapsed);

	/// Set the speed of our Pokemon 
	void SetSpeed(double minX, double maxX, double minY, double maxY);

	/// Set the range for our Pokemon 

private: 
	/// Pokemon speed in the X direction
	double mSpeedX;

	/// Pokemon speed in the Y direction
	double mSpeedY;

	/// Object movement speed in the X direction 
	double mObjectSpeedX; 

	/// Object movement speed in the Y direction
	double mObjectSpeedY; 

	/// The elapsed time since construction
	double mTime = 0;
};

