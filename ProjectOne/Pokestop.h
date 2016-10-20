/**
 * \file Pokestop.h
 *
 * \author Haitai Ng 
 *
 * Class that represents a pokestop
 */

#pragma once
#include <memory>
#include "RotationalItem.h"
#include "Orbit.h"


/**
 * Pokestop class derived from rotational item class holds attributes of pokestop
 */
class CPokestop :
	public CRotationalItem
{
public:

	/// Constructor 
	CPokestop::CPokestop(COrbit *orbit);

	/// Destructor 
	virtual ~CPokestop();

	/// Load 
	void Load(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);

	/// Constructor disabled 
	CPokestop() = delete;

	/// Copy Constructor (disabled) 
	CPokestop(const CPokestop &) = delete;
	
	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitPokestop(this); }

	/** 
	* Draw an object
	*/
	void Draw(Gdiplus::Graphics *graphics) override;

	void Update(double elapsed) override;
	
	/** 
	*	Set member variable mClicked to true
	*/
	void IsClicked();

	/**
	* Is this object a pokestop?
	* \return bool. This is a pokestop 
	*/
	bool IsPokeStop() { return true; }

	/**
	* Is the pokestop clicked?
	* \return bool. This is a pokestop
	*/
	virtual bool State() { return mClicked; };
	virtual bool NotActive() { return mNotActive; };
private:
	
	/// The image of the loaded rocket
	std::unique_ptr<Gdiplus::Bitmap> mClickedImage;

	/// Determines if pokestop has been clicked on
	bool mClicked = false;
	bool mNotActive = false;
	long long mTime;    ///< Last time we read the timer
	long long mStartTime;    ///< Start time when pokestop is clicked

	double mLife = 0; ///< time before pokestop disappears 
};

