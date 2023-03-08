// StandardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Launcher.h"
#include "StandardDlg.h"
#include "StandardDialog.h"

// StandardDlg dialog

IMPLEMENT_DYNAMIC(StandardDlg, CStandardDialog)

StandardDlg::StandardDlg(CWnd* pParent /*=NULL*/)
	: CStandardDialog(StandardDlg::IDD, RGB(0, 255, 0), pParent)
{

}

StandardDlg::~StandardDlg()
{
}

void StandardDlg::DoDataExchange(CDataExchange* pDX)
{
	CStandardDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StandardDlg, CStandardDialog)
END_MESSAGE_MAP()


BOOL StandardDlg::OnInitDialog()
{
	CStandardDialog::OnInitDialog();
	
	return TRUE;
}