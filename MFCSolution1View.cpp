
// MFCSolution1View.cpp : implementation of the CMFCSolution1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSolution1.h"
#endif

#include "MFCSolution1Doc.h"
#include "MFCSolution1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSolution1View

IMPLEMENT_DYNCREATE(CMFCSolution1View, CView)

BEGIN_MESSAGE_MAP(CMFCSolution1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCSolution1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCSolution1View construction/destruction

CMFCSolution1View::CMFCSolution1View()
{
	// TODO: add construction code here

}

CMFCSolution1View::~CMFCSolution1View()
{
}

BOOL CMFCSolution1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCSolution1View drawing

void CMFCSolution1View::OnDraw(CDC* /*pDC*/)
{
	CMFCSolution1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCSolution1View printing


void CMFCSolution1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCSolution1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSolution1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSolution1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCSolution1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCSolution1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCSolution1View diagnostics

#ifdef _DEBUG
void CMFCSolution1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSolution1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSolution1Doc* CMFCSolution1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSolution1Doc)));
	return (CMFCSolution1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSolution1View message handlers
