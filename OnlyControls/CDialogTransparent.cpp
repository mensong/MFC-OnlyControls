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
		// �ڶԻ����ʼ����������OnInitDialog����������´��룺
		// 1. ���ô��ڷֲ�����
		DWORD dwExStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		SetWindowLong(m_hWnd, GWL_EXSTYLE, dwExStyle | WS_EX_LAYERED);

		// 2. ����͸��ɫΪ����ɫ��R=0, G=255, B=0������������ɫ��͸��
		SetLayeredWindowAttributes(RGB(0, 255, 0), 255, LWA_COLORKEY);
	}

	return ret;
}

BOOL CDialogTransparent::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_PAINT)
	{
		if (pMsg->hwnd == GetSafeHwnd()) //ֻ͸���Ի��򣬲�͸���ؼ�		
		{
			// 3. ���ƴ��ڱ���Ϊ͸��ɫ����ɫ��
			// ��OnPaint��OnEraseBkgnd�������ɫ����
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