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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std; 
using namespace Gdiplus;

/// Initial fish X location
const int InitialX = 0;

/// Initial fish Y location
const int InitialY = 0;

/**
* Constructor
*/
CChildView::CChildView()
{
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

	mOrbit.OnDraw(&graphics, rect.Width(), rect.Height());

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

	mGrabbedItem = mOrbit.HitTest(point.x, point.y);
	if (mGrabbedItem != nullptr)
	{
		// We grabbed something
		// Move it to the front
		mOrbit.MoveToFront(mGrabbedItem);
		Invalidate();
	}
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
