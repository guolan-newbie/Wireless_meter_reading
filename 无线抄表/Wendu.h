// Wendu.h : main header file for the WENDU application
//

#if !defined(AFX_WENDU_H__DC4ECC07_EAE6_472C_BE08_A4E60A180E48__INCLUDED_)
#define AFX_WENDU_H__DC4ECC07_EAE6_472C_BE08_A4E60A180E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWenduApp:
// See Wendu.cpp for the implementation of this class
//

class CWenduApp : public CWinApp
{
public:
	static CString  Checksum();
	CWenduApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWenduApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWenduApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WENDU_H__DC4ECC07_EAE6_472C_BE08_A4E60A180E48__INCLUDED_)
