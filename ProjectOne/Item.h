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

	virtual void Draw(Gdiplus::Graphics *graphics);

	virtual bool HitTest(int x, int y);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

protected:
	CItem(COrbit *orbit, const std::wstring &filename);

private:
	/// The aquarium this item is contained in
	COrbit   *mOrbit;

	// Item location in the aquarium
	double   mX = 0;     ///< X location for the center of the item
	double   mY = 0;     ///< Y location for the center of the item

	/// The image of this Item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

};