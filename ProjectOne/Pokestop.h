/**
 * \file Pokestop.h
 *
 * \author Haitai Ng 
 *
 * 
 */

#pragma once
#include <memory>
#include "RotationalItem.h"


/**
 * 
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
	
	/** 
	*	Set member variable mClicked to true
	*/
	void IsClicked() { mClicked = true; }
private:

	/// The image of the loaded rocket
	std::unique_ptr<Gdiplus::Bitmap> mClickedImage;

	/// Determines if pokestop has been clicked on
	bool mClicked = false;

};

