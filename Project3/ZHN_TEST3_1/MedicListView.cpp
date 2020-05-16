// MedicListView.cpp : ʵ���ļ�
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


// CMedicListView ���

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


// CMedicListView ��Ϣ�������

// �б���ͼ��ʼ��
void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	
	Updata();
	
}

void CMedicListView::Updata()
{
	// ��ȡ�б���ͼ�е��б�ؼ�
	CListCtrl& listCtrl = this->GetListCtrl();
	
	LONG lStyle; 
	lStyle = GetWindowLong(listCtrl.m_hWnd, GWL_STYLE);// ��ȡ��ǰ����style 
    lStyle &= ~LVS_TYPEMASK; // �����ʾ��ʽλ 
    lStyle |= LVS_REPORT; // ����style 
    SetWindowLong(listCtrl.m_hWnd, GWL_STYLE, lStyle);// ����style 

    DWORD dwStyle = listCtrl.GetExtendedStyle(); 
    dwStyle |= LVS_EX_FULLROWSELECT;// ѡ��ĳ��ʹ���и�����ֻ������report ����listctrl �� 
	dwStyle |= LVS_EX_GRIDLINES;// �����ߣ�ֻ������report ����listctrl �� 
	//   dwStyle |= LVS_EX_CHECKBOXES;//item ǰ����checkbox �ؼ� 
	listCtrl.SetExtendedStyle(dwStyle); // ������չ���
	
	

	CString head[] = {
		TEXT("��Ա��"),TEXT("����"),TEXT("�Ա�"),TEXT("���֤��"),
		TEXT("��Ա�ȼ�"),TEXT("���ʱ��"),TEXT("����"),TEXT("��ע")
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

