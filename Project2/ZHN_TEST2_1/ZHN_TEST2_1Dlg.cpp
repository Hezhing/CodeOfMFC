
// ZHN_TEST2_1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ZHN_TEST2_1.h"
#include "ZHN_TEST2_1Dlg.h"
#include "afxdialogex.h"

#include "add.h"
#include "Change.h"
#include "Search.h"

#include <fstream>
#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CZHN_TEST2_1Dlg 对话框



CZHN_TEST2_1Dlg::CZHN_TEST2_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CZHN_TEST2_1Dlg::IDD, pParent)
{
	I_add=false;
	clickList=false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZHN_TEST2_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CZHN_TEST2_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CZHN_TEST2_1Dlg::On32771)
	ON_COMMAND(ID_32772, &CZHN_TEST2_1Dlg::On32772)
	ON_COMMAND(ID_32773, &CZHN_TEST2_1Dlg::On32773)
	ON_COMMAND(ID_32774, &CZHN_TEST2_1Dlg::On32774)
	ON_COMMAND(ID_32775, &CZHN_TEST2_1Dlg::On32775)
	ON_BN_CLICKED(IDC_BUTTON1, &CZHN_TEST2_1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CZHN_TEST2_1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CZHN_TEST2_1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CZHN_TEST2_1Dlg::OnBnClickedButton4)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CZHN_TEST2_1Dlg::OnNMClickList1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CZHN_TEST2_1Dlg::OnTvnSelchangedTree1)
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, &CZHN_TEST2_1Dlg::OnNMRClickTree1)
	ON_COMMAND(ID_32776, &CZHN_TEST2_1Dlg::On32776)
	ON_COMMAND(ID_32777, &CZHN_TEST2_1Dlg::On32777)
END_MESSAGE_MAP()


// CZHN_TEST2_1Dlg 消息处理程序

