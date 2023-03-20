// Test.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Launcher.h"
#include "TranslucentDlg.h"
#include "StandardDlg.h"
#include "TranslucentDialog.h"
#include "StandardDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLauncherApp

BEGIN_MESSAGE_MAP(CLauncherApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLauncherApp construction

CLauncherApp::CLauncherApp()
{
}

ULONG_PTR gdiplusToken;
CLauncherApp theApp;
LONG g_fAbortDownload;

BOOL CLauncherApp::InitInstance()
{
	CWinApp::InitInstance();
	AfxEnableControlContainer();

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	//TranslucentDlg dlg(_T("res\\VLTK3.png"));
	TranslucentDlg dlg(IDB_BG, _T("PNG"), AfxGetResourceHandle());
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

int CLauncherApp::ExitInstance()
{
	Gdiplus::GdiplusShutdown(gdiplusToken);

	return CWinApp::ExitInstance();
}