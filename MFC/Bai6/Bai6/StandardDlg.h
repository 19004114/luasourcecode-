#pragma once

#include "StandardDialog.h"
#include "afxwin.h"
#include "explorer1.h"
#include "GdipButton.h"

#include "afxcmn.h"
#include "afxdtctl.h"


// StandardDlg dialog

class StandardDlg : public CStandardDialog
{
	DECLARE_DYNAMIC(StandardDlg)

public:
	StandardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~StandardDlg();


// Dialog Data
	enum { IDD = IDD_BAI6_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_browser;
	CGdipButton btn_TuyChon;
	CGdipButton btn_ThuLai;
	CGdipButton btn_HuongDan;
	CGdipButton btn_Fanpage;
	afx_msg void OnBnClickedButton1();
};