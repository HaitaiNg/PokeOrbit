/**
 * \file ItemVisitor.h
 *
 * \author Haitai Ng 
 *
 *  Item visitor base class 
 */

#pragma once

/// Forward references to all item types 

class CRotationalItem; ///< forward reference to CRotationalItem
class CPokemon; ///< forward reference to CPokemon
class CPokestop;  ///< forward reference to CPokestop 
class CBlastoise; ///< forward reference to CBlastoise 
class CCharmeleon;  ///< forward reference to CCharmeleon
class CPikachu;  ///< forward reference to CPikachu


/**
 * Item visitor base class 
 */
class CItemVisitor
{
public:

	/// Constructor 
	CItemVisitor();

	/// Destructor 
	virtual ~CItemVisitor();

	/** Visit a CRotationalItem object
	* \param rotationalItem RotationalItem we are visiting */
	virtual void VisitRotationalItem(CRotationalItem *rotationalItem) {}

	/** Visit a CPokemon object
	* \param pokemon Pokemon we are visiting */
	virtual void VisitPokemon(CPokemon *pokemon) {}

	/** Visit a CPokestop object
	* \param pokestop Pokestop we are visiting */
	virtual void VisitPokestop(CPokestop *pokestop) {}

	/** Visit a Blastoise object
	* \param blastoise Blastoise we are visiting */
	virtual void VisitBlastoise(CBlastoise *blastoise) {}

	/** Visit a Charmeleon object
	* \param charmeleon Charmeleon we are visiting */
	virtual void VisitCharmeleon(CCharmeleon *charmeleon) {}

	/** Visit a Pikachu object
	* \param blastoise Blastoise we are visiting */
	virtual void VisitPikachu(CPikachu *pikachu) {}

};

