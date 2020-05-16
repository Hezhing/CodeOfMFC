// UserListView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_EXAM3_1.h"
#include "UserListView.h"
#include "ZHN_EXAM3_1Doc.h"
#include "NewObject.h"


// CUserListView

IMPLEMENT_DYNCREATE(CUserListView, CListView)

CUserListView::CUserListView()
{

}

CUserListView::~CUserListView()
{
}

BEGIN_MESSAGE_MAP(CUserListView, CListView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CUserListView::OnNMDblclk)
END_MESSAGE_MAP()


// CUserListView ���

#ifdef _DEBUG
void CUserListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserListView ��Ϣ�������


void CUserListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	
	CListCtrl& m_list_ctr = this->GetListCtrl();
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
	m_list_ctr.InsertColumn(0,_T("����"),LVCFMT_LEFT,200);
	m_list_ctr.InsertColumn(1,_T("ռ��"),LVCFMT_CENTER,200);
	m_list_ctr.InsertColumn(2,_T("R"),LVCFMT_CENTER,200);
	m_list_ctr.InsertColumn(3,_T("G"),LVCFMT_CENTER,200);
	m_list_ctr.InsertColumn(4,_T("B"),LVCFMT_CENTER,200);
	Updata();

}

void CUserListView::Updata()
{
	CListCtrl& m_list_ctr = this->GetListCtrl();

	CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
	ASSERT_VALID(pDoc);
	m_list_ctr.DeleteAllItems();
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
}

void CUserListView::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW *pNMListView=(NM_LISTVIEW *)pNMHDR;
    int nItem=pNMListView->iItem;

	CListCtrl& m_list_ctr = this->GetListCtrl();

    if(nItem>=0 && nItem<m_list_ctr.GetItemCount())//�ж�˫��λ���Ƿ��������ݵ��б�������
    {
		CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
		CNewObject no;
		no.ModifyObj(nItem, pDoc->fd[nItem].name,pDoc->fd[nItem].PerMoney,pDoc->fd[nItem].R,pDoc->fd[nItem].G,pDoc->fd[nItem].B); // ��ʾ��Ӧ�е�����
		no.DoModal();
    }
	
	*pResult = 0;
}
