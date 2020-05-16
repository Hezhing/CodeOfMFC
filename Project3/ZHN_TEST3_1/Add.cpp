// Add.cpp : 实现文件
//

#include "stdafx.h"
#include "ZHN_TEST3_1.h"
#include "Add.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include"UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
#include "ZHN_TEST3_1Doc.h"


// CAdd 对话框

IMPLEMENT_DYNAMIC(CAdd, CDialog)

CAdd::CAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CAdd::IDD, pParent)
{
	a_state = false;
	m_aid = _T("");
}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_aid);
}


BEGIN_MESSAGE_MAP(CAdd, CDialog)
	ON_BN_CLICKED(IDOK, &CAdd::OnBnClickedOk)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CAdd::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CAdd::OnCbnDropdownCombo2)
END_MESSAGE_MAP()


// CAdd 消息处理程序


void CAdd::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowText(a_id);
	((CEdit *)GetDlgItem(IDC_EDIT2))->GetWindowText(a_name);
	((CEdit *)GetDlgItem(IDC_COMBO1))->GetWindowText(a_sex);
	((CEdit *)GetDlgItem(IDC_EDIT3))->GetWindowText(a_card);
	((CEdit *)GetDlgItem(IDC_COMBO2))->GetWindowText(a_level);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->GetWindowText(a_time);
	((CEdit *)GetDlgItem(IDC_EDIT4))->GetWindowText(a_like);
	((CEdit *)GetDlgItem(IDC_EDIT5))->GetWindowText(a_remarks);

	if (a_id=="" || a_name=="" || a_card=="" || a_sex=="" || a_level=="")
	{
		MessageBox("带*号为必填项！");
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
		a_state=true;
		
	}
	
}



void CAdd::OnCbnDropdownCombo1()
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


void CAdd::OnCbnDropdownCombo2()
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
