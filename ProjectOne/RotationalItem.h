/**
 * \file RotationalItem.h
 *
 * \author Haitai Ng 
 *
 * 
 */

#pragma once
#include "Item.h"

class CRotationalItem :
	public CItem
{
public:
	CRotationalItem() = delete;

	virtual ~CRotationalItem();

	/// Copy constructor (disabled) 
	CRotationalItem(const CRotationalItem &) = delete;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed);

protected:
	///constructor 
	CRotationalItem(COrbit * orbit, const std::wstring & filename);

	/// Set the speed of the item for the object 
	virtual void SetItemSpeed() {} 

private:
	double mSpeedX; 
	double mSpeedY; 

};

