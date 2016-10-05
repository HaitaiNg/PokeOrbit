/**
 * \file RotationalItem.cpp
 *
 * \author Haitai Ng 
 */

#include "stdafx.h"
#include "RotationalItem.h"


CRotationalItem::CRotationalItem(COrbit *orbit, const std::wstring &filename, double speedx, double speedy):
	CItem(orbit, filename)
{
}


CRotationalItem::~CRotationalItem()
{
}


