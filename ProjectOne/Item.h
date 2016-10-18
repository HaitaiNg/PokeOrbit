/**
 * \file Item.h
 *
 * \author Haitai Ng 
 *
 *  Base class for any item in our aquarium 
 */


#pragma once

#include <string>
#include <memory>
#include "ItemVisitor.h"

class COrbit;

/**
* Base class for any item in our orbit. 
*/
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;
	
	/// Destructor 
	virtual ~CItem();

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/** Set the item location
	* \param x X location
	* \param y Y location */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	//! Draw this item
	//! \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics *graphics);

	//! Set the image 
	//! \param file 
	void SetImage(const std::wstring & file);

	/** Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Get the orbit this item is in
	/// \returns Orbit pointer
	COrbit *GetOrbit() { return mOrbit; }

	/// Get the display width of the item
	/// \return Width
	virtual int GetWidth() const { return mItemImage->GetWidth(); }

	/// Get the display height of the item
	/// \return Height
	virtual int GetHeight() const { return mItemImage->GetHeight(); }

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) {};

	/**
	* Is this object ready to be destroyed?
	* \returns bool. The default is false
	*/
	virtual bool DestroyObject() { return false; }

	/**
	* Is this object a pokeball?
	* \return bool. The default is false
	*/
	virtual bool IsPokeball() { return false; }

	/** 
	* Is this object a pokemon?
	* \return bool. The default is false 
	*/
	virtual bool IsPokemon() { return false; }

	/**
	* Is this object a pokestop?
	* \return bool. The default is false
	*/
	virtual bool IsPokeStop() { return false; }

protected:
	///Citem type
	/// \param orbit, filename 
	CItem(COrbit *orbit, const std::wstring &filename);

private:
	/// The aquarium this item is contained in
	COrbit   *mOrbit;

	// Item location in the aquarium
	double   mX = 0;     ///< X location for the center of the item
	double   mY = 0;     ///< Y location for the center of the item

	/// The image of this Item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// The file for this item
	std::wstring mFile;

	
};