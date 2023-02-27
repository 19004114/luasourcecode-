// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include "PictureWindow.h"
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestDlg dialog




CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
	, Edit_path(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Edit_path);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_OPEN, &CTestDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &CTestDlg::OnBnClickedSave)
	ON_WM_ERASEBKGND()
	ON_EN_CHANGE(IDC_EDIT2, &CTestDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint()
{
	CBitmap backg;
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
    CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestDlg::OnBnClickedOpen()
{	
	UpdateData(TRUE);
	CFileDialog cfile(TRUE);
	if (cfile.DoModal())
	{
		Edit_path = cfile.GetPathName();
	}
	else
	{
		MessageBox(_T("Loi"),_T("Thong Bao"),MB_OK);
	}
	
	CStdioFile file;
	file.Open(Edit_path, CFile::modeRead | CFile::typeText);
	  
	
	//file.ReadString(edt_result1);
	file.Close();
	UpdateData(FALSE);
	
}
int show(lua_State* L);
int show(lua_State* L)
{
	MessageBox(NULL,_T("OK"),_T("Thong Bao"),MB_OK);
	return 1;
}


void CTestDlg::OnBnClickedSave()
{
	CStringA s2( Edit_path );
	const char* c = s2;
	
	lua_State* L = lua_open(0);
    lua_baselibopen(L);
    lua_strlibopen(L);
    lua_pushcfunction(L, show);
    lua_setglobal(L, "show");
    lua_dofile(L, c);
    lua_getglobal(L, "Main");
    lua_call(L, 0, 0);
}

BOOL CTestDlg::OnEraseBkgnd(CDC* pDC)
{
	return CDialog::OnEraseBkgnd(pDC);
}

void CTestDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
