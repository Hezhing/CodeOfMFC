// add.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_TEST2_1.h"
#include "add.h"
#include "afxdialogex.h"


// Cadd �Ի���

IMPLEMENT_DYNAMIC(Cadd, CDialog)

Cadd::Cadd(CWnd* pParent /*=NULL*/)
	: CDialog(Cadd::IDD, pParent)
{
	a_state = false;
	m_aid = _T("");
}

Cadd::~Cadd()
{
}

void Cadd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_aid);
}


BEGIN_MESSAGE_MAP(Cadd, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Cadd::OnBnClickedButton1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &Cadd::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &Cadd::OnCbnDropdownCombo2)
END_MESSAGE_MAP()


// Cadd ��Ϣ�������


void Cadd::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox("��*��Ϊ�����");
	}
	else
	{
		CDialog::OnOK();
		a_state=true;
	}

}

Cadd add;

void Cadd::OnCbnDropdownCombo1()
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


void Cadd::OnCbnDropdownCombo2()
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