BOOL CZHN_TEST2_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	// TODO: 在此添加额外的初始化代码

	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU2);
	SetMenu(&m_Menu);

	CListCtrl* lCtrl;
	lCtrl=(CListCtrl*)GetDlgItem(IDC_LIST1);
	LONG lStyle; 
	lStyle = GetWindowLong(lCtrl->m_hWnd, GWL_STYLE);// 获取当前窗口style 
    lStyle &= ~LVS_TYPEMASK; // 清除显示方式位 
    lStyle |= LVS_REPORT; // 设置style 
    SetWindowLong(lCtrl->m_hWnd, GWL_STYLE, lStyle);// 设置style 
    DWORD dwStyle = lCtrl->GetExtendedStyle(); 
    dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（只适用与report 风格的listctrl ） 
	dwStyle |= LVS_EX_GRIDLINES;// 网格线（只适用与report 风格的listctrl ） 
	//   dwStyle |= LVS_EX_CHECKBOXES;//item 前生成checkbox 控件 

	lCtrl->SetExtendedStyle(dwStyle); // 设置扩展风格
	   
	lCtrl->InsertColumn(0,"会员号",LVCFMT_CENTER, 70);
	lCtrl->InsertColumn(1,"姓名",LVCFMT_CENTER, 70);
	lCtrl->InsertColumn(2,"性别",LVCFMT_CENTER, 50);
	lCtrl->InsertColumn(3,"身份证号",LVCFMT_CENTER, 150);
	lCtrl->InsertColumn(4,"会员等级",LVCFMT_CENTER, 80);
	lCtrl->InsertColumn(5,"入会时间",LVCFMT_CENTER, 100);
	lCtrl->InsertColumn(6,"爱好",LVCFMT_CENTER, 70);
	lCtrl->InsertColumn(7,"备注",LVCFMT_CENTER, 110);

	m_ImageList.Create(16,16,ILC_COLOR,4,2);
	//myPopMenu.LoadMenu(IDR_MENU2);

	CTreeCtrl* myTree=(CTreeCtrl*)GetDlgItem(IDC_TREE1);
	myTree->DeleteAllItems();
	myTree->ModifyStyle(0,TVS_EDITLABELS|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);

	CZHN_TEST2_1App * PmyApp=(CZHN_TEST2_1App *)AfxGetApp();

	m_ImageList.Add(PmyApp->LoadIcon(IDI_ICON1));
	m_ImageList.Add(PmyApp->LoadIcon(IDI_ICON2));
	m_ImageList.Add(PmyApp->LoadIcon(IDI_ICON3));
	m_ImageList.Add(PmyApp->LoadIcon(IDI_ICON4));

	myTree->SetImageList(&m_ImageList,LVSIL_NORMAL);

	for (int k=0;k<3;k++)
	   {
		   if(k==0)
		   {		
			   TV_INSERTSTRUCT TCitem;
			   TCitem.hParent=TVI_ROOT;
			   TCitem.hInsertAfter=TVI_LAST;
			   TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			   TCitem.item.pszText="高级会员";
			   TCitem.item.lParam=0;
			   TCitem.item.iImage=0;
			   TCitem.item.iSelectedImage=1;
			   HTREEITEM rootItem=myTree->InsertItem(&TCitem);
			   //	HTREEITEM rootItem=myTree->InsertItem(_T("root"),TVI_ROOT,TVI_LAST);	   
		   }
		   else if(k==1)
		   {
			   /////////////////////////////////////////////////
			   TV_INSERTSTRUCT TCitem;
			   TCitem.hParent=TVI_ROOT;
			   TCitem.hInsertAfter=TVI_LAST;
			   TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			   TCitem.item.pszText="中级会员";
			   TCitem.item.lParam=0;
			   TCitem.item.iImage=0;
			   TCitem.item.iSelectedImage=1;
			   HTREEITEM rootItem=myTree->InsertItem(&TCitem);	
		   }
		   else
		   {
			   /////////////////////////////////////////////////
			   TV_INSERTSTRUCT TCitem;
			   TCitem.hParent=TVI_ROOT;
			   TCitem.hInsertAfter=TVI_LAST;
			   TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			   TCitem.item.pszText="低级会员";
			   TCitem.item.lParam=0;
			   TCitem.item.iImage=0;
			   TCitem.item.iSelectedImage=1;
			   HTREEITEM rootItem=myTree->InsertItem(&TCitem);
		   }
	}

	ifstream file;
	file.open("会员数据.txt",ios::in);
	if(!file)
	{
		MessageBox("Cannot open file!");
		return 0;
	}
	save.clear();
	while(!file.eof())
	{
		item = new Information;
		string id, name, sex, card, level, time, like, remarks;
		file >> id >> name >> sex >> card >> level >> time >> like >> remarks;
		if(id.empty())
		{
			file.close();
			break;
		}
		item->I_id.Format("%s",id.c_str());
		item->I_name.Format("%s",name.c_str());
		item->I_sex.Format("%s",sex.c_str());
		item->I_card.Format("%s",card.c_str());
		item->I_level.Format("%s",level.c_str());
		item->I_time.Format("%s",time.c_str());
		item->I_like.Format("%s",like.c_str());
		item->I_remarks.Format("%s",remarks.c_str());
		save.push_back(item);
	}
	store = save.end()-1;
	int itemp = atoi((*store)->I_id);
	itemp+=1;
	CString stemp;
	stemp.Format("%d",itemp);
	add.m_aid=stemp;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CZHN_TEST2_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CZHN_TEST2_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CZHN_TEST2_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CZHN_TEST2_1Dlg::On32771()
{
	
	// TODO: 在此添加命令处理程序代码
	CFileDialog *lpszOpenFile;
	CStdioFile file;
	CString filePathName;
	CString result;

	// 生成对话框
	lpszOpenFile = new CFileDialog(TRUE,"","",OFN_FILEMUSTEXIST |OFN_HIDEREADONLY , "文件类型(*.txt)|*.txt|所有文件(*.*)|*.*|");

	if(lpszOpenFile->DoModal() == IDOK)
	{
		filePathName = lpszOpenFile->GetPathName(); // 得到文件路径
	}
	OpenFile(filePathName); // 打开文件
	
}


void CZHN_TEST2_1Dlg::On32772()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedButton1();
}


