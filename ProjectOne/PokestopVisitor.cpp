/**
 * \file PokestopVisitor.cpp
 *
 * \author Kevin Scott
 */

#include "stdafx.h"
#include "PokestopVisitor.h"
#include "Pokestop.h"

/**
 * Constructor
 */
CPokestopVisitor::CPokestopVisitor()
{
}


/**
 * Destructor
 */
CPokestopVisitor::~CPokestopVisitor()
{
}

/**
 * Overriden visit pokestop function to change state when clicked on.
 * \param pokestop 
 */
void CPokestopVisitor::VisitPokestop(CPokestop * pokestop)
{
	pokestop->IsClicked();
}
