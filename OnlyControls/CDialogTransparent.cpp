#include "CDialogTransparent.h"

IMPLEMENT_DYNAMIC(CDialogTransparent, CDialogEx)

CDialogTransparent::CDialogTransparent()
	: CDialogEx()
{

}

CDialogTransparent::CDialogTransparent(UINT nIDTemplate, CWnd* pParent /*= nullptr*/)
	: CDialogEx(nIDTemplate, pParent)
{
}

CDialogTransparent::CDialogTransparent(LPCTSTR lpszTemplateName, CWnd* pParentWnd /*= nullptr*/)
	: CDialogEx(lpszTemplateName, pParentWnd)
{
}

CDialogTransparent::~CDialogTransparent()
{

}

BOOL CDialogTransparent::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	if (ret)
	{
		// 在对话框初始化函数（如OnInitDialog）中添加以下代码：
		// 1. 设置窗口分层属性
		DWORD dwExStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		SetWindowLong(m_hWnd, GWL_EXSTYLE, dwExStyle | WS_EX_LAYERED);

		// 2. 设置透明色为纯绿色（R=0, G=255, B=0），并启用颜色键透明
		SetLayeredWindowAttributes(RGB(0, 255, 0), 255, LWA_COLORKEY);
	}

	return ret;
}

BOOL CDialogTransparent::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_PAINT)
	{
		if (pMsg->hwnd == GetSafeHwnd()) //只透明对话框，不透明控件		
		{
			// 3. 绘制窗口背景为透明色（绿色）
			// 在OnPaint或OnEraseBkgnd中填充绿色背景
			CDC* pDC = GetDC();
			CRect rect;
			GetClientRect(&rect);
			pDC->FillSolidRect(rect, RGB(0, 255, 0));
			ReleaseDC(pDC);
		}
	}

	return __super::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(CDialogTransparent, CDialogEx)
END_MESSAGE_MAP()