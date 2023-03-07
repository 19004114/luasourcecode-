#pragma once
#include "TranslucentDialog.h"
#include "explorer1.h"

// TranslucentDlg dialog

class TranslucentDlg : public CTranslucentDialog
{
	DECLARE_DYNAMIC(TranslucentDlg)

public:
	TranslucentDlg(LPCTSTR lpszFile, CWnd* pParent = NULL);
	TranslucentDlg(UINT nImgID, LPCTSTR lpszType = _T("PNG"), HINSTANCE hResourceModule = NULL, CWnd* pParent = NULL);   // standard constructor
	virtual ~TranslucentDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };
	virtual CStandardDialog* CreateStandardDialog();
	virtual void OnInitChildrenWnds();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
};
