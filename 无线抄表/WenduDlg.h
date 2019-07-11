// WenduDlg.h : header file
//
#if !defined(AFX_WENDUDLG_H__96D11C98_3EAC_4EA8_8F5F_8A48EC6A1458__INCLUDED_)
#define AFX_WENDUDLG_H__96D11C98_3EAC_4EA8_8F5F_8A48EC6A1458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
#define NOPARITY 0 
#define ODDPARITY 1 
#define EVENPARITY 2 
#define ONESTOPBIT 0 
#define ONE5STOPBITS 1 
#define TWOSTOPBITS 2 
#define CBR_110  110 
#define CBR_300  300 
#define CBR_600  600 
#define CBR_1200  1200 
#define CBR_2400  2400 
#define CBR_4800  4800 
#define CBR_9600  9600 
#define CBR_14400 14400 
#define CBR_19200 19200 
#define CBR_38400 38400 
#define CBR_56000 56000 
#define CBR_57600 57600 
#define CBR_115200 115200 
#define CBR_128000 128000 
#define CBR_256000 256000
// CWenduDlg dialog

class CWenduDlg : public CDialog
{
// Construction
public:
	CString selStr;
	void GetCom();
	BOOL flag;
	CBrush m_brush;
	CString checksum(char *m_TXData);
	void GUO_OpenCK();
	CWenduDlg(CWnd* pParent = NULL);	// standard constructor
	HANDLE hCom;
	/*
	int wendu;
		int count;
		int flag;*/
	
// Dialog Data
	//{{AFX_DATA(CWenduDlg)
	enum { IDD = IDD_WENDU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWenduDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWenduDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBUTTON2_send();
	afx_msg void OnChangeEDIT3ZhengZongLiang();
	afx_msg void OnChangeEDIT4FuZhongLiang();
	afx_msg void OnChangeEDIT5ShunShi();
	afx_msg void OnChangeEDIT6Time();
	afx_msg void OnChangeEDIT3ZhengZongLiang2_Units();
	afx_msg void OnChangeEDIT4FuZhongLiang2_Units();
	afx_msg void OnChangeEDIT5ShunShi2_Units();
	afx_msg void OnChangeEDIT6_DianYa();
	virtual void OnCancel();
	afx_msg void OnChangeEDIT3receive();
	afx_msg void OnCancelMode();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WENDUDLG_H__96D11C98_3EAC_4EA8_8F5F_8A48EC6A1458__INCLUDED_)
