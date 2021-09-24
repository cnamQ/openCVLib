#pragma once


using namespace std;


// CTh_ElementDlg 대화 상자

class CTh_ElementDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTh_ElementDlg)

public:
	CTh_ElementDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTh_ElementDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_THRESHOLD_ELEMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()

private:		// 변수 선언 - Dlg 관련
	CString m_strTest;
	CSliderCtrl m_slTEAbsolute;
	CStatic m_editAbsolute;


public:		// Setter,Getter 함수 선언
	void InitElement();


public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnNMCustomdrawSliderThresholdAbsolute(NMHDR *pNMHDR, LRESULT *pResult);
	
	
	
};
