// Bai6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bai6.h"
#include "Bai6Dlg.h"
#include "./Src/Utility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBai6Dlg dialog

CBai6Dlg::CBai6Dlg(CWnd* pParent /*=NULL*/)
	: CImgDialogBase( CBai6Dlg::IDD
	, CUtility::GetModulePath() + _T("VLTK2.jpg")
	, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBai6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CImgDialogBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_browser);
}

BEGIN_MESSAGE_MAP(CBai6Dlg, CImgDialogBase)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CBai6Dlg message handlers

BOOL CBai6Dlg::OnInitDialog()
{
	CImgDialogBase::OnInitDialog();

	m_browser.Navigate(L"http://launcher.game.zing.vn/vo-lam-mien-phi/launcher-news-062014.html", NULL, NULL, NULL, NULL);


	
	//SetWindowLong(m_hWnd, GWL_EXSTYLE, GetWindowLong(m_hWnd,GWL_EXSTYLE) ^ WS_EX_LAYERED);
	//SetLayeredWindowAttributes( RGB(255,0,255), 0, LWA_COLORKEY);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBai6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBai6Dlg::OnPaint()
{
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
		CImgDialogBase::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBai6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CBai6Dlg::PreTranslateMessage(MSG *pMsg)
{
	static bool mouse_down = false;
     static CRect MainRect;
     static CPoint point;
     switch(pMsg->message)
     {
     case WM_LBUTTONDOWN:
         //save current dialog’s rectangle
         GetWindowRect(&MainRect);
         //save current cursor coordinate
         point = pMsg->pt;
         ScreenToClient(&point);
         
         //change the sign
         mouse_down = true;
         break;
     case WM_LBUTTONUP:
         //stop the sign
         mouse_down = false;
         //gimme a standard cursor now!!
         break;
     case WM_MOUSEMOVE :
         if(mouse_down)
         {     
              //finally, move the window
              MoveWindow(    pMsg->pt.x - point.x,
                  //count the relative position
                       pMsg->pt.y - point.y,
                       MainRect.Width(), 
                     //if the width doesn’t change 
                       MainRect.Height(),
                     //if the height doesn’t change
                       TRUE);
         }
     }
     //The code ends here
     return CImgDialogBase::PreTranslateMessage(pMsg);
}
