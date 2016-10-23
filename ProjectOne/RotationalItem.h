/**
 * \file RotationalItem.h
 *
 * \author Haitai Ng 
 *
 * 
 */

#pragma once
#include "Item.h"

/**
 * Rotational Item class derived from CItem
 * Moves all items that move in a circle around the orbit
 */
class CRotationalItem :
	public CItem
{
public:

	/// Default constructor disabled 
	CRotationalItem() = delete;

	/// Virtual destructor 
	virtual ~CRotationalItem();

	/// Copy constructor (disabled) 
	CRotationalItem(const CRotationalItem &) = delete;

	/// Set the speed of the item for the object 
	virtual void SetItemSpeed() {}

	/// Handle updates in time of our fish 
	virtual void Update(double elapsed);

	/// Set the speed of our Pokemon 
	virtual void SetSpeed(double minX, double maxX, double mThreshold, double maxY);

	/// Return the radius so that all pokemon are properly centered around ash 
	virtual double SetRadius();

	/// Return the angle 
	virtual double SetAngle();

	/// Return the x position
	double ReturnXPosition();

	/// Return the y position 
	double ReturnYPosition();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitRotationalItem(this); }

protected:
	///constructor 
	CRotationalItem(COrbit * orbit, const std::wstring & filename);

private:
	/// Object speed in the X direction
	double mSpeedRatio; 

	/// The elapsed time since construction
	double mTime = 0;

	/// Compute random range; 
	double mRadius;

	///Get the angle
	double mAngle;

	/// x position 
	double mX;

	/// y position 
	double mY;

	/// sine coordinate
	double sn; 
	
	/// cos coordinate
	double cs;

	/// new X coordinate
	double newX;

	/// new Y coordinate 
	double newY; 

};

