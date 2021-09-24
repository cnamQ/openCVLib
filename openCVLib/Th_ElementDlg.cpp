// Th_Element.cpp: 구현 파일
//

#include "pch.h"
#include "openCVLib.h"
#include "Th_ElementDlg.h"
#include "afxdialogex.h"


// CTh_ElementDlg 대화 상자

IMPLEMENT_DYNAMIC(CTh_ElementDlg, CDialogEx)

CTh_ElementDlg::CTh_ElementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_THRESHOLD_ELEMENT, pParent)
{
	m_strTest.Format(_T("slider test"));
}

CTh_ElementDlg::~CTh_ElementDlg()
{
}

void CTh_ElementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_THRESHOLD_ABSOLUTE, m_slTEAbsolute);
	DDX_Control(pDX, IDC_STATIC_THRESHOLD_ABSOLUTE_VALUE, m_editAbsolute);
}


BEGIN_MESSAGE_MAP(CTh_ElementDlg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_THRESHOLD_ABSOLUTE, &CTh_ElementDlg::OnNMCustomdrawSliderThresholdAbsolute)
END_MESSAGE_MAP()


// CTh_ElementDlg 메시지 처리기

BOOL CTh_ElementDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	InitElement();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CTh_ElementDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	UINT nID = CWnd::FromHandle(pMsg->hwnd)->GetDlgCtrlID();

	switch (nID)
	{
	case IDC_SLIDER_THRESHOLD_ABSOLUTE:
		{
			CString str;
			int nPos = m_slTEAbsolute.GetPos();
			str.Format(_T("%d"), nPos);
			m_editAbsolute.SetWindowTextW(str);
		}
		break;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CTh_ElementDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnTimer(nIDEvent);
}


void CTh_ElementDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CTh_ElementDlg::InitElement()
{
	// Dlg에 추가되어있는 속성들의 초기 세팅을 한다.
	
	// Edit
	m_editAbsolute.SetWindowTextW(_T("0"));


	// Slider
	m_slTEAbsolute.SetRange(0, 255);
	m_slTEAbsolute.SetPos(128);
	m_slTEAbsolute.SetLineSize(5);
	m_slTEAbsolute.SetPageSize(5);

	
}

void CTh_ElementDlg::OnNMCustomdrawSliderThresholdAbsolute(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	*pResult = 0;
}

