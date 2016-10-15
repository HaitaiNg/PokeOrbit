/**
 * \file ChildView.h
 *
 * \author Haitai Ng 
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */ 


// ChildView.h : interface of the CChildView class
//

#include "Orbit.h"

#pragma once


/**
* The child window our program draws in.
*/
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private: 
	/// An object that describes our aquarium
	COrbit  mOrbit;

	//Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem; ///< pointer to grabbed item 

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

	double mTimeToDrawPokemon; ///< Time to draw a pokemon

	float mPointX; ///< x coordinate of click
	float mPointY; ///< y coordinate of click

	float mScale; ///< The scale gotten from COrbit
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);


	void DisplayRotationalPokemon(double time);
	
};

