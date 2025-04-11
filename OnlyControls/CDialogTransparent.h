#pragma once
#include <afxdialogex.h>

/*
* CDialogTransparent
* ͸���Ի������
*/
class CDialogTransparent 
	: public CDialogEx
{
	DECLARE_DYNAMIC(CDialogTransparent)

public:
	CDialogTransparent();   // ��׼���캯��
	CDialogTransparent(UINT nIDTemplate, CWnd* pParent = NULL);
	CDialogTransparent(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	virtual ~CDialogTransparent();

protected:
	virtual BOOL PreTranslateMessage(MSG* pMsg) override;
	virtual BOOL OnInitDialog() override;

	DECLARE_MESSAGE_MAP()
};

