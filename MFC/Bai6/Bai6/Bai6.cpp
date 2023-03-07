// Test.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Bai6.h"
#include "Bai6.h"
#include "TranslucentDlg.h"
#include "StandardDlg.h"
#include "TranslucentDialog.h"
#include "StandardDialog.h"
#include <gdiplus.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBai6App

BEGIN_MESSAGE_MAP(CBai6App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CBai6App construction

CBai6App::CBai6App()
{
}

ULONG_PTR gdiplusToken;
CBai6App theApp;

BOOL CBai6App::InitInstance()
{
	CWinApp::InitInstance();
	AfxEnableControlContainer();

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	TranslucentDlg dlg(_T("res\\VLTK3.png"));
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}

int CBai6App::ExitInstance()
{
	Gdiplus::GdiplusShutdown(gdiplusToken);

	return CWinApp::ExitInstance();
}