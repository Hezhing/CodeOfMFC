#pragma once
#include "afxcmn.h"

// CManagerObject 对话框

class CManagerObject : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerObject)

public:
	CManagerObject(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManagerObject();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_list_ctr;

	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
