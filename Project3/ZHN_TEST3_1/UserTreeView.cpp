// UserTreeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZHN_TEST3_1.h"
#include "Add.h"
#include "Change.h"
#include "Search.h"
#include "UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"


#include <fstream>
#include<string>
using namespace std;

// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView ���

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


// CUserTreeView ��Ϣ�������


// ����ͼ��ʼ��
void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	Updata();

}

void CUserTreeView::Updata()
{
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	pDoc->OpenFiles();

	CString h_lev[100],m_lev[100],l_lev[100];
	int h_shu=0,m_shu=0,l_shu=0;
	for (int store=0;store<pDoc->save.size();store++)
	{
		if((pDoc->save[store].I_level)=="�߼�")
		{
			h_lev[h_shu]=(pDoc->save[store].I_id);
			h_shu++;
		}
		else if ((pDoc->save[store].I_level)=="�м�")
		{
			m_lev[m_shu]=(pDoc->save[store].I_id);
			m_shu++;
		}
		else
		{
			l_lev[l_shu]=(pDoc->save[store].I_id);
			l_shu++;
		}
	}

	CTreeCtrl &myTree=this->GetTreeCtrl();  //����style
	myTree.DeleteAllItems();
	myTree.ModifyStyle(0,TVS_EDITLABELS|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);
	
	//���ؼ��в�����Ϣ
	myTree.SetImageList(&imageList,LVSIL_NORMAL);
	myTree.DeleteAllItems();
	for (int k=0;k<3;k++)
	{
		if (k==0)
		{
			TV_INSERTSTRUCT TCitem;
			TCitem.hParent=TVI_ROOT;
			TCitem.hInsertAfter=TVI_LAST;
			TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			TCitem.item.pszText="�߼���Ա";
			TCitem.item.lParam=0;
			TCitem.item.iImage=0;
			TCitem.item.iSelectedImage=1;
			HTREEITEM rootItem=myTree.InsertItem(&TCitem);
			
			for(int i=0;i<h_shu;i++)
			{
				TV_INSERTSTRUCT TCSubItem;
				TCSubItem.hParent=rootItem;
				TCSubItem.hInsertAfter=TVI_LAST;
				TCSubItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
				TCSubItem.item.pszText=(LPTSTR)(LPCTSTR)h_lev[i];
				TCSubItem.item.lParam=i+1;
				TCSubItem.item.iImage=2;
				TCSubItem.item.iSelectedImage=3;
				HTREEITEM childItem=myTree.InsertItem(&TCSubItem);
			}
			myTree.Expand(rootItem,TVE_EXPAND);
		}
		else if(k==1)
		{
			TV_INSERTSTRUCT TCitem;
			TCitem.hParent=TVI_ROOT;
			TCitem.hInsertAfter=TVI_LAST;
			TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			TCitem.item.pszText="�м���Ա";
			TCitem.item.lParam=0;
			TCitem.item.iImage=0;
			TCitem.item.iSelectedImage=1;
			HTREEITEM rootItem=myTree.InsertItem(&TCitem);
			
			for(int i=0;i<m_shu;i++)
			{
				TV_INSERTSTRUCT TCSubItem;
				TCSubItem.hParent=rootItem;
				TCSubItem.hInsertAfter=TVI_LAST;
				TCSubItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
				TCSubItem.item.pszText=(LPTSTR)(LPCTSTR)m_lev[i];
				TCSubItem.item.lParam=i+1;
				TCSubItem.item.iImage=2;
				TCSubItem.item.iSelectedImage=3;
				HTREEITEM childItem=myTree.InsertItem(&TCSubItem);
			}
			myTree.Expand(rootItem,TVE_EXPAND);
		}
		else
		{
			TV_INSERTSTRUCT TCitem;
			TCitem.hParent=TVI_ROOT;
			TCitem.hInsertAfter=TVI_LAST;
			TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			TCitem.item.pszText="�ͼ���Ա";
			TCitem.item.lParam=0;
			TCitem.item.iImage=0;
			TCitem.item.iSelectedImage=1;
			HTREEITEM rootItem=myTree.InsertItem(&TCitem);
			
			for(int i=0;i<l_shu;i++)
			{
				TV_INSERTSTRUCT TCSubItem;
				TCSubItem.hParent=rootItem;
				TCSubItem.hInsertAfter=TVI_LAST;
				TCSubItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
				TCSubItem.item.pszText=(LPTSTR)(LPCTSTR)l_lev[i];
				TCSubItem.item.lParam=i+1;
				TCSubItem.item.iImage=2;
				TCSubItem.item.iSelectedImage=3;
				HTREEITEM childItem=myTree.InsertItem(&TCSubItem);
			}
			myTree.Expand(rootItem,TVE_EXPAND);
		}
	}
}
