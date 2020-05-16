#pragma once
#include "MainFrm.h"
#include "UserListView.h"
#include "UserTreeView.h"

// CNewObject 对话框

class CNewObject : public CDialogEx
{
	DECLARE_DYNAMIC(CNewObject)

public:
	CNewObject(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewObject();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
