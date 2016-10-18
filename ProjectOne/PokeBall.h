/**
* \ file PokeBall.h
*
* \ author Quan Zhou
* 
* Class that describe a pokeballl
*/

#pragma once
#include "LinearMovement.h"
#include "Item.h"

/**
 * implement a pokeball
 */
class CPokeBall :
	public CLinearMovement
{
public:
	CPokeBall(COrbit * orbit);

	/// Default constructor (disabled)
	CPokeBall() = delete;

	/// Copy constructor (disabled)
	CPokeBall(const CPokeBall &) = delete;


	virtual ~CPokeBall();
};

