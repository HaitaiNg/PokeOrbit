/**
 * \file ChildView.cpp
 *
 * \author Haitai Ng 
 */


// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"
#include "Orbit.h"

#include "Item.h"
#include "RotationalItem.h"
#include "Pokemon.h"
#include "Blastoise.h"
#include "Charmeleon.h"
#include "Pikachu.h"
#include "Pokestop.h"
#include "PokeBall.h"
#include "PokestopVisitor.h"
#include <algorithm>

using namespace Gdiplus;
using namespace std; 


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std; 
using namespace Gdiplus;

/// Initial fish X location
const int InitialX = 0;

/// Initial fish Y location
const int InitialY = 0;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
* Constructor
*/
CChildView::CChildView()
{
	srand((unsigned int)time(nullptr)); //< random number generator 
}

/**
* Destructor
*/
CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()



/** This function is called before the window is created.
* \param cs A structure with the window creation parameters
* \returns TRUE
*/
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

/** This function is called to draw in the window.
*
* This function is called in response to a drawing message
* whenever we need to redraw the window on the screen.
* It is responsible for painting the window.
*/
void CChildView::OnPaint() 
{
	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC); // Create GDI+ graphics context

	CRect rect;
	GetClientRect(&rect);

	/// Draw the background and ash 
	mOrbit.OnDraw(&graphics, rect.Width(), rect.Height());

	/// Draw an object 
	mOrbit.Draw(&graphics);

	/// Start the timer 
	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	/// Everytime we draw we determine how much time has elapsed since the last time we draw. 
	mOrbit.Update(elapsed);
}


/**
* Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \returns FALSE
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE; 
}

/**
* Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	mScale = mOrbit.GetScale();
	mPointX = (point.x - mOrbit.GetXOffset()) * (1 / mScale);
	mPointY = (point.y - mOrbit.GetYOffset()) * (1 / mScale);

	mGrabbedItem = mOrbit.HitTest(mPointX, mPointY);
	if (mGrabbedItem != nullptr)
	{
		// We grabbed something
		// Move it to the front
		mOrbit.MoveToFront(mGrabbedItem);
		Invalidate();

		// Create a visitor to change pokestop color to purple
		CPokestopVisitor visitor;
		mGrabbedItem->Accept(&visitor);

	}

	/// Draw Pokemon at random intervals ********************THIS NEEDS TO BE FIXED 
	DisplayRotationalPokemon(10);
	mOrbit.Click(point.x, point.y);
	


}

/**
* Called when the left mouse button is released
* \param nFlags Flags associated with the mouse button release
* \param point Where the button was pressed
*/
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnLButtonUp(nFlags, point);
}

/**
* Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnMouseMove(nFlags, point);
}

/**
* Handle timer events
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(); 
	CWnd::OnTimer(nIDEvent);

}


/**
 *  Display the rotatinal pokemon 
 * \param time 
 */
void CChildView::DisplayRotationalPokemon(double time)
{

	
	if (time > 0)
	{
		/// to place image at origin use: x = -image->GetWidth() / 4 , y = -image->GetHeight() / 4 

		///Pokestop Image is here 
		auto pokestop = make_shared<CPokestop>(&mOrbit);
		mOrbit.Add(pokestop);
		Invalidate();

		auto blastoise = make_shared<CBlastoise>(&mOrbit);
		mOrbit.Add(blastoise);
		Invalidate();

		auto charmeleon = make_shared<CCharmeleon>(&mOrbit);
		mOrbit.Add(charmeleon);
		Invalidate();
		
		/**
		auto pikachu = make_shared<CPikachu>(&mOrbit);
		mOrbit.Add(pikachu);
		Invalidate();
		*/ 
		 
	}

	
}