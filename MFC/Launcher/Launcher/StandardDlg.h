#pragma once

#include "StandardDialog.h"
#include "afxwin.h"
#include "explorer1.h"
#include "GdipButton.h"
#include "SecondDialog.h"
#include "afxcmn.h"


// StandardDlg dialog

class StandardDlg : public CStandardDialog
{
	DECLARE_DYNAMIC(StandardDlg)

public:
	StandardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~StandardDlg();


// Dialog Data
	enum { IDD = IDD_LAUNCHER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	void WorkerThreadProc();
    void ProgressUpdate ( LPCTSTR szIEMsg, LPCTSTR szCustomMsg,
                          const int nPercentDone );
	CExplorer1 m_browser;
	CGdipButton btn_TuyChon;
	CGdipButton btn_ThuLai;
	CGdipButton btn_Thoat;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	CGdipButton btn_DangNhap;
	afx_msg void OnBnClickedButton2();
	CProgressCtrl m_progress;
	CStatic m_Status;
};