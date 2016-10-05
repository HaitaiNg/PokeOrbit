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

	/// Draw an object 
	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	/// Add an item to our collection 
	void Add(std::shared_ptr<CItem> item);

	/// Hit test on the orbit itself
	std::shared_ptr<CItem> HitTest(int x, int y);

private:
	/// All of the items to populate our orbit
	std::vector<std::shared_ptr<CItem> > mItems;
	double Radius = 500; 
};

