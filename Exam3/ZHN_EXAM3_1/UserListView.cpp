// UserListView.cpp : 实现文件
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


// CUserListView 诊断

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


// CUserListView 消息处理程序


void CUserListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	
	CListCtrl& m_list_ctr = this->GetListCtrl();
	LONG lStyle;
	// 获取当前窗口style
	lStyle = GetWindowLong(m_list_ctr.m_hWnd, GWL_STYLE);
	// 清除显示方式位
	lStyle &= ~LVS_TYPEMASK; 
	// 设置style
	lStyle |= LVS_REPORT; 
	//设置style
    SetWindowLong(m_list_ctr.m_hWnd, GWL_STYLE, lStyle);

	DWORD extStyle = m_list_ctr.GetExtendedStyle();
	// 选中某行使整行高亮（只适用与report风格)
	extStyle |= LVS_EX_FULLROWSELECT;
	// 网格线（只适用与report风格
	extStyle |= LVS_EX_GRIDLINES;
	m_list_ctr.SetExtendedStyle(extStyle);
	m_list_ctr.InsertColumn(0,_T("名称"),LVCFMT_LEFT,200);
	m_list_ctr.InsertColumn(1,_T("占比"),LVCFMT_CENTER,200);
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
	// TODO: 在此添加控件通知处理程序代码

	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW *pNMListView=(NM_LISTVIEW *)pNMHDR;
    int nItem=pNMListView->iItem;

	CListCtrl& m_list_ctr = this->GetListCtrl();

    if(nItem>=0 && nItem<m_list_ctr.GetItemCount())//判断双击位置是否在有数据的列表项上面
    {
		CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
		CNewObject no;
		no.ModifyObj(nItem, pDoc->fd[nItem].name,pDoc->fd[nItem].PerMoney,pDoc->fd[nItem].R,pDoc->fd[nItem].G,pDoc->fd[nItem].B); // 显示相应行的数据
		no.DoModal();
    }
	
	*pResult = 0;
}
