
// ZHN_TEST3_1View.cpp : CZHN_TEST3_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CZHN_TEST3_1View ����/����

CZHN_TEST3_1View::CZHN_TEST3_1View()
	: CFormView(CZHN_TEST3_1View::IDD)
{
	// TODO: �ڴ˴���ӹ������


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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CZHN_TEST3_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CZHN_TEST3_1View ���

#ifdef _DEBUG
void CZHN_TEST3_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CZHN_TEST3_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CZHN_TEST3_1Doc* CZHN_TEST3_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_TEST3_1Doc)));
	return (CZHN_TEST3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_TEST3_1View ��Ϣ�������


