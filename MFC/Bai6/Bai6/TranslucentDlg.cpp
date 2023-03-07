// TranslucentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bai6.h"
#include "TranslucentDlg.h"
#include "TranslucentDialog.h"
#include "StandardDlg.h"


// TranslucentDlg dialog

IMPLEMENT_DYNAMIC(TranslucentDlg, CTranslucentDialog)

TranslucentDlg::TranslucentDlg(LPCTSTR lpszFile, CWnd* pParent /*=NULL*/)
	: CTranslucentDialog(TranslucentDlg::IDD, lpszFile, pParent)
{
}
TranslucentDlg::TranslucentDlg(UINT nImgID, LPCTSTR lpszType/* = _T("PNG")*/, HINSTANCE hResourceModule/* = NULL*/, CWnd* pParent /*=NULL*/)
	: CTranslucentDialog(TranslucentDlg::IDD, nImgID, lpszType, hResourceModule, pParent)
{
}

TranslucentDlg::~TranslucentDlg()
{
}

void TranslucentDlg::DoDataExchange(CDataExchange* pDX)
{
	CTranslucentDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TranslucentDlg, CTranslucentDialog)
END_MESSAGE_MAP()

CStandardDialog* TranslucentDlg::CreateStandardDialog()
{
	return ::new StandardDlg(this);
}

void TranslucentDlg::OnInitChildrenWnds()
{
}

// TranslucentDlg message handlers
