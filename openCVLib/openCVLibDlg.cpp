
// openCVLibDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "openCVLib.h"
#include "openCVLibDlg.h"
#include "afxdialogex.h"

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


// CopenCVLibDlg 대화 상자



CopenCVLibDlg::CopenCVLibDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPENCVLIB_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CopenCVLibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CopenCVLibDlg, CDialogEx)
//	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
ON_WM_TIMER()
ON_WM_DESTROY()
ON_BN_CLICKED(IDC_BUTTON_FILTER_ADAPTIVE_THRESHOLD, &CopenCVLibDlg::OnBnClickedButtonFilterAdaptiveThreshold)
ON_BN_CLICKED(IDC_BUTTON_FILTER_THRESHOLD, &CopenCVLibDlg::OnBnClickedButtonFilterThreshold)
ON_COMMAND(ID_MENUTOP_FILEOPEN, &CopenCVLibDlg::OnMenutopFileopen)
END_MESSAGE_MAP()


// CopenCVLibDlg 메시지 처리기

BOOL CopenCVLibDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if(!m_pDlg_ThElement)
	{
		m_pDlg_ThElement = new CTh_ElementDlg(this);
	}
	if(m_pDlg_ThElement)
	{
		m_pDlg_ThElement->Create(IDD_DIALOG_THRESHOLD_ELEMENT);
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

//void CopenCVLibDlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CopenCVLibDlg::OnPaint()
{
	//DisplayImage(IDC_STATIC_IMAGE_ORIGINAL, m_cvImage);

// 	if (IsIconic())
// 	{
// // 		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
// // 
// // 		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
// // 
// // 		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
// // 		int cxIcon = GetSystemMetrics(SM_CXICON);
// // 		int cyIcon = GetSystemMetrics(SM_CYICON);
// // 		CRect rect;
// // 		GetClientRect(&rect);
// // 		int x = (rect.Width() - cxIcon + 1) / 2;
// // 		int y = (rect.Height() - cyIcon + 1) / 2;
// // 
// // 		// 아이콘을 그립니다.
// // 		dc.DrawIcon(x, y, m_hIcon);
// 	}
// 	else
// 	{
// 		CDialogEx::OnPaint();
// 	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
//HCURSOR CopenCVLibDlg::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}



void CopenCVLibDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//////////////////////////////////////////////////////////////////////////
	// 확인용

	//////////////////////////////////////////////////////////////////////////

	CDialogEx::OnTimer(nIDEvent);
}


void CopenCVLibDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// 초기화 및 해제
	if(m_pDlg_ThElement)
	{
		delete m_pDlg_ThElement;
		m_pDlg_ThElement = nullptr;
	}

	if(m_pTargetIplImage)
	{
		delete m_pTargetIplImage;
		m_pTargetIplImage = nullptr;
	}

	if(m_pBitmapInfo)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = nullptr;
	}


	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}



void CopenCVLibDlg::OnBnClickedButtonFilterThreshold()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strTitle.Format(_T("Threshold"));
	//m_CvFunc.linkerTestFunc(m_strTitle);

	m_pDlg_ThElement->ShowWindow(SW_SHOW);

}


void CopenCVLibDlg::OnBnClickedButtonFilterAdaptiveThreshold()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
// 	m_strTitle.Format(_T("Adaptive Threshold"));
// 	m_CvFunc.linkerTestFunc(m_strTitle);


	CopyImage();
}

void CopenCVLibDlg::DisplayImage(int nID, Mat cvImage)
{
	m_pTargetIplImage = new IplImage(cvImage);


	if(m_pTargetIplImage != nullptr)
	{
		// IDC 픽쳐 컨트롤 DC 및 RECT 정의
		CWnd* pWnd_pictureControl = GetDlgItem(IDC_STATIC_IMAGE_ORIGINAL);
		CClientDC dcImageTraget(pWnd_pictureControl);
		RECT rcPicControl;	// right->width, bottom->height
		pWnd_pictureControl->GetClientRect(&rcPicControl);


		// 비트맵 선언 및 정의
		BITMAPINFO bitmapInfo;
		memset(&bitmapInfo, 0, sizeof(bitmapInfo));
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		bitmapInfo.bmiHeader.biWidth = m_pTargetIplImage->width;
		bitmapInfo.bmiHeader.biHeight = -m_pTargetIplImage->height;

		IplImage *tempImage = nullptr;

		if(m_pTargetIplImage->nChannels == 1)
		{
			tempImage = cvCreateImage(cvSize(m_pTargetIplImage->width, m_pTargetIplImage->height), IPL_DEPTH_8U, 3);
			cvCvtColor(m_pTargetIplImage, tempImage, CV_GRAY2BGR);
		}
		else if(m_pTargetIplImage->nChannels == 3)
		{
			tempImage = cvCloneImage(m_pTargetIplImage);
		}

		bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;

		dcImageTraget.SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(dcImageTraget.GetSafeHdc(), rcPicControl.left, rcPicControl.top, rcPicControl.right, rcPicControl.bottom,
						0, 0, tempImage->width, tempImage->height, tempImage->imageData,
						&bitmapInfo, DIB_RGB_COLORS, SRCCOPY);

		cvReleaseImage(&tempImage);

	}

	return;
}

