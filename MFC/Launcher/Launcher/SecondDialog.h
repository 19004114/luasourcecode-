#pragma once
#include "afxwin.h"


// SecondDialog dialog

class SecondDialog : public CDialog
{
	DECLARE_DYNAMIC(SecondDialog)

public:
	SecondDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~SecondDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString path;
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL PreTranslateMessage(MSG *pMsg);
	CEdit Edit_path;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton2();
};
