// Change.cpp : 实现文件
//

#include "stdafx.h"
#include "ZHN_TEST2_1.h"
#include "Change.h"
#include "afxdialogex.h"


// CChange 对话框

IMPLEMENT_DYNAMIC(CChange, CDialog)

CChange::CChange(CWnd* pParent /*=NULL*/)
	: CDialog(CChange::IDD, pParent)
{
	r_state=false;
	m_rid = _T("");
}

CChange::~CChange()
{
}

void CChange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChange, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CChange::OnBnClickedButton1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CChange::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CChange::OnCbnDropdownCombo2)
END_MESSAGE_MAP()


// CChange 消息处理程序


void CChange::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowText(r_id);
	((CEdit *)GetDlgItem(IDC_EDIT2))->GetWindowText(r_name);
	((CEdit *)GetDlgItem(IDC_COMBO1))->GetWindowText(r_sex);
	((CEdit *)GetDlgItem(IDC_EDIT3))->GetWindowText(r_card);
	((CEdit *)GetDlgItem(IDC_COMBO2))->GetWindowText(r_level);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->GetWindowText(r_time);
	((CEdit *)GetDlgItem(IDC_EDIT4))->GetWindowText(r_like);
	((CEdit *)GetDlgItem(IDC_EDIT5))->GetWindowText(r_remarks);
	
	if (r_id=="" || r_name=="" || r_card=="" || r_sex=="" || r_level=="")
	{
		MessageBox("请完善你所要查询的信息，带*号为必填项！");
	}
	else
	{
		CDialog::OnOK();
		r_state=true;
	}
}


void CChange::OnCbnDropdownCombo1()
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


void CChange::OnCbnDropdownCombo2()
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
