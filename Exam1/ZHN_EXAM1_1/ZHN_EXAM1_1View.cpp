
// ZHN_EXAM1_1View.cpp : CZHN_EXAM1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZHN_EXAM1_1View ����/����

CZHN_EXAM1_1View::CZHN_EXAM1_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CZHN_EXAM1_1View::~CZHN_EXAM1_1View()
{
}

BOOL CZHN_EXAM1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZHN_EXAM1_1View ����

void CZHN_EXAM1_1View::OnDraw(CDC* pDC)
{
	image.myPoint(pDC);
	CString str;
	pDC->SetTextColor(RGB(0,0,0));
	str.Format(_T("2018��һ���û�����ͼ"));
	pDC->DrawText(str,CRect(200,100,400,400),DT_LEFT);

	CZHN_EXAM1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// CZHN_EXAM1_1View ��ӡ

BOOL CZHN_EXAM1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CZHN_EXAM1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CZHN_EXAM1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CZHN_EXAM1_1View ���

#ifdef _DEBUG
void CZHN_EXAM1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CZHN_EXAM1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZHN_EXAM1_1Doc* CZHN_EXAM1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_EXAM1_1Doc)));
	return (CZHN_EXAM1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_EXAM1_1View ��Ϣ�������



