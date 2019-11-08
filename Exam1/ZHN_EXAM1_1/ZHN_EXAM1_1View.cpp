
// ZHN_EXAM1_1View.cpp : CZHN_EXAM1_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZHN_EXAM1_1.h"
#endif

#include "ZHN_EXAM1_1Doc.h"
#include "ZHN_EXAM1_1View.h"
#include "math.h"
#include "MyImage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZHN_EXAM1_1View

IMPLEMENT_DYNCREATE(CZHN_EXAM1_1View, CView)

BEGIN_MESSAGE_MAP(CZHN_EXAM1_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZHN_EXAM1_1View 构造/析构

CZHN_EXAM1_1View::CZHN_EXAM1_1View()
{
	// TODO: 在此处添加构造代码

}

CZHN_EXAM1_1View::~CZHN_EXAM1_1View()
{
}

BOOL CZHN_EXAM1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZHN_EXAM1_1View 绘制

void CZHN_EXAM1_1View::OnDraw(CDC* pDC)
{
	image.myPoint(pDC);
	CString str;
	pDC->SetTextColor(RGB(0,0,0));
	str.Format(_T("2018年一月用户消费图"));
	pDC->DrawText(str,CRect(200,100,400,400),DT_LEFT);

	CZHN_EXAM1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	
}


// CZHN_EXAM1_1View 打印

BOOL CZHN_EXAM1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZHN_EXAM1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZHN_EXAM1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZHN_EXAM1_1View 诊断

#ifdef _DEBUG
void CZHN_EXAM1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CZHN_EXAM1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZHN_EXAM1_1Doc* CZHN_EXAM1_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_EXAM1_1Doc)));
	return (CZHN_EXAM1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_EXAM1_1View 消息处理程序



