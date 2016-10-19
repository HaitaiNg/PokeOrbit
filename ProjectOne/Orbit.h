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
#include "ItemVisitor.h"
#include "Emitter.h"
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

	/// Accepts a visitor for the collection
	void Accept(CItemVisitor * visitor);

	void Click(float x, float y);

	void SetXOffset(float width) { mXOffset = width; }
	void SetYOffset(float height) { mYOffset = height; }
	float GetXOffset() { return mXOffset; }
	float GetYOffset() { return mYOffset; }

	void SetScale(float scale) { mScale = scale; }
	float GetScale() { return mScale; }

	/** See if the item needs to be destroyed */
	bool Destroyed();

	/** See if a pokemon has been caught */
	std::shared_ptr<CItem> PokemonCaught(std::shared_ptr<CItem> item);


private:
	/// Ash Ketchum image 
	std::unique_ptr<Gdiplus::Bitmap> mAshImage;

	/// Pokeball Image 
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// Blastoise Image 
	std::unique_ptr<Gdiplus::Bitmap> mBlastoiseImage; 
	/// Charmeleon Image 
	std::unique_ptr<Gdiplus::Bitmap> mCharmeleonImage; 
	/// PikachuImage 
	std::unique_ptr<Gdiplus::Bitmap> mPikachuImage; 


	/// All of the items to populate our orbit
	std::vector<std::shared_ptr<CItem> > mItems;
	float Radius = 500; 

	//Pointer to object that will be destroyed 
	std::shared_ptr<CItem> mObject; 

	float mXOffset;
	float mYOffset;

	float mScale;

	std::shared_ptr<CEmitter> mEmitter;

	/// Number of pokeballs in inventory
	int mPokeballs = 13;

	/// Y Offset in pixels for each redraw of pokeball on left side of screen
	int mPokeballOffset;

	/// Number of pokemon caught 
	double mPokemonCaught = 0 ;
};

