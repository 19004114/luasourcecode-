// Bai6Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "explorer1.h"
#include "GdipButton.h"


// CBai6Dlg dialog
class CBai6Dlg : public CDialog
{
// Construction
public:
	CBai6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BAI6_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CGdipButton btn_TuyChon;
	CExplorer1 m_browser;
};
