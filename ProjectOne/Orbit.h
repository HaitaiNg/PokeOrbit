/**
 * \file Orbit.h
 *
 * \author Haitai Ng 
 *
 *  Class that represents our orbit. 
 */

#pragma once
#include <memory>
#include <vector> 

class CItem; 

/**
 * This will be the main class that represents our Orbit 
 */
class COrbit
{
public:
	COrbit();
	virtual ~COrbit();

	/// Draws the background and ash 
	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	/// Draws objects to fill the background
	void Draw(Gdiplus::Graphics * graphics);

	/// Add an item to our collection 
	void Add(std::shared_ptr<CItem> item);

	/// Hit test on the orbit itself
	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Move an item to the front of the list of items.
	void MoveToFront(std::shared_ptr<CItem> item);

	/// Handle updates for animation
	void Update(double elapsed);

private:

	/// Ash Ketchum image 
	std::unique_ptr<Gdiplus::Bitmap> mAshImage;

	/// All of the items to populate our orbit
	std::vector<std::shared_ptr<CItem> > mItems;
	float Radius = 500; 
};

