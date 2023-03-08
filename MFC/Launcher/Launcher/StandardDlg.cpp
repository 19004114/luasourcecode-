// StandardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Launcher.h"
#include "StandardDlg.h"
#include "StandardDialog.h"
#include "explorer1.h"

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
	DDX_Control(pDX, IDC_EXPLORER1, m_browser);
	DDX_Control(pDX, IDC_BUTTON1, btn_TuyChon);
	DDX_Control(pDX, IDC_BUTTON2, btn_ThuLai);
	DDX_Control(pDX, IDC_BUTTON3, btn_Thoat);
}


BEGIN_MESSAGE_MAP(StandardDlg, CStandardDialog)
END_MESSAGE_MAP()


BOOL StandardDlg::OnInitDialog()
{
	CStandardDialog::OnInitDialog();

	btn_TuyChon.LoadStdImage(IDB_PNG1, _T("PNG"));
	btn_ThuLai.LoadStdImage(IDB_PNG2, _T("PNG"));
	btn_Thoat.LoadStdImage(IDB_PNG3, _T("PNG"));

	m_browser.Navigate(L"http://launcher.game.zing.vn/vo-lam-mien-phi/launcher-news-062014.html", NULL, NULL, NULL, NULL);
	
	return TRUE;
}