
// ZHN_TEST1_3View.cpp : CZHN_TEST1_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZHN_TEST1_3.h"
#endif

#include "ZHN_TEST1_3Doc.h"
#include "ZHN_TEST1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZHN_TEST1_3View

IMPLEMENT_DYNCREATE(CZHN_TEST1_3View, CView)

BEGIN_MESSAGE_MAP(CZHN_TEST1_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RANDOM_NUM, &CZHN_TEST1_3View::OnRandomNum)

	ON_WM_TIMER()
	ON_COMMAND(ID_BUBBLE_SORT, &CZHN_TEST1_3View::OnBubbleSort)
	ON_COMMAND(ID_INSERT_SORT, &CZHN_TEST1_3View::OnInsertSort)
	ON_COMMAND(ID_SELECT_SORT, &CZHN_TEST1_3View::OnSelectSort)
	ON_COMMAND(ID_START_SORT, &CZHN_TEST1_3View::OnStartSort)
	ON_COMMAND(ID_END_SORT, &CZHN_TEST1_3View::OnEndSort)
	ON_UPDATE_COMMAND_UI(ID_BUBBLE_SORT, &CZHN_TEST1_3View::OnUpdateBubbleSort)
	ON_UPDATE_COMMAND_UI(ID_INSERT_SORT, &CZHN_TEST1_3View::OnUpdateInsertSort)
	ON_UPDATE_COMMAND_UI(ID_SELECT_SORT, &CZHN_TEST1_3View::OnUpdateSelectSort)
	ON_COMMAND(ID_SORT_STEP, &CZHN_TEST1_3View::OnSortStep)
	ON_UPDATE_COMMAND_UI(ID_SORT_STEP, &CZHN_TEST1_3View::OnUpdateSortStep)
END_MESSAGE_MAP()

// CZHN_TEST1_3View 构造/析构

CZHN_TEST1_3View::CZHN_TEST1_3View()
{
	// TODO: 在此处添加构造代码
	//变量初始化
	Bubble = FALSE;
	Select = FALSE;
	Insert = FALSE;
	SortOnTime = FALSE;
	SortStep = FALSE;
	Specialnum = 0;

	//画笔颜色初始化为黑色
	m_draw = true;
	m_pen.CreatePen(PS_SOLID, 10, RGB(0,0,0));

	//画笔字体初始化
	m_font.CreateFont(
		25,10,0,0,100,
		FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,_T("宋体"));
}

CZHN_TEST1_3View::~CZHN_TEST1_3View()
{
}

BOOL CZHN_TEST1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZHN_TEST1_3View 绘制

