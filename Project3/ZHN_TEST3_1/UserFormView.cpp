// UserFormView.cpp : 实现文件
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

// CUserFormView

IMPLEMENT_DYNCREATE(CUserFormView, CFormView)

CUserFormView::CUserFormView()
	: CFormView(CUserFormView::IDD)
{
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	clickList = false;
	I_add = false;
}

CUserFormView::~CUserFormView()
{
}

void CUserFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUserFormView, CFormView)
	ON_BN_CLICKED(IDOK, &CUserFormView::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUserFormView::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserFormView::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON4, &CUserFormView::OnBnClickedDelect)
	ON_BN_CLICKED(IDC_BUTTON5, &CUserFormView::OnBnClickedChange)
	ON_BN_CLICKED(IDC_BUTTON6, &CUserFormView::OnBnClickedSearch)
	ON_COMMAND(ID_32771, &CUserFormView::On32771Add)
	ON_COMMAND(ID_32772, &CUserFormView::On32772Delect)
	ON_COMMAND(ID_32773, &CUserFormView::On32773Change)
	ON_COMMAND(ID_32774, &CUserFormView::On32774Search)
END_MESSAGE_MAP()


// CUserFormView 诊断

#ifdef _DEBUG
void CUserFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserFormView 消息处理程序


void CUserFormView::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


void CUserFormView::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

