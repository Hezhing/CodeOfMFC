// Search.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_TEST2_1.h"
#include "Search.h"
#include "afxdialogex.h"


// CSearch �Ի���

IMPLEMENT_DYNAMIC(CSearch, CDialog)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CSearch::IDD, pParent)
{
	q_state=false;
}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearch, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CSearch::OnBnClickedButton1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CSearch::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CSearch::OnCbnDropdownCombo2)
END_MESSAGE_MAP()


// CSearch ��Ϣ�������


void CSearch::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox("����������Ҫ��ѯ����Ϣ����*��Ϊ�����");
	}
	else
	{
		CDialog::OnOK();
		q_state=true;
	}
}


void CSearch::OnCbnDropdownCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CComboBox* box;
	box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int count = box->GetCount();

	if (count<1)
	{
		box->AddString("��");
		box->AddString("Ů");
	}
}


void CSearch::OnCbnDropdownCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CComboBox* box;
	box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	int count=box->GetCount();    
	
	if (count<1)
	{
		box->AddString("�߼�");
		box->AddString("�м�");
		box->AddString("�ͼ�");
 	}
}
