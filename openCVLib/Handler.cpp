#include "pch.h"
#include "Handler.h"

#include "openCVLib.h"
#include "openCVLibDlg.h"

cvFunc::cvFunc()
{
	// ������
}
cvFunc::~cvFunc()
{
	// �Ҹ���
}


void cvFunc::linkerTestFunc(CString str)
{
	str += " Test";
	int nTest = 0;
	AfxMessageBox(str);
	return;
}