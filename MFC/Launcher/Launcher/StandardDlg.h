#pragma once

#include "StandardDialog.h"
#include "afxwin.h"


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
};