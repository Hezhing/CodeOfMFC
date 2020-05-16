
// ZHN_EXAM2_1View.cpp : CZHN_EXAM2_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZHN_EXAM2_1.h"
#endif

#include "ZHN_EXAM2_1Doc.h"
#include "ZHN_EXAM2_1View.h"
#include "MyImage.h"
#include "NewObject.h"
#include "ManagerObject.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZHN_EXAM2_1View

IMPLEMENT_DYNCREATE(CZHN_EXAM2_1View, CView)

BEGIN_MESSAGE_MAP(CZHN_EXAM2_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
ON_WM_LBUTTONDBLCLK()
ON_COMMAND(ID_32771, &CZHN_EXAM2_1View::OnNewObj)
ON_COMMAND(ID_32772, &CZHN_EXAM2_1View::OnManagerObj)
END_MESSAGE_MAP()

// CZHN_EXAM2_1View 构造/析构

CZHN_EXAM2_1View::CZHN_EXAM2_1View()
{
	// TODO: 在此处添加构造代码

}

CZHN_EXAM2_1View::~CZHN_EXAM2_1View()
{
}

BOOL CZHN_EXAM2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZHN_EXAM2_1View 绘制

void CZHN_EXAM2_1View::OnDraw(CDC* pDC)
{
	CZHN_EXAM2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CString str;
	pDC->SetTextColor(RGB(0,0,0));
	str.Format(_T("2018年一月用户消费图"));
	pDC->DrawText(str,CRect(200,100,400,400),DT_LEFT);

	CMyImage image(pDC);

	// TODO: 在此处为本机数据添加绘制代码)
	for(int i=0;i<(pDoc->fd.size());i++)
	{
		image.DrawImage(pDC,pDoc->fd[i].PerMoney,pDoc->fd[i].R,pDoc->fd[i].G,pDoc->fd[i].B,pDoc->fd[i].name,pDoc->fd[i].idb);
	}
	for (int i=0,j=50;i<(pDoc->fd.size());i++)
	{
		image.DrawMark(pDC,pDoc->fd[i].R,pDoc->fd[i].G,pDoc->fd[i].B,pDoc->fd[i].name,500,j,520,j+20);
		j = j+40;
	}
}


// CZHN_EXAM2_1View 打印

BOOL CZHN_EXAM2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZHN_EXAM2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZHN_EXAM2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZHN_EXAM2_1View 诊断

#ifdef _DEBUG
void CZHN_EXAM2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CZHN_EXAM2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZHN_EXAM2_1Doc* CZHN_EXAM2_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_EXAM2_1Doc)));
	return (CZHN_EXAM2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_EXAM2_1View 消息处理程序





void CZHN_EXAM2_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDblClk(nFlags, point);

	if(sqrt((point.x-300)*(point.x-300) + (point.y-300)*(point.y-300)) <= 100)
	{

		a = sqrt((400-point.x)*(400-point.x) + (300-point.y)*(300-point.y));
		b = sqrt((400-300)*(400-300) + (300-300)*(300-300));
		c = sqrt((point.x-300)*(point.x-300) + (point.y-300)*(point.y-300));

		cosNum = (b*b+c*c-a*a)/(2*b*c);
		preNum = acos(cosNum)/(2*3.14);
		

		/*CString s;
		s.Format(_T("%.2f"),preNum);
		MessageBox(s);*/

		if(point.y<300)
		{
			compareNum = preNum;
		}
		else if(point.y>=300)
		{
			compareNum = 1-preNum;
		}
		
		/*CString s;
		s.Format(_T("%.2f"),compareNum);
		MessageBox(s);*/
		CZHN_EXAM2_1Doc* pDoc = GetDocument();

		Num = 0.0;

		for(int i=0;i<pDoc->fd.size();i++)
		{
			Num = Num + pDoc->fd[i].PerMoney;

			if(compareNum < Num)
			{
				CNewObject newObj;
				newObj.ModifyObj(i,pDoc->fd[i].name,pDoc->fd[i].PerMoney,pDoc->fd[i].R,pDoc->fd[i].G,pDoc->fd[i].B);
				newObj.DoModal();
				break;
			}
			else
			{
				continue;
			}
		}
		
		
	}
}


void CZHN_EXAM2_1View::OnNewObj()
{
	// TODO: 在此添加命令处理程序代码
	CNewObject newObj;
	newObj.DoModal();
}


void CZHN_EXAM2_1View::OnManagerObj()
{
	// TODO: 在此添加命令处理程序代码
	CManagerObject manObj;
	manObj.DoModal();
}