void CUserFormView::showInformation(int index)
{
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(pDoc->save[index].I_id);
	((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(pDoc->save[index].I_name);
	((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(pDoc->save[index].I_sex);
	((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(pDoc->save[index].I_card);
	((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(pDoc->save[index].I_level);
	((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(pDoc->save[index].I_time);
	((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(pDoc->save[index].I_like);
	((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(pDoc->save[index].I_remarks);
}

void CUserFormView::fileListOut(int f_index)
{
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	pDoc->it = pDoc->save.begin()+f_index;
	pDoc->save.erase(pDoc->it);

	reFile();
	UpdateData();
}

void CUserFormView::fileTreeOut(CString f_indexT)
{
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	for(pDoc->store = pDoc->save.begin();pDoc->store!=pDoc->save.end();)
	{
		if(((pDoc->store)->I_id)==f_indexT){
			
            pDoc->store=pDoc->save.erase(pDoc->store);
			
        }else{
			
            pDoc->store++;	
        }
	}

	reFile();
	UpdateData();
}

void CUserFormView::reFile()
{
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();

	ofstream file;
	file.open("会员数据.txt",ios::out|ios::ate);
	if (!file)
	{
		MessageBox("Cannot open file!");
		return;
	}
	for (int store=0;store<pDoc->save.size();store++)
	{
		file <<(LPCTSTR)pDoc->save[store].I_id<<" "<<(LPCTSTR)pDoc->save[store].I_name<<" "<<(LPCTSTR)pDoc->save[store].I_sex<<" "<<(LPCTSTR)pDoc->save[store].I_card
			<<" "<<(LPCTSTR)pDoc->save[store].I_level<<" "<<(LPCTSTR)pDoc->save[store].I_time<<" "<<(LPCTSTR)pDoc->save[store].I_like<<" "<<(LPCTSTR)pDoc->save[store].I_remarks<<"\n";
	}
	
	file.close();
}

void CUserFormView::xiaohui()
{
	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(" ");
	((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(" ");
}


void CUserFormView::OpenFile(CString FilePath)
{

	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();

	ifstream file;
	file.open("会员数据.txt",ios::in);
	if(!file)
	{
		MessageBox(_T("Cannot open file!"));
		return ;
	}
	pDoc->save.clear();
	while(!file.eof())
	{
		string id, name, sex, card, level, time, like, remarks;
		file >> id >> name >> sex >> card >> level >> time >> like >> remarks;
		
		/*CString s;
		s.Format(_T("%s"),name.c_str());
		MessageBox(s);*/

		if(id.empty())
		{
			file.close();
			break;
		}
		CString s;
		s.Format(_T("%s"),id.c_str());
		pDoc->item.I_id = s;
		s.Format(_T("%s"),name.c_str());
		pDoc->item.I_name = s;
		s.Format(_T("%s"),sex.c_str());
		pDoc->item.I_sex = s;
		s.Format(_T("%s"),card.c_str());
		pDoc->item.I_card = s;
		s.Format(_T("%s"),level.c_str());
		pDoc->item.I_level = s;
		s.Format(_T("%s"),time.c_str());
		pDoc->item.I_time = s;
		s.Format(_T("%s"),like.c_str());
		pDoc->item.I_like = s;
		s.Format(_T("%s"),remarks.c_str());
		pDoc->item.I_remarks = s;
		pDoc->save.push_back(pDoc->item);
	}

	pDoc->UpdateAllViews(NULL);
}


void CUserFormView::WriteFile()
{
	ofstream file;
	file.open("会员数据.txt",ios::out|ios::app);
	if (!file)
	{
		MessageBox("Cannot open file!");
		return;
	}
	
	file <<"\n"<<(LPCTSTR)add.a_id<<" "<<(LPCTSTR)add.a_name<<" "<<(LPCTSTR)add.a_sex<<" "<<(LPCTSTR)add.a_card
		<<" "<<(LPCTSTR)add.a_level<<" "<<(LPCTSTR)add.a_time<<" "<<(LPCTSTR)add.a_like<<" "<<(LPCTSTR)add.a_remarks;
	file.close();
}

void CUserFormView::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	int i = atoi(add.m_aid);
	CString s;
	if(I_add)
	{
		s.Format("%d",i+1);
		add.m_aid = s;
		I_add = false;
	}
	add.DoModal();
	if (add.a_state && add.a_id!="" && add.a_name!="" && add.a_card!="" && add.a_sex!="" && add.a_time!="")
	{		
		pDoc->item.I_id=add.a_id;
		pDoc->item.I_name=add.a_name;
		pDoc->item.I_sex=add.a_sex;
		pDoc->item.I_card=add.a_card;
		pDoc->item.I_level=add.a_level;
		pDoc->item.I_time=add.a_time;
		pDoc->item.I_like=add.a_like;
		pDoc->item.I_remarks=add.a_remarks;
		pDoc->save.push_back(pDoc->item);

		//主信息栏显示信息
		((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(add.a_id);
		((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(add.a_name);
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(add.a_sex);
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(add.a_card);
		((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(add.a_level);
		((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(add.a_time);
		((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(add.a_like);
		((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(add.a_remarks);

		WriteFile();

		I_add=true;
		add.a_state=false;
		pDoc->UpdateAllViews(NULL);
	}

}


void CUserFormView::OnBnClickedDelect()
{
	// TODO: 在此添加控件通知处理程序代码
	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();
	if (clickList)
	{
		clickList=false;
		CString strMessage = _T("是否删除当前选择的数据？");
		/*if(MessageBox(strMessage,_T(""),MB_YESNO)== IDYES)
		{
			CListCtrl *lCtrl; //有问题

			int num=lCtrl->GetItemCount();
			for(int i=0;i<num;i++)
			{
				if((lCtrl->GetItemState(i, LVNI_ALL | LVNI_SELECTED) == LVIS_SELECTED)||(lCtrl->GetCheck(i)==true))
					lCtrl->DeleteItem(i);		
			}
			xiaohui();
			int f_index=I_index;
			fileListOut(f_index);//文件对应删除
			
			//重绘列表
			
			lCtrl->DeleteAllItems();
			
		} */
	}
	else
	{
		MessageBox("请选中一条信息再删除！");
	}
}


void CUserFormView::OnBnClickedChange()
{
	// TODO: 在此添加控件通知处理程序代码
	bool revise_state = false;
	if (clickList)
	{
		CString re;
		clickList=false;
		((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(re);
		revise.m_rid=re;
		revise.DoModal();	

		CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();

		if (revise.r_state && revise.r_id!="" && revise.r_name!="" && revise.r_card!="" && revise.r_sex!="" && revise.r_level)//开始遍历修改
		{	
			
		//	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(re);

			for (pDoc->store=pDoc->save.begin();pDoc->store!=pDoc->save.end();++pDoc->store)
			{
				if (((pDoc->store)->I_id)==re )
				{
					//主信息栏显示信息
					(pDoc->store)->I_id=revise.r_id;
					(pDoc->store)->I_name=revise.r_name;
					(pDoc->store)->I_sex=revise.r_sex;
					(pDoc->store)->I_card=revise.r_card;
					(pDoc->store)->I_level=revise.r_level;
					(pDoc->store)->I_time=revise.r_time;
					(pDoc->store)->I_like=revise.r_like;
					(pDoc->store)->I_remarks=revise.r_remarks;
					
					//主信息面显示
					((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(revise.r_id);
					((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(revise.r_name);
					((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(revise.r_sex);
					((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(revise.r_card);
					((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(revise.r_level);
					((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(revise.r_time);
					((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(revise.r_like);
					((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(revise.r_remarks);
					
					reFile();//修改后写入文件
					MessageBox("修改信息成功！");
					revise_state=true;
					break;
				}
				
			}
			if(!revise_state)
			{
				MessageBox("抱歉，修改信息失败！");
			}
		}
	}
	else
	{
		MessageBox("请选中一条信息再修改！");
	}
}


void CUserFormView::OnBnClickedSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	bool query_state = false;
	query.DoModal();

	CZHN_TEST3_1Doc *pDoc = (CZHN_TEST3_1Doc*)GetDocument();

	if (query.q_state && query.q_id!="" && query.q_name!="" && query.q_card!="" && query.q_sex!="")//开始遍历查询
	{	
 		for (pDoc->store=pDoc->save.begin();pDoc->store!=pDoc->save.end();++pDoc->store)
 		{
 			if (((pDoc->store)->I_id)==query.q_id && ((pDoc->store)->I_name)==query.q_name && ((pDoc->store)->I_card)==query.q_card && ((pDoc->store)->I_sex)==query.q_sex)
 			{
 				//主信息栏显示信息
 				((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(((pDoc->store)->I_id));
 				((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(((pDoc->store)->I_name));
 				((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(((pDoc->store)->I_sex));
 				((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(((pDoc->store)->I_card));
 				((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(((pDoc->store)->I_level));
 				((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(((pDoc->store)->I_time));
 				((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(((pDoc->store)->I_like));
 				((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(((pDoc->store)->I_remarks));
				query_state=true;
 				break;
			}
 		}
		if(!query_state)
		{
			MessageBox("抱歉，未查询到你想要的相关信息！");
		}
	}
}


void CUserFormView::On32771Add()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedAdd();
}


void CUserFormView::On32772Delect()
{
	// TODO: 在此添加命令处理程序代码

}


void CUserFormView::On32773Change()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedChange();
}


void CUserFormView::On32774Search()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedSearch();
}




