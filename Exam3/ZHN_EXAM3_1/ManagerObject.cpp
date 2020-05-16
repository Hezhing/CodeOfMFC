// ManagerObject.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_EXAM3_1.h"
#include "ManagerObject.h"
#include "afxdialogex.h"

#include "ZHN_EXAM3_1Doc.h"
#include "NewObject.h"


// CManagerObject �Ի���

IMPLEMENT_DYNAMIC(CManagerObject, CDialogEx)

CManagerObject::CManagerObject(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagerObject::IDD, pParent)
{

}

CManagerObject::~CManagerObject()
{
}

void CManagerObject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list_ctr);
}


BEGIN_MESSAGE_MAP(CManagerObject, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST3, &CManagerObject::OnNMDblclkList1)
END_MESSAGE_MAP()


// CManagerObject ��Ϣ�������


BOOL CManagerObject::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	LONG lStyle;
	// ��ȡ��ǰ����style
	lStyle = GetWindowLong(m_list_ctr.m_hWnd, GWL_STYLE);
	// �����ʾ��ʽλ
	lStyle &= ~LVS_TYPEMASK; 
	// ����style
	lStyle |= LVS_REPORT; 
	//����style
    SetWindowLong(m_list_ctr.m_hWnd, GWL_STYLE, lStyle);
	DWORD extStyle = m_list_ctr.GetExtendedStyle();
	// ѡ��ĳ��ʹ���и�����ֻ������report���)
	extStyle |= LVS_EX_FULLROWSELECT;
	// �����ߣ�ֻ������report���
	extStyle |= LVS_EX_GRIDLINES;
	m_list_ctr.SetExtendedStyle(extStyle);
	m_list_ctr.InsertColumn(0,_T("����"),LVCFMT_LEFT,120);
	m_list_ctr.InsertColumn(1,_T("ռ��"),LVCFMT_CENTER,100);
	m_list_ctr.InsertColumn(2,_T("R"),LVCFMT_CENTER,80);
	m_list_ctr.InsertColumn(3,_T("G"),LVCFMT_CENTER,80);
	m_list_ctr.InsertColumn(4,_T("B"),LVCFMT_CENTER,80);

	CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
	ASSERT_VALID(pDoc);
	for(int i=0;i<pDoc->fd.size();i++)
	{
		m_list_ctr.InsertItem(i, pDoc->fd[i].name);
		CString s;
		s.Format(TEXT("%.2f"), pDoc->fd[i].PerMoney);
		m_list_ctr.SetItemText(i, 1, s);
		s.Format(TEXT("%d"), pDoc->fd[i].R);
		m_list_ctr.SetItemText(i, 2, s);
		s.Format(TEXT("%d"), pDoc->fd[i].G);
		m_list_ctr.SetItemText(i, 3, s);
		s.Format(TEXT("%d"), pDoc->fd[i].B);
		m_list_ctr.SetItemText(i, 4, s);
	}

	return TRUE;  // return TRUE unless you set the focus to a control

}

void CManagerObject::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW *pNMListView=(NM_LISTVIEW *)pNMHDR;
    int nItem=pNMListView->iItem;

    if(nItem>=0 && nItem<m_list_ctr.GetItemCount())//�ж�˫��λ���Ƿ��������ݵ��б�������
    {
		CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
		CNewObject no;
		no.ModifyObj(nItem, pDoc->fd[nItem].name,pDoc->fd[nItem].PerMoney,pDoc->fd[nItem].R,pDoc->fd[nItem].G,pDoc->fd[nItem].B);
		no.DoModal();
    }
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
