// Search.cpp : 实现文件
//

#include "stdafx.h"
#include "ZHN_TEST3_1.h"
#include "Search.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include"UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
#include "ZHN_TEST3_1Doc.h"

// CSearch 对话框

IMPLEMENT_DYNAMIC(CSearch, CDialog)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CSearch::IDD, pParent)
{

}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearch, CDialog)
	ON_BN_CLICKED(IDOK, &CSearch::OnBnClickedOk)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CSearch::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CSearch::OnCbnDropdownCombo2)
END_MESSAGE_MAP()


// CSearch 消息处理程序


void CSearch::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowText(q_id);
	((CEdit *)GetDlgItem(IDC_EDIT2))->GetWindowText(q_name);
	((CEdit *)GetDlgItem(IDC_COMBO1))->GetWindowText(q_sex);
	((CEdit *)GetDlgItem(IDC_EDIT3))->GetWindowText(q_card);
	((CEdit *)GetDlgItem(IDC_COMBO2))->GetWindowText(q_level);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->GetWindowText(q_time);
	((CEdit *)GetDlgItem(IDC_EDIT4))->GetWindowText(q_like);
	((CEdit *)GetDlgItem(IDC_EDIT5))->GetWindowText(q_remarks);
	
	if (q_id=="" || q_name=="" || q_card=="" || q_sex=="" )
	{
		MessageBox("请完善你所要查询的信息，带*号为必填项！");
	}
	else
	{
		CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
		CZHN_TEST3_1Doc* pdoc = (CZHN_TEST3_1Doc*)pMainFrame->GetActiveDocument();
		CMedicListView* listView = (CMedicListView*)pMainFrame->m_sWnd1.GetPane(1,0);
		CUserTreeView* treeList = (CUserTreeView*)pMainFrame->m_sWnd.GetPane(0,0);
		treeList->Updata();
		listView->Updata();
		CDialog::OnOK();
		q_state=true;
	}
}


void CSearch::OnCbnDropdownCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CComboBox* box;
	box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int count = box->GetCount();

	if (count<1)
	{
		box->AddString("男");
		box->AddString("女");
	}
}


void CSearch::OnCbnDropdownCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	CComboBox* box;
	box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	int count=box->GetCount();    
	
	if (count<1)
	{
		box->AddString("高级");
		box->AddString("中级");
		box->AddString("低级");
 	}
}