void CZHN_TEST1_3View::OnDraw(CDC* /*pDC*/)
{
	
	//调用绘制数字函数
	DrawNum();

	CZHN_TEST1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// CZHN_TEST1_3View 打印

BOOL CZHN_TEST1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZHN_TEST1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZHN_TEST1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZHN_TEST1_3View 诊断

#ifdef _DEBUG
void CZHN_TEST1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZHN_TEST1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZHN_TEST1_3Doc* CZHN_TEST1_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_TEST1_3Doc)));
	return (CZHN_TEST1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_TEST1_3View 消息处理程序

void CZHN_TEST1_3View::OnRandomNum()
{
	//随机数组
	ranNumCount = rand()%10 + 10;
	m_nums = new int[ranNumCount];
	for(int i=0;i<ranNumCount;i++)
	{
		m_nums[i] = rand() % 35 + 1;
	}
	Invalidate();
}

void CZHN_TEST1_3View::DrawNum(void)
{
	m_pdc = GetDC();

	//操作说明
	CString about;
	m_pdc->SetTextColor(RGB(255, 0, 0));
	about.Format(_T("操作说明:\n      1.排序算法目前实现了冒泡排序、选择排序和插入排序\n      2.生成随机数可以生成随机数量的随机数\n      3.演示方式可以进行单步执行和直接执行，点击单步执行后，点击\n开始可单步执行，再次点击单步执行后，点击开始则可直接执行\n"));
	m_pdc->DrawTextW(about,  CRect(750, 50, 1600, 600),DT_LEFT);
	
	//画笔设置（比较和被比较的数字）
	m_pdc->SelectObject(&m_pen);
	int startx = 100,starty=GetSystemMetrics(SM_CYFULLSCREEN) / 2;
	int intervalWidth = 50;
	CPen pen1,pen2;
	pen1.CreatePen(PS_SOLID, 10, RGB(255,0,0));
	pen2.CreatePen(PS_SOLID, 10, RGB(0,255,0));

	if(m_draw){
		for(int i=0;i<ranNumCount;i++){
			int endx = starty - m_nums[i] * 17, endy = starty - m_nums[i] * 10;
			if(i == first_num ){ //表示为比较的数字

				CString first;
				m_pdc->SetTextColor(RGB(255, 0, 0));
				first.Format(_T("Number of swaps = %d"),m_nums[i]);
				m_pdc->DrawText(first,CRect(100, 630, 300, 550), DT_SINGLELINE | DT_LEFT | DT_VCENTER);
				m_pdc->SelectObject(&pen1);

			}else if(i == next_num){ //表示为被比较的数字

				CString next;
				m_pdc->SetTextColor(RGB(0, 255, 0));
				next.Format(_T("Number of comparisions = %d"),m_nums[i]);
				m_pdc->DrawText(next,CRect(100, 670, 400, 580), DT_SINGLELINE | DT_LEFT | DT_VCENTER);

				m_pdc->SelectObject(&pen2);
			}else  //其他未参与比较的数字
			{
				m_pdc->SetTextColor(RGB(0, 0, 0));
				m_pdc->SelectObject(&m_pen);
			}

			// 图
			m_pdc->MoveTo(startx, starty);
			m_pdc->LineTo(startx, endy);

			// 数字
			CString str;
			str.Format(_T("%d"),m_nums[i]);
			m_pdc->TextOutW(startx -10,starty +20,str);
			startx += intervalWidth;
		}
	}
}


void CZHN_TEST1_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//判断排序

	if(nIDEvent == ID_TIMER_BUBBLE){
		if(m_nums[m_first] > m_nums[m_first+1]) //冒泡排序数字交换
		{
			swap(m_first, m_first+1);
		}
		m_first ++;
		first_num = m_first; //记录比较数字下标
		next_num = m_first+1; //记录被比较数字下标
		if (m_first > ranNumCount - m_next -2) //循环比较过程
		{
			m_next ++;
			m_first = 0;
			first_num = m_first;
			next_num = m_first+1;

			if (m_next >= ranNumCount -1 ) //表示冒泡排序完成
			{
				KillTimer(ID_TIMER_BUBBLE);
				first_num = ranNumCount + 1;
				next_num = ranNumCount + 1;
				Invalidate();
				MessageBox(_T("冒泡排序已完成"));
			}
		}
		if (SortStep)  //判断是否单步运行
		{
			KillTimer(ID_TIMER_BUBBLE);
		}
		Invalidate();
	}
	if(nIDEvent == ID_TIMER_SELECT)
	{
		if(m_nums[first_num] > m_nums[m_first + 1]){ //选择排序过程
			first_num = m_first + 1;
			Specialnum = m_nums[m_first + 1];  //记录最小的那个数
		}
		m_first ++;
		next_num = m_first + 1; //记下被比较数下标
		
		if(m_first > ranNumCount -1){
			swap(m_next,first_num);
			m_next++;
			m_first=m_next;
			first_num=m_next;

			if(m_next >= ranNumCount -1) //判断选择排序是否结束
			{
				first_num = ranNumCount + 1;
				next_num = ranNumCount + 1;
				Invalidate();
				KillTimer(ID_TIMER_SELECT);
				MessageBox(_T("选择排序已完成"));
			}
		}
		if(SortStep) //判断是否单步运行
		{
			KillTimer(ID_TIMER_SELECT);
		}
		Invalidate();
	}
	if(nIDEvent == ID_TIMER_INSERT) //插入排序过程
	{
		if(m_nums[first_num] > m_nums[next_num]){
			if(first_num == 0){
				int buf = m_nums[next_num];
				for(int i=next_num;i>0;i--){ //依次后移
					m_nums[i] = m_nums[i-1];
				}
				m_nums[0] = buf;
				next_num ++;
				first_num = next_num - 1;  //记录下标
			}else {
				if(m_nums[first_num - 1] <= m_nums[next_num]){
					int buf = m_nums[next_num];
					for(int i=next_num; i>=first_num; i--){ //依次后移
						m_nums[i] = m_nums[i-1];
					}
					m_nums[first_num] = buf;
					next_num ++;
					first_num = next_num - 1;
				}else{
					first_num --;
				}
			}
		}else {
			first_num --;
		}
		if(first_num < 0){
			next_num ++;
			first_num = next_num - 1;
		}
		if(next_num >= ranNumCount){ //判断选择排序是否结束
			first_num = ranNumCount + 1;
			next_num = ranNumCount + 1;
			Invalidate();
			KillTimer(ID_TIMER_INSERT);
			MessageBox(_T("直接插入排序已完成"));
		}
		if (SortStep) //判断是否单步
		{
			KillTimer(ID_TIMER_INSERT);
		}
		Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}


void CZHN_TEST1_3View::OnBubbleSort()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);
	
	Bubble = TRUE;
	Select = FALSE;
	Insert = FALSE;


	SortStep = FALSE;
	SortOnTime = FALSE;

	m_first = 0; //初始值下标
	m_next = 0;
	Specialnum = 0;
	first_num = 0; //交换值下标
	next_num = 1;

	
}

void CZHN_TEST1_3View::swap(int x,int y)
{
	int a = m_nums[x];
	m_nums[x] = m_nums[y];
	m_nums[y] = a;
}

void CZHN_TEST1_3View::OnInsertSort()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);

	Bubble = FALSE;
	Select = FALSE;
	Insert = TRUE;


	first_num = 0; //交换值下标
	next_num = 1;
}



void CZHN_TEST1_3View::OnSelectSort()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);

	Bubble = FALSE;
	Select = TRUE;
	Insert = FALSE;

	SortStep = FALSE;
	SortOnTime = FALSE;

	m_first = 0; //初始值下标
	m_next = 0;
	Specialnum = 0;
	first_num = 0; //交换值下标
	next_num = 1;

}


void CZHN_TEST1_3View::OnStartSort()
{
	// TODO: 在此添加命令处理程序代码

	if(Bubble){
		SetTimer(ID_TIMER_BUBBLE,1000,0);
	}else if(Select){
		SetTimer(ID_TIMER_SELECT,1000,0);
	}else if(Insert){
		SetTimer(ID_TIMER_INSERT,1000,0);
	}

}


void CZHN_TEST1_3View::OnEndSort()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);
	first_num = -1;
	next_num = -1;
	Invalidate();
}


void CZHN_TEST1_3View::OnUpdateBubbleSort(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(Bubble);
}


void CZHN_TEST1_3View::OnUpdateInsertSort(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(Insert);
}


void CZHN_TEST1_3View::OnUpdateSelectSort(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(Select);
}


void CZHN_TEST1_3View::OnSortStep()
{
	// TODO: 在此添加命令处理程序代码
	SortStep = !SortStep;
	SortOnTime = FALSE;
}


void CZHN_TEST1_3View::OnUpdateSortStep(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(SortStep);
}
