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

	

	virtual ~CLinearMovement();

	void Update(double elapsed);

	//void Draw(Gdiplus::Graphics *graphics) override;

	void SetSpeed(double speedx, double speedy) { mSpeedX = speedx, mSpeedY = speedy; };

protected:

	CLinearMovement(COrbit * orbit, const std::wstring & filename);

private: 
	///Linear movement speed in the X direction.
	double mSpeedX;

	///Linear movement speed in the Y direction.
	double mSpeedY;

	double mPosX = 0;
	double mPosY = 0;


};

