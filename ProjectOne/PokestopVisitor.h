/**
 * \file PokestopVisitor.h
 *
 * \author Kevin Scott
 *
 * Visitor class for pokestops
 */

#pragma once
#include "ItemVisitor.h"

 /**
 * Visitor class to pokestop to change aspects of pokestop item
 */
class CPokestopVisitor :
	public CItemVisitor
{
public:
	CPokestopVisitor();
	virtual ~CPokestopVisitor();

	/** Visit a CPokestop object
	* \param pokestop Pokestop we are visiting */
	virtual void VisitPokestop(CPokestop *pokestop) override;
};

