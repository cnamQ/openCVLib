// FormViewTest.cpp: 구현 파일
//

#include "pch.h"
#include "openCVLib.h"
#include "FormViewTest.h"


// CFormViewTest

IMPLEMENT_DYNCREATE(CFormViewTest, CFormView)

CFormViewTest::CFormViewTest()
	: CFormView(IDD_CFormViewTest)
{

}

CFormViewTest::~CFormViewTest()
{
}

void CFormViewTest::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewTest, CFormView)
END_MESSAGE_MAP()


// CFormViewTest 진단

#ifdef _DEBUG
void CFormViewTest::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormViewTest::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewTest 메시지 처리기
