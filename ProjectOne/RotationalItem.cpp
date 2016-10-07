/**
 * \file RotationalItem.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "RotationalItem.h"


CRotationalItem::CRotationalItem(COrbit *orbit, const std::wstring &filename):
	CItem(orbit, filename)
{
}


CRotationalItem::~CRotationalItem()
{
}

/// Handle updates for animation
/// \param elapsed The time since the last update
void CRotationalItem::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

}

