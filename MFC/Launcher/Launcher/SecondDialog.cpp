// SecondDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Launcher.h"
#include "SecondDialog.h"


// SecondDialog dialog

IMPLEMENT_DYNAMIC(SecondDialog, CDialog)

SecondDialog::SecondDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SecondDialog::IDD, pParent)
{

}

SecondDialog::~SecondDialog()
{
}

void SecondDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_path);
}


BEGIN_MESSAGE_MAP(SecondDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &SecondDialog::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RADIO1, &SecondDialog::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &SecondDialog::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON2, &SecondDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// SecondDialog message handlers

void SecondDialog::OnBnClickedButton1()
{
	CStdioFile file;
	UpdateData(TRUE);
	CFileDialog cfile(TRUE);
	if (cfile.DoModal())
	{
		path = cfile.GetPathName();
		file.Open(path, CFile::modeRead | CFile::typeText);
		SetDlgItemText(IDC_EDIT1, path);
	}
	UpdateData(FALSE);
}

void SecondDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);

	CBrush myb;
	myb.CreateSolidBrush(RGB(255,217,111));
	dc.FillRect(&rect,&myb);

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
	}
	else
	{
		CDialog::OnPaint();
	}
}

BOOL SecondDialog::PreTranslateMessage(MSG *pMsg)
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
     return CDialog::PreTranslateMessage(pMsg);
}

HBRUSH SecondDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_BTN:
	case CTLCOLOR_DLG:
		return CreateSolidBrush(RGB(255,217,111));
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(TEXT_COLOR);
		return CreateSolidBrush(RGB(255,217,111));
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

BOOL SecondDialog::OnInitDialog()
{
	CDialog::OnInitDialog();


    CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);  
	CButton* pBtn = (CButton*) GetDlgItem(IDC_3D);
    pBtn->EnableWindow(0);
	CheckRadioButton(IDC_RADIO3,IDC_RADIO4,IDC_RADIO3);  
	return TRUE;
}

void SecondDialog::OnBnClickedRadio1()
{
	CButton* pBtn = (CButton*) GetDlgItem(IDC_3D);
    pBtn->EnableWindow(0);
}

void SecondDialog::OnBnClickedRadio2()
{
	CButton* pBtn = (CButton*) GetDlgItem(IDC_3D);
    pBtn->EnableWindow(1);
}

void SecondDialog::OnBnClickedButton2()
{
	OnOK();
}
