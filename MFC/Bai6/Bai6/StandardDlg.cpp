// StandardDlg.cpp : implementation file
//

#include "stdafx.h"
// VC6
#if defined(_MSC_VER) && _MSC_VER == 1200

#ifndef ULONG_PTR
#define ULONG_PTR unsigned long*
#endif

#include <Specstrings.h>
#include <gdiplus.h>#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

// VS2005
#else

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

#endif

#include "Bai6.h"
#include "StandardDlg.h"
#include "StandardDialog.h"
#include "SecondDialog.h"

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
	DDX_Control(pDX, IDC_BUTTON3, btn_HuongDan);
	DDX_Control(pDX, IDC_BUTTON4, btn_Fanpage);
}


BEGIN_MESSAGE_MAP(StandardDlg, CStandardDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &StandardDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


BOOL StandardDlg::OnInitDialog()
{
	CStandardDialog::OnInitDialog();

	btn_TuyChon.LoadStdImage(IDB_PNG4, _T("PNG"));
	btn_ThuLai.LoadStdImage(IDB_PNG3, _T("PNG"));
	btn_HuongDan.LoadStdImage(IDB_PNG2, _T("PNG"));
	btn_Fanpage.LoadStdImage(IDB_PNG1, _T("PNG"));

	m_browser.Navigate(L"http://launcher.game.zing.vn/vo-lam-mien-phi/launcher-news-062014.html", NULL, NULL, NULL, NULL);
	

	return TRUE;
}
void StandardDlg::OnBnClickedButton1()
{
	SecondDialog dlg;
	dlg.DoModal();
}