void CopenCVLibDlg::DrawImage(Mat* cvImage, int nID)
{
	CClientDC dc(GetDlgItem(nID));
	CRect cr;

	GetDlgItem(nID)->GetClientRect(&cr);


	// 영상 비율 계산 및 반영
	float fImageRatio = float(cvImage->cols) / float(cvImage->rows);
	float fRectRatio = float(cr.right) / float(cr.bottom);
	float fScaleFactor;
	if(fImageRatio < fRectRatio)
	{
		fScaleFactor = float(cr.bottom) / float(cvImage->rows);	//TRACE("%f",fScaleFactor);
		int rightWithRatio = cvImage->cols * fScaleFactor;
		float halfOfDif = ((float)cr.right - (float)rightWithRatio) / (float)2;
		cr.left = halfOfDif;
		cr.right = rightWithRatio;
	}
	else
	{
		fScaleFactor = float(cr.right) / float(cvImage->cols);	//TRACE("%f",fScaleFactor);
		int bottomWithRatio = cvImage->rows * fScaleFactor;
		float halfOfDif = ((float)cr.bottom - (float)bottomWithRatio)/* / (float)4*/;
		cr.top = halfOfDif;
		cr.bottom = bottomWithRatio;
	}
	//////////////////////////////////////////////////////////////////////////

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
 
 	int nW = 0, nH =0;
 	nW = cr.Width();
 
 	float fImageW = cvImage->cols;
 	float fImageH = cvImage->rows;
 
 	nH =  nW / (fImageW / fImageH);
	
	// StretchDIBits() Image data 출력 함수이며, 크기 변형에 따른 꺠짐 방지까지 처리 해줌.
 	StretchDIBits(dc.GetSafeHdc(), 0, 0, nW, nH, 0, 0, cvImage->cols, cvImage->rows, cvImage->data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);

}


void CopenCVLibDlg::CreateBitMapInfo(int w, int h, int bpp)
{
	if(m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if(bpp == 8)
	{
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	}
	else
	{
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];
	}

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if(bpp == 8)
	{
		for(int i=0; i<=255; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = h;

	return;
}

void CopenCVLibDlg::OnMenutopFileopen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	char szFilter[] = "Image (*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.gif;*.jpg;*.png | All Files(*.*)|*.*||";


/*	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, AfxGetMainWnd());*/

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Image (*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.gif;*.jpg;*.png | All Files(*.*)|*.*||"), AfxGetMainWnd());

	if(dlg.DoModal() == IDOK)
	{		
		m_strFilePath = dlg.GetPathName();

		CT2CA pszString(m_strFilePath);
		std::string strPath(pszString);
		
		m_cvImage = imread(strPath/*string(m_strFilePath)*/);

		CreateBitMapInfo(m_cvImage.cols, m_cvImage.rows, m_cvImage.channels() * 8);		// color bbp는 8로..
		
		
		// 선택한 채널에 따라 해당 ID 전달
		int nID = IDC_STATIC_IMAGE_ORIGINAL;
		DrawImage(&m_cvImage, nID);

		//Invalidate(true);
	}
}

void CopenCVLibDlg::CopyImage()		// 테스트 구성...
{
	int nID = IDC_STATIC_IMAGE_FILTER;	
	m_cvImage.copyTo(m_cvSubImage);
	// Threshold 진행해보자.
	//cvtColor(m_cvImage, m_cvSubImage, CV_RGB2GRAY);
// 
// 	cv::flip(m_cvSubImage, m_cvSubImage, 0);	// 0: y filp.. cvtColor 왜 y 반전되어있지?
// 	imshow("Threshold", m_cvSubImage);

	threshold(m_cvImage, m_cvSubImage, 100, 255, THRESH_OTSU);
	imshow("Threshold", m_cvSubImage);

//	DrawImage(&m_cvSubImage, nID);


}


