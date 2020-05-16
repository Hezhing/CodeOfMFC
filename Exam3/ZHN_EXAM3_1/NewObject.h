#pragma once
#include "MainFrm.h"
#include "UserListView.h"
#include "UserTreeView.h"

// CNewObject �Ի���

class CNewObject : public CDialogEx
{
	DECLARE_DYNAMIC(CNewObject)

public:
	CNewObject(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewObject();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	float PerMoney;
	int R;
	int G;
	int B;
	int index;
	afx_msg void OnBnClickedOk();
	void ModifyObj(int index,CString name,float PerMoney,int R,int G,int B);
};
