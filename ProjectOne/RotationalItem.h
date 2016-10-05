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

protected:
	///constructor 
	CRotationalItem(COrbit * orbit, const std::wstring & filename, double speedx, double speedy);

};

