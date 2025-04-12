
// OnlyControlsDlg.h: 头文件
//

#pragma once
#include "afxdialogex.h"


// COnlyControlsDlg 对话框
class COnlyControlsDlg : public CDialogEx
{
// 构造
public:
	COnlyControlsDlg(CWnd* pParent = nullptr);	// 标准构造函数
	~COnlyControlsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ONLYCONTROLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	class CDlgTest* m_pDlg;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