void CZHN_TEST2_1Dlg::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CTreeCtrl* myTree=(CTreeCtrl*)GetDlgItem(IDC_TREE1);
	HTREEITEM hSel = myTree->GetSelectedItem();
	if(hSel==NULL)//没有选中节点
		return;
	else
		if(myTree->ItemHasChildren(hSel))//选中节点有子节点
		{
			CString strMessage = _T("当前选择的项包含子项，是否删除？");
			if(MessageBox(strMessage,_T(""),MB_YESNO)== IDYES)
				myTree->DeleteItem(hSel);//删除子树
		}
		else
		{
			CString strMessage = _T("是否删除当前选择的数据？");//（有问题？？）
			if(MessageBox(strMessage,_T(""),MB_YESNO)== IDYES)
			{
				//	myTree->DeleteItem(hSel);//删除单个节点//形式上删除节点，选中点会自动下移，与重绘树的方法产生矛盾，导致删除错误
				xiaohui();  //主信息面清空
				CString f_indexT=I_indexT;
				MessageBox(f_indexT);
				fileTreeOut(f_indexT);//文件对应删除
				
				//重绘列表
				CListCtrl* lCtrl;
				lCtrl=(CListCtrl*)GetDlgItem(IDC_LIST1);
				lCtrl->DeleteAllItems();
				
				initList();   //重绘list
				initTree();   //重绘tree
			}
		}
}


void CZHN_TEST2_1Dlg::On32774()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedButton3();
}


void CZHN_TEST2_1Dlg::On32775()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedButton4();
}


