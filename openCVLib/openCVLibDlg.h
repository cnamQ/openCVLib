
// openCVLibDlg.h: 헤더 파일
//

#pragma once

#include "Handler.h"
#include "Th_ElementDlg.h"
#include <string>

#include "windows.h"

using namespace std;
using namespace cv;

// CopenCVLibDlg 대화 상자
class CopenCVLibDlg : public CDialogEx
{
// 생성입니다.
public:
	CopenCVLibDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCVLIB_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.



private:
	// class 객체 선언 부분
	cvFunc m_CvFunc;			// Handler class
	CTh_ElementDlg* m_pDlg_ThElement = nullptr;
	
	Mat m_cvImage;
	Mat m_cvSubImage;

	IplImage* m_pIplImage;
	IplImage* m_pTargetIplImage;
	IplImage* m_pSubImage;
	BITMAPINFO* m_pBitmapInfo;

	CString m_strTitle;
	CString m_strFilePath;	


public:
	void DisplayImage(int nID, Mat cvImage);
	void CreateBitMapInfo(int w, int h, int bpp);
	void DrawImage(Mat* cvImage, int nID);

	void CopyImage();


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
//	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
//	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonFilterAdaptiveThreshold();
	afx_msg void OnBnClickedButtonFilterThreshold();
	afx_msg void OnMenutopFileopen();
};


