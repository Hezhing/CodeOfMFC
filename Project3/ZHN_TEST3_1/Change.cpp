// Change.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_TEST3_1.h"
#include "Change.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include"UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
#include "ZHN_TEST3_1Doc.h"


// CChange �Ի���

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
	ON_BN_CLICKED(IDOK, &CChange::OnBnClickedOk)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CChange::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CChange::OnCbnDropdownCombo2)
END_MESSAGE_MAP()


// CChange ��Ϣ��������


void CChange::OnBnClickedOk()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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
		MessageBox("����������Ҫ��ѯ����Ϣ����*��Ϊ�����");
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
		r_state=true;
	}
}



void CChange::OnCbnDropdownCombo1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CComboBox* box;
	box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int count = box->GetCount();

	if (count<1)
	{
		box->AddString("��");
		box->AddString("Ů");
	}
}


void CChange::OnCbnDropdownCombo2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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