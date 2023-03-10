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
	DDX_Control(pDX, IDC_BUTTON4, btn_DangNhap);
}


BEGIN_MESSAGE_MAP(StandardDlg, CStandardDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &StandardDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &StandardDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


BOOL StandardDlg::OnInitDialog()
{
	CStandardDialog::OnInitDialog();

	btn_TuyChon.LoadStdImage(IDB_OPTION, _T("PNG"));
	btn_ThuLai.LoadStdImage(IDB_RESUME, _T("PNG"));
	btn_Thoat.LoadStdImage(IDB_EXIT, _T("PNG"));
	btn_DangNhap.LoadStdImage(IDB_PNG4, _T("PNG"));

	m_browser.Navigate(L"http://launcher.game.zing.vn/vo-lam-mien-phi/launcher-news-062014.html", NULL, NULL, NULL, NULL);
	
	return TRUE;
}
void StandardDlg::OnBnClickedButton1()
{
	SecondDialog dlg;
	dlg.DoModal();
}

void StandardDlg::OnBnClickedButton3()
{
	EndDialog(0);
}
