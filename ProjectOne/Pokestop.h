/**
 * \file Pokestop.h
 *
 * \author Haitai Ng 
 *
 * 
 */

#pragma once
#include <memory>
#include "RotationalItem.h"


/**
 * 
 */
class CPokestop :
	public CRotationalItem
{
public:

	/// Constructor 
	CPokestop::CPokestop(COrbit *orbit);


	/// Destructor 
	virtual ~CPokestop();

	/// Constructor disabled 
	CPokestop() = delete;

	/// Copy Constructor (disabled) 
	CPokestop(const CPokestop &) = delete;
	
};

