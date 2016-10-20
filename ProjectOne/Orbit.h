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

	/// Constructor 
	COrbit();
	
	/// Destructor 
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

	/** Add the pokeball and change the pokestop color when clicking*/
	void Click(float x, float y);

	/** Set the horizontal offset
	*/
	void SetXOffset(float width) { mXOffset = width; }

	/** Set the vertical offset
	*/
	void SetYOffset(float height) { mYOffset = height; }

	/** Get the horizontal offset
	* \return float
	*/
	float GetXOffset() { return mXOffset; }

	/** Get the vertical offset
	* \return float
	*/
	float GetYOffset() { return mYOffset; }

	/** Set the scale 
	* \param float
	*/
	void SetScale(float scale) { mScale = scale; }

	/** Get the scale
	* \return float
	*/
	float GetScale() { return mScale; }

	/** See if the item needs to be destroyed
	* \return bool
	*/
	bool Destroyed();

	/** See if a pokemon has been caught
	* \param item
	* \return item
	*/
	std::shared_ptr<CItem> PokemonCaught(std::shared_ptr<CItem> item);

	/* Determine which pokemon has been caught
	* \param item
	*/
	void DeterminePokemonCount(std::shared_ptr<CItem> item);

	/* Add pokeballs
	* \param num
	*/
	void AddPokeball(int num);
	

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

	/// horizontal offset 
	float mXOffset;

	/// vertical offset 
	float mYOffset;

	///scale 
	float mScale;

	/// pointer to an Emitter object 
	std::shared_ptr<CEmitter> mEmitter;

	/// Y Offset in pixels for each redraw of pokeball on left side of screen
	int mPokeballOffset;

	/// Number of blastoise
	double mBlastoise = 0 ;

	/// Number of charmelon 
	double mCharmeleon = 0; 

	/// Number of pikachu 
	double mPikachu = 0; 

	/// Number of pokeballs in inventory
	int mPokeballs = 3;

};

