// UserTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "ZHN_EXAM3_1.h"
#include "UserTreeView.h"
#include "ZHN_EXAM3_1Doc.h"
#include "NewObject.h"


// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CUserTreeView::OnNMDblclk)
END_MESSAGE_MAP()


// CUserTreeView 诊断

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView 消息处理程序


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	// 显示树控件的数据
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();

	for(int i=0;i<pDoc->fd.size();i++)
	{
		m_tree.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
		HTREEITEM root = m_tree.InsertItem(pDoc->fd[i].name,0,NULL,NULL);
	}

	/*m_tree.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
	HTREEITEM root = m_tree.InsertItem(TEXT("数据管理"),0,NULL,NULL);

	HTREEITEM Eat = m_tree.InsertItem(TEXT("吃饭"),1,NULL,root);
	HTREEITEM Cloth = m_tree.InsertItem(TEXT("衣服"),1,NULL,root);
	HTREEITEM Entertainment = m_tree.InsertItem(TEXT("娱乐"),1,NULL,root);
	HTREEITEM Education = m_tree.InsertItem(TEXT("教育"),1,NULL,root);
	HTREEITEM Mortgage = m_tree.InsertItem(TEXT("房贷"),1,NULL,root);*/

	// TODO: 在此添加专用代码和/或调用基类
}

void CUserTreeView::Updata()
{
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();

	m_tree.DeleteAllItems();
	for(int i=0;i<pDoc->fd.size();i++)
	{
		m_tree.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
		HTREEITEM root = m_tree.InsertItem(pDoc->fd[i].name,0,NULL,NULL);
	}
}



void CUserTreeView::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	// 双击列表控件行，可以弹出对象的属性对话框
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	CZHN_EXAM3_1Doc* pDoc = (CZHN_EXAM3_1Doc*)GetParentFrame()->GetActiveDocument();
	HTREEITEM Hitem;
	Hitem=NULL;
	Hitem=m_tree.GetSelectedItem();
	CString m_EditItem=m_tree.GetItemText(Hitem);

	for(int i=0;i<pDoc->fd.size();i++)
	{
		if(pDoc->fd[i].name == m_EditItem)
		{
			CNewObject no;
			no.ModifyObj(i, pDoc->fd[i].name,pDoc->fd[i].PerMoney,pDoc->fd[i].R,pDoc->fd[i].G,pDoc->fd[i].B);
			no.DoModal();
		}
	}
	*pResult = 0;
}
