// MedicListView.cpp : 实现文件
//

#include "stdafx.h"
#include "ZHN_TEST3_1.h"
#include "MedicListView.h"
#include "Add.h"
#include "Change.h"
#include "Search.h"
#include "UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"

#include"ZHN_TEST3_1Doc.h"

#include <fstream>
#include<string>
using namespace std;

// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{
	
}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView 诊断

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView 消息处理程序

// 列表视图初始化
void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	
	Updata();
	
}

void CMedicListView::Updata()
{
	// 获取列表视图中的列表控件
	CListCtrl& listCtrl = this->GetListCtrl();
	
	LONG lStyle; 
	lStyle = GetWindowLong(listCtrl.m_hWnd, GWL_STYLE);// 获取当前窗口style 
    lStyle &= ~LVS_TYPEMASK; // 清除显示方式位 
    lStyle |= LVS_REPORT; // 设置style 
    SetWindowLong(listCtrl.m_hWnd, GWL_STYLE, lStyle);// 设置style 

    DWORD dwStyle = listCtrl.GetExtendedStyle(); 
    dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（只适用与report 风格的listctrl ） 
	dwStyle |= LVS_EX_GRIDLINES;// 网格线（只适用与report 风格的listctrl ） 
	//   dwStyle |= LVS_EX_CHECKBOXES;//item 前生成checkbox 控件 
	listCtrl.SetExtendedStyle(dwStyle); // 设置扩展风格
	
	

	CString head[] = {
		TEXT("会员号"),TEXT("姓名"),TEXT("性别"),TEXT("身份证号"),
		TEXT("会员等级"),TEXT("入会时间"),TEXT("爱好"),TEXT("备注")
	};

	int n = sizeof(head) / sizeof(head[0]);
	for(int i=0;i<n;i++)
	{
		listCtrl.InsertColumn(i,head[i],LVCFMT_CENTER,100);
	}


	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	
	/*CString s;
	s.Format(_T("test"));
	MessageBox(s);*/
	pDoc->OpenFiles();
	listCtrl.DeleteAllItems();
	for(int i=0;i<pDoc->save.size();i++)
	{
		listCtrl.InsertItem(i,pDoc->save[i].I_id);
		CString s;
		s.Format(TEXT("%s"), pDoc->save[i].I_name);
		listCtrl.SetItemText(i,1,s);
		s.Format(TEXT("%s"), pDoc->save[i].I_sex);
		listCtrl.SetItemText(i,2,s);
		s.Format(TEXT("%s"), pDoc->save[i].I_id);
		listCtrl.SetItemText(i,3,s);
		s.Format(TEXT("%s"), pDoc->save[i].I_level);
		listCtrl.SetItemText(i,4,s);
		s.Format(TEXT("%s"), pDoc->save[i].I_time);
		listCtrl.SetItemText(i,5,s);
		s.Format(TEXT("%s"), pDoc->save[i].I_like);
		listCtrl.SetItemText(i,6,s);
		s.Format(TEXT("%s"), pDoc->save[i].I_remarks);
		listCtrl.SetItemText(i,7,s);
	}
}

