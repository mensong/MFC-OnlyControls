// CDlgTest.cpp: 实现文件
//

#include "pch.h"
#include "OnlyControls.h"
#include "CDlgTest.h"


// CDlgTest 对话框

IMPLEMENT_DYNAMIC(CDlgTest, CDialogTransparent)

CDlgTest::CDlgTest(CWnd* pParent /*=nullptr*/)
	: CDialogTransparent(IDD_DIALOG1, pParent)
{

}

CDlgTest::~CDlgTest()
{
}

void CDlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogTransparent::DoDataExchange(pDX);
}


BOOL CDlgTest::OnInitDialog()
{
	__super::OnInitDialog();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgTest, CDialogTransparent)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTest::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTest::OnBnClickedButton2)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgTest 消息处理程序

void CDlgTest::OnBnClickedButton1()
{
	AfxMessageBox(_T("ok"));
}

void CDlgTest::OnBnClickedButton2()
{
	DestroyWindow();
}

void CDlgTest::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogTransparent::OnPaint()
}
