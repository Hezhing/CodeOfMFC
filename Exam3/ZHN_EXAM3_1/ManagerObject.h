#pragma once
#include "afxcmn.h"

// CManagerObject �Ի���

class CManagerObject : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerObject)

public:
	CManagerObject(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManagerObject();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_list_ctr;

	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
