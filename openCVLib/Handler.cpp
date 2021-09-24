#include "pch.h"
#include "Handler.h"

#include "openCVLib.h"
#include "openCVLibDlg.h"

cvFunc::cvFunc()
{
	// 持失切
}
cvFunc::~cvFunc()
{
	// 社瑚切
}


void cvFunc::linkerTestFunc(CString str)
{
	str += " Test";
	int nTest = 0;
	AfxMessageBox(str);
	return;
}