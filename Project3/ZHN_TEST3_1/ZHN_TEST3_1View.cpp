
// ZHN_TEST3_1View.cpp : CZHN_TEST3_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZHN_TEST3_1.h"
#endif

#include "ZHN_TEST3_1Doc.h"
#include "ZHN_TEST3_1View.h"

#include <fstream>
#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZHN_TEST3_1View

IMPLEMENT_DYNCREATE(CZHN_TEST3_1View, CFormView)

BEGIN_MESSAGE_MAP(CZHN_TEST3_1View, CFormView)
END_MESSAGE_MAP()

// CZHN_TEST3_1View 构造/析构

CZHN_TEST3_1View::CZHN_TEST3_1View()
	: CFormView(CZHN_TEST3_1View::IDD)
{
	// TODO: 在此处添加构造代码


}

CZHN_TEST3_1View::~CZHN_TEST3_1View()
{
}

void CZHN_TEST3_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CZHN_TEST3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CZHN_TEST3_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CZHN_TEST3_1View 诊断

#ifdef _DEBUG
void CZHN_TEST3_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CZHN_TEST3_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CZHN_TEST3_1Doc* CZHN_TEST3_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_TEST3_1Doc)));
	return (CZHN_TEST3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_TEST3_1View 消息处理程序


