// NewObject.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_EXAM3_1.h"
#include "NewObject.h"
#include "afxdialogex.h"

#include "ZHN_EXAM3_1Doc.h"
#include "UserListView.h"
#include "UserTreeView.h"



// CNewObject �Ի���

IMPLEMENT_DYNAMIC(CNewObject, CDialogEx)

CNewObject::CNewObject(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewObject::IDD, pParent)
	, name(_T("�½���������"))
	, PerMoney(0.0)
	, R(0)
	, G(0)
	, B(0)
{
	index = -1;
}

CNewObject::~CNewObject()
{
}

void CNewObject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, PerMoney);
	DDX_Text(pDX, IDC_EDIT3, R);
	DDV_MinMaxInt(pDX, R, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, G);
	DDV_MinMaxInt(pDX, G, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, B);
	DDV_MinMaxInt(pDX, B, 0, 255);
}


BEGIN_MESSAGE_MAP(CNewObject, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewObject::OnBnClickedOk)
END_MESSAGE_MAP()


// CNewObject ��Ϣ��������


void CNewObject::OnBnClickedOk()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CZHN_EXAM3_1Doc *pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(index==-1){
		UpdateData(TRUE);
		pDoc->AddData(name,PerMoney,R,G,B);	
	} else {
		UpdateData(TRUE);
		pDoc->fd[index].name = name;
		pDoc->fd[index].PerMoney = PerMoney;
		pDoc->fd[index].R = R;
		pDoc->fd[index].G = G;
		pDoc->fd[index].B = B;
		pDoc->CalculatePer();
		pDoc->MyUpDateView();
	}
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CZHN_EXAM3_1Doc* pdoc = (CZHN_EXAM3_1Doc*)pMainFrame->GetActiveDocument();
	CUserListView* listView = (CUserListView*)pMainFrame->m_sWnd1.GetPane(1,0);
	CUserTreeView* treeList = (CUserTreeView*)pMainFrame->m_sWnd.GetPane(0,0);
	treeList->Updata();
	listView->Updata();
	CDialogEx::OnOK();
}

void CNewObject::ModifyObj(int index1,CString name1,float PerMoney1,int R1,int G1,int B1)
{
	name = name1;
	PerMoney = PerMoney1;
	R = R1;
	G = G1;
	B = B1;
	index = index1;
}