void CZHN_TEST2_1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

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
		item = new Information;//必加
		item->I_id=add.a_id;
		item->I_name=add.a_name;
		item->I_sex=add.a_sex;
		item->I_card=add.a_card;
		item->I_level=add.a_level;
		item->I_time=add.a_time;
		item->I_like=add.a_like;
		item->I_remarks=add.a_remarks;
		save.push_back(item);

		//主信息栏显示信息
		((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(add.a_id);
		((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(add.a_name);
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(add.a_sex);
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(add.a_card);
		((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(add.a_level);
		((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(add.a_time);
		((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(add.a_like);
		((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(add.a_remarks);
		
		//重绘列表
		CListCtrl* lCtrl;
		lCtrl=(CListCtrl*)GetDlgItem(IDC_LIST1);
		lCtrl->DeleteAllItems();
		
		initList();
		initTree();
		WriteFile();

		I_add=true;
		add.a_state=false;
	}
}


void CZHN_TEST2_1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (clickList)
	{
		clickList=false;
		CString strMessage = _T("是否删除当前选择的数据？");
		if(MessageBox(strMessage,_T(""),MB_YESNO)== IDYES)
		{
			CListCtrl* lCtrl;
			lCtrl=(CListCtrl*)GetDlgItem(IDC_LIST1);
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
			
			initList();   //重绘list
			initTree();   //重绘tree
		} 
	}
	else
	{
		MessageBox("请选中一条信息再删除！");
	}
}


void CZHN_TEST2_1Dlg::OnBnClickedButton3()
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
		
		if (revise.r_state && revise.r_id!="" && revise.r_name!="" && revise.r_card!="" && revise.r_sex!="" && revise.r_level)//开始遍历修改
		{	
			
		//	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(re);

			for (store=save.begin();store!=save.end();++store)
			{
				if (((*store)->I_id)==re )
				{
					//主信息栏显示信息
					(*store)->I_id=revise.r_id;
					(*store)->I_name=revise.r_name;
					(*store)->I_sex=revise.r_sex;
					(*store)->I_card=revise.r_card;
					(*store)->I_level=revise.r_level;
					(*store)->I_time=revise.r_time;
					(*store)->I_like=revise.r_like;
					(*store)->I_remarks=revise.r_remarks;
					
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
					initList();
					initTree();
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


void CZHN_TEST2_1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	bool query_state = false;
	query.DoModal();

	if (query.q_state && query.q_id!="" && query.q_name!="" && query.q_card!="" && query.q_sex!="")//开始遍历查询
	{	
// 		CString re;
// 		((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(re);
// 		MessageBox(re);
 		for (store=save.begin();store!=save.end();++store)
 		{
 			if (((*store)->I_id)==query.q_id && ((*store)->I_name)==query.q_name && ((*store)->I_card)==query.q_card && ((*store)->I_sex)==query.q_sex)
 			{
 				//主信息栏显示信息
 				((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(((*store)->I_id));
 				((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(((*store)->I_name));
 				((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(((*store)->I_sex));
 				((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(((*store)->I_card));
 				((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(((*store)->I_level));
 				((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(((*store)->I_time));
 				((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(((*store)->I_like));
 				((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(((*store)->I_remarks));
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


void CZHN_TEST2_1Dlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl *list = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int index = list->GetSelectionMark();
	showInformation(index);
	I_index = index;  //传递删除的位置
	clickList=true;
	*pResult = 0;
}

void CZHN_TEST2_1Dlg::showInformation(int index)
{
	store=save.begin()+index;
	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText((*store)->I_id);
	((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText((*store)->I_name);
	((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText((*store)->I_sex);
	((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText((*store)->I_card);
	((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText((*store)->I_level);
	((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText((*store)->I_time);
	((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText((*store)->I_like);
	((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText((*store)->I_remarks);
}

void CZHN_TEST2_1Dlg::OpenFile(CString FilePath)
{
	ifstream file;//输入流文件
	file.open(FilePath,ios::in);
	
	if (!file)
	{
		MessageBox("Cannot open file!");
		return;
	}
	save.clear();
	while(!file.eof())
	{
		item = new Information;
		string id, name, sex, card, level, time, like, remarks;
		file >> id >> name >> sex >> card >> level >> time >> like >> remarks;
		
		if (id.empty())
		{
			file.close();
			break;
		}
		
		item->I_id.Format("%s",id.c_str());
		item->I_name.Format("%s",name.c_str());
		item->I_sex.Format("%s",sex.c_str());
		item->I_card.Format("%s",card.c_str());
		item->I_level.Format("%s",level.c_str());
		item->I_time.Format("%s",time.c_str());
		item->I_like.Format("%s",like.c_str());
		item->I_remarks.Format("%s",remarks.c_str());
		save.push_back(item);
	}

	initList();
	initTree();
}

void CZHN_TEST2_1Dlg::initList()
{
	CListCtrl* lCtrl;
	lCtrl=(CListCtrl*)GetDlgItem(IDC_LIST1);
    lCtrl->DeleteAllItems();

	//for(store=save.end()-1;store!=save.begin();--store)
	for(int i=save.size()-1;i >= 0; i--)
	{
		//store = save[i];
		int row = lCtrl->InsertItem(0,(save[i])->I_id);
		lCtrl->SetItemText(row,1,(save[i])->I_name);
		lCtrl->SetItemText(row,2,(save[i])->I_sex);
		lCtrl->SetItemText(row,3,(save[i])->I_card);
		lCtrl->SetItemText(row,4,(save[i])->I_level);
		lCtrl->SetItemText(row,5,(save[i])->I_time);
		lCtrl->SetItemText(row,6,(save[i])->I_like);
		lCtrl->SetItemText(row,7,(save[i])->I_remarks);
	}
}

void CZHN_TEST2_1Dlg::initTree()
{
	CString h_lev[100],m_lev[100],l_lev[100];
	int h_shu=0,m_shu=0,l_shu=0;
	for (store=save.begin();store!=save.end();++store)
	{
		if(((*store)->I_level)=="高级")
		{
			h_lev[h_shu]=((*store)->I_id);
			h_shu++;
		}
		else if (((*store)->I_level)=="中级")
		{
			m_lev[m_shu]=((*store)->I_id);
			m_shu++;
		}
		else
		{
			l_lev[l_shu]=((*store)->I_id);
			l_shu++;
		}
	}

	CTreeCtrl* myTree=(CTreeCtrl*)GetDlgItem(IDC_TREE1);  //设置style
	myTree->DeleteAllItems();
	myTree->ModifyStyle(0,TVS_EDITLABELS|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);
	
	//树控件中插入信息
	myTree->SetImageList(&m_ImageList,LVSIL_NORMAL);
	for (int k=0;k<3;k++)
	{
		if (k==0)
		{
			TV_INSERTSTRUCT TCitem;
			TCitem.hParent=TVI_ROOT;
			TCitem.hInsertAfter=TVI_LAST;
			TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			TCitem.item.pszText="高级会员";
			TCitem.item.lParam=0;
			TCitem.item.iImage=0;
			TCitem.item.iSelectedImage=1;
			HTREEITEM rootItem=myTree->InsertItem(&TCitem);
			
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
				HTREEITEM childItem=myTree->InsertItem(&TCSubItem);
			}
			myTree->Expand(rootItem,TVE_EXPAND);
		}
		else if(k==1)
		{
			TV_INSERTSTRUCT TCitem;
			TCitem.hParent=TVI_ROOT;
			TCitem.hInsertAfter=TVI_LAST;
			TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			TCitem.item.pszText="中级会员";
			TCitem.item.lParam=0;
			TCitem.item.iImage=0;
			TCitem.item.iSelectedImage=1;
			HTREEITEM rootItem=myTree->InsertItem(&TCitem);
			
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
				HTREEITEM childItem=myTree->InsertItem(&TCSubItem);
			}
			myTree->Expand(rootItem,TVE_EXPAND);
		}
		else
		{
			TV_INSERTSTRUCT TCitem;
			TCitem.hParent=TVI_ROOT;
			TCitem.hInsertAfter=TVI_LAST;
			TCitem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			TCitem.item.pszText="低级会员";
			TCitem.item.lParam=0;
			TCitem.item.iImage=0;
			TCitem.item.iSelectedImage=1;
			HTREEITEM rootItem=myTree->InsertItem(&TCitem);
			
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
				HTREEITEM childItem=myTree->InsertItem(&TCSubItem);
			}
			myTree->Expand(rootItem,TVE_EXPAND);
		}
	}
}

void CZHN_TEST2_1Dlg::WriteFile()
{
	item = new Information;
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

void CZHN_TEST2_1Dlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	// TODO: 在此添加控件通知处理程序代码
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	CTreeCtrl* myTree=(CTreeCtrl*)GetDlgItem(IDC_TREE1);
	HTREEITEM Hitem;
	Hitem=NULL;
	Hitem=myTree->GetSelectedItem();
	m_EditItem=myTree->GetItemText(Hitem);
	UpdateData(FALSE);
	
	//for(store=save.end()-1;store!=save.begin()-1;--store)
	for(int i=save.size()-1;i >= 0; i--)
	{
		if (((save[i])->I_id)==m_EditItem)
		{
			((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText((save[i])->I_id);
			((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText((save[i])->I_name);
			((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText((save[i])->I_sex);
			((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText((save[i])->I_card);
			((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText((save[i])->I_level);
			((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText((save[i])->I_time);
			((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText((save[i])->I_like);
			((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText((save[i])->I_remarks);
			I_indexT=m_EditItem;   //传递树节点的位置
			clickList=true;
		}
	}

	*pResult = 0;
}


void CZHN_TEST2_1Dlg::OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CTreeCtrl* myTree=(CTreeCtrl*)GetDlgItem(IDC_TREE1);
	CPoint   point(GetMessagePos()); 	
    unsigned   int   nFlags = 0; 	
    myTree->ScreenToClient(&point); 	
    HTREEITEM hItem=myTree->HitTest(point,&nFlags); 	
    if  ((nFlags& TVHT_ONITEM) &&(hItem!=NULL))
		
    { 		
		myTree->SetFocus(); 		
		myTree->SelectItem(hItem); 	
		
		CMenu *pSubMenu;
		menu.LoadMenu(IDR_MENU3);
		pSubMenu = menu.GetSubMenu(0);
		CPoint point;
		GetCursorPos(&point);
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, point.x, point.y, this);

		pSubMenu->DestroyMenu();
		menu.DestroyMenu();

		
    }
	
	*pResult = 0;
}


void CZHN_TEST2_1Dlg::On32776()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedButton1();
}


void CZHN_TEST2_1Dlg::On32777()
{
	// TODO: 在此添加命令处理程序代码
	On32773();
}

void CZHN_TEST2_1Dlg::xiaohui()
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

void CZHN_TEST2_1Dlg::fileListOut(int f_index)
{
	vector<Information*>::iterator it= save.begin()+f_index;
	save.erase(it);

	reFile();
}

void CZHN_TEST2_1Dlg::fileTreeOut(CString f_indexT)
{
	for(store=save.begin();store!=save.end();)
	{
		
        if(((*store)->I_id)==f_indexT){
			
            store=save.erase(store);
			
        }else{
			
            store++;
			
        }
	}

	reFile();
}

void CZHN_TEST2_1Dlg::reFile()
{
	item = new Information;
	ofstream file;
	file.open("会员数据.txt",ios::out|ios::ate);
	if (!file)
	{
		MessageBox("Cannot open file!");
		return;
	}
	for (store=save.begin();store!=save.end();++store)
	{
		file <<(LPCTSTR)(*store)->I_id<<" "<<(LPCTSTR)(*store)->I_name<<" "<<(LPCTSTR)(*store)->I_sex<<" "<<(LPCTSTR)(*store)->I_card
			<<" "<<(LPCTSTR)(*store)->I_level<<" "<<(LPCTSTR)(*store)->I_time<<" "<<(LPCTSTR)(*store)->I_like<<" "<<(LPCTSTR)(*store)->I_remarks<<"\n";
	}
	
	file.close();
}