// StandardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Launcher.h"
#include "StandardDlg.h"
#include "StandardDialog.h"
#include "explorer1.h"
#include "BindStatusCallback.h"

// StandardDlg dialog
static UINT gThreadProc ( void* pv );

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
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_Status, m_Status);
}


BEGIN_MESSAGE_MAP(StandardDlg, CStandardDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &StandardDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &StandardDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


BOOL StandardDlg::OnInitDialog()
{
	CStandardDialog::OnInitDialog();

	m_progress.SetRange ( 0, 100 );

	btn_TuyChon.LoadStdImage(IDB_OPTION, _T("PNG"));
	btn_ThuLai.LoadStdImage(IDB_RESUME, _T("PNG"));
	btn_Thoat.LoadStdImage(IDB_EXIT, _T("PNG"));
	btn_DangNhap.LoadStdImage(IDB_PNG4, _T("PNG"));

	m_browser.Navigate(L"http://launcher.game.zing.vn/vo-lam-mien-phi/launcher-news-062014.html", NULL, NULL, NULL, NULL);
	
	CWinThread* pWorkerThread;
	UpdateData();
	pWorkerThread = AfxBeginThread ( gThreadProc, this,
                                     THREAD_PRIORITY_NORMAL, 0, 
                                     CREATE_SUSPENDED );
	if ( NULL != pWorkerThread )
        {
        g_fAbortDownload = 0;
        pWorkerThread->ResumeThread();
        }
    else
        {
        AfxMessageBox ( _T("Couldn't create worker thread!"), MB_ICONERROR );
        }

	return TRUE;
}

UINT gThreadProc ( void* pv )
{
StandardDlg* pDlg = (StandardDlg*) pv;

    pDlg->WorkerThreadProc();

    return 0;
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

void StandardDlg::WorkerThreadProc()
{
CCallback callback;
HRESULT   hr;
CString   sURL, sFile;
	
    callback.m_pDlg = this;

    sURL = "https://download.microsoft.com/download/8/4/A/84A35BF1-DAFE-4AE8-82AF-AD2AE20B6B14/directx_Jun2010_redist.exe";
    sFile = "directx9.exe";

    hr = URLDownloadToFile ( NULL,      // ptr to ActiveX container
                             sURL,      // URL to get
                             sFile,     // file to store data in
                             0,         // reserved
                             &callback  // ptr to IBindStatusCallback
                           );
	

    if ( SUCCEEDED(hr) )
        {
        AfxMessageBox ( _T("Download completed successfully!"), 
                        MB_ICONINFORMATION );
		m_Status.SetWindowTextW(L"Tai xuong thanh cong");
        }
    else
        {
        LPTSTR lpszErrorMessage;
        CString sMsg;

        if ( FormatMessage ( FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                              FORMAT_MESSAGE_FROM_SYSTEM | 
                              FORMAT_MESSAGE_IGNORE_INSERTS,
                            NULL, hr, 
                            MAKELANGID ( LANG_NEUTRAL, SUBLANG_DEFAULT ),
                            (LPTSTR) &lpszErrorMessage, 0, NULL ))
            {
            sMsg.Format ( _T("Download failed.  Error = 0x%08lX\n\n%s"),
                          (DWORD) hr, lpszErrorMessage );

            LocalFree ( lpszErrorMessage );
            }
        else
            {
            sMsg.Format ( _T("Download failed.  Error = 0x%08lX\n\nNo message available."),
                          (DWORD) hr );
            }

        AfxMessageBox ( sMsg );
        }
}

void StandardDlg::ProgressUpdate ( LPCTSTR szIEMsg,
                                       LPCTSTR szCustomMsg,
                                       const int nPercentDone )
{
    ASSERT ( nPercentDone >= 0  &&  nPercentDone <= 100 );
	m_Status.SetWindowTextW(L"Dang tai xuong");

    m_progress.SetPos ( nPercentDone );
}
