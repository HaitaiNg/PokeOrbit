/**
 * \ file LinearMovement.h
 *
 * \ author Quan Zhou
 *
 * An intermediate class between CItem and CPokeBall
 */

#pragma once
#include "Item.h"
/**
 * Class that describe a linear movement.
 */
class CLinearMovement :
	public CItem
{
public:
	/// Default constructor (disabled)
	CLinearMovement() = delete;

	/// Copy constructor (disabled)
	CLinearMovement(const CLinearMovement &) = delete;

	/// Virtual Destructor 
	virtual ~CLinearMovement();

	/// Update the animation 
	virtual void Update(double elapsed);

	/// Destroy an object 
	bool DestroyObject();

	//void Draw(Gdiplus::Graphics *graphics) override;

	/// Set the speed of an object 
	void SetSpeed(double speedx, double speedy) { mSpeedX = speedx, mSpeedY = speedy; };

protected:

	/// Constructor 
	CLinearMovement(COrbit * orbit, const std::wstring & filename);

private: 
	///Linear movement speed in the X direction.
	double mSpeedX;

	///Linear movement speed in the Y direction.
	double mSpeedY;

	/// Positon x 
	double mPosX = 0;

	/// Position y 
	double mPosY = 0;

	///maxium radius 
	double mRadius; 

};

