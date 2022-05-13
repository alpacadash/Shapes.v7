
// Shapes.7Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"
#include "pShapes.h"

#include <string>
#include <sstream>
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapes7Dlg 대화 상자



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT4, m_stTest);
	DDX_Control(pDX, IDC_RESULT, m_ResultOut);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapes7Dlg::OnCbnSelchangeCombo1)
//	ON_BN_CLICKED(IDOK, &CShapes7Dlg::OnBnClickedOk)
ON_BN_CLICKED(IDOK, &CShapes7Dlg::OnBnClickedOk)
ON_STN_CLICKED(IDC_PICTURE, &CShapes7Dlg::OnStnClickedPicture)
END_MESSAGE_MAP()


// CShapes7Dlg 메시지 처리기

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->InsertString(0, _T("Square"));
	pCombo->InsertString(1, _T("Rectangle"));
	pCombo->InsertString(2, _T("Circle"));
	pCombo->InsertString(3, _T("Triangle"));
	pCombo->InsertString(4, _T("Cube"));
	pCombo->InsertString(5, _T("Box"));
	pCombo->InsertString(6, _T("Cylinder"));
	pCombo->InsertString(7, _T("Prism"));
	pCombo->SetCurSel(0); // -1 for unselected
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
	pEdit4->SetWindowText(CString(_T("Side")));
	pEdit5->SetWindowText(CString(_T("")));
	pEdit6->SetWindowText(CString(_T("")));
	pEdit1->ShowWindow(SW_SHOW);
	pEdit2->ShowWindow(SW_HIDE);
	pEdit3->ShowWindow(SW_HIDE);

	// Picture control setup
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_PICTURE));
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);

	return TRUE;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CShapes7Dlg::OnCbnSelchangeCombo1()
{
	CComboBox* pCombo1 = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int x = pCombo1->GetCurSel(); // 0 for first item...
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_PICTURE));
	//{"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"}; 
	//^sample code to help with switch
	//6 is length/side, 9 is height, 8 is width, 10 is radius
	if (x == 0)
	{
		
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Side")));
		pEdit5->SetWindowText(CString(_T("")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	if (x == 1)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Length")));
		pEdit5->SetWindowText(CString(_T("Width")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	if (x == 2)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Radius")));
		pEdit5->SetWindowText(CString(_T("")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	if (x == 3)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Side")));
		pEdit5->SetWindowText(CString(_T("")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	if (x == 4)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Side")));
		pEdit5->SetWindowText(CString(_T("")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	if (x == 5)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		pEdit4->SetWindowText(CString(_T("Length")));
		pEdit5->SetWindowText(CString(_T("Height")));
		pEdit6->SetWindowText(CString(_T("Width")));
	}
	if (x == 6)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Radius")));
		pEdit5->SetWindowText(CString(_T("Height")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	if (x == 7)
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);
		pEdit4->SetWindowText(CString(_T("Length")));
		pEdit5->SetWindowText(CString(_T("Height")));
		pEdit6->SetWindowText(CString(_T("")));
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CShapes7Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int n = pCombo->GetCurSel(); // 0 for first item...

	CString mEdit1;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	pEdit1->GetWindowText(mEdit1); // copy control's text into an MFC string
	CString mEdit2;
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	pEdit2->GetWindowText(mEdit2); // copy control's text into an MFC string
	CString mEdit3;
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	pEdit3->GetWindowText(mEdit3); // copy control's text into an MFC string
	CEdit* pResult = reinterpret_cast<CEdit*>(GetDlgItem(IDC_RESULT));

	string first = CStringA(mEdit1); //used for length, side or radius
	string second = CStringA(mEdit2); //used for width or height
	string third = CStringA(mEdit3); //used for height
	//{"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"}; 
	//^sample code to help with switch
	vector<string> params;
	ostringstream sout;

	switch (n)
	{
	case 0:
	{
		params.push_back("Square");
		params.push_back(first.c_str());
		Square s(params);
		s.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 1:
	{
		params.push_back("Rectangle");
		params.push_back(first);
		params.push_back(second);
		comsc::Rectangle re(params);
		re.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 2:
	{
		params.push_back("Circle");
		params.push_back(first);
		Circle c(params);
		c.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 3:
	{
		params.push_back("Triangle");
		params.push_back(first);
		Triangle t(params);
		t.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 4:
	{
		params.push_back("Cube");
		params.push_back(first);
		Cube c(params);
		c.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 5:
	{
		params.push_back("Box");
		params.push_back(first);
		params.push_back(second);
		params.push_back(third);
		Box b(params);
		b.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 6:
	{
		params.push_back("Cylinder");
		params.push_back(first);
		params.push_back(second);
		Cylinder c(params);
		c.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 7:
	{
		params.push_back("Prism");
		params.push_back(first);
		params.push_back(second);
		Prism p(params);
		p.output(sout);
		pResult->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	}
}


void CShapes7Dlg::OnStnClickedPicture()
{
	// TODO: Add your control notification handler code here
}
