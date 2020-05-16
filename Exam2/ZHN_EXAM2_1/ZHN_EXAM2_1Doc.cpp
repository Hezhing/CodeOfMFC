
// ZHN_EXAM2_1Doc.cpp : CZHN_EXAM2_1Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZHN_EXAM2_1.h"
#endif

#include "ZHN_EXAM2_1Doc.h"

#include <propkey.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZHN_EXAM2_1Doc

IMPLEMENT_DYNCREATE(CZHN_EXAM2_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CZHN_EXAM2_1Doc, CDocument)
END_MESSAGE_MAP()


// CZHN_EXAM2_1Doc ����/����

CZHN_EXAM2_1Doc::CZHN_EXAM2_1Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CZHN_EXAM2_1Doc::~CZHN_EXAM2_1Doc()
{
}

BOOL CZHN_EXAM2_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	// ��ʼ������

	// 1.�Է�
	fanData.PerMoney = 0.1;
	fanData.R = 0;
	fanData.G = 0;
	fanData.B = 255;
	fanData.name = TEXT("�Է�");
	fanData.idb = IDB_BITMAP2;
	fd.push_back(fanData);

	// 2.�·�
	fanData.PerMoney = 0.25;
	fanData.R = 50;
	fanData.G = 201;
	fanData.B = 50;
	fanData.name = TEXT("�·�");
	fanData.idb = IDB_BITMAP4;
	fd.push_back(fanData);

	// 3.����
	fanData.PerMoney = 0.3;
	fanData.R = 255;
	fanData.G = 0;
	fanData.B = 255;
	fanData.name = TEXT("����");
	fanData.idb = IDB_BITMAP3;
	fd.push_back(fanData);

	// 4.����
	fanData.PerMoney = 0.15;
	fanData.R = 0;
	fanData.G = 255;
	fanData.B = 255;
	fanData.name = TEXT("����");
	fanData.idb = IDB_BITMAP5;
	fd.push_back(fanData);

	// 5.����
	fanData.PerMoney = 0.2;
	fanData.R = 100;
	fanData.G = 0;
	fanData.B = 255;
	fanData.name = TEXT("����");
	fanData.idb = IDB_BITMAP1;
	fd.push_back(fanData);


	return TRUE;
}

void CZHN_EXAM2_1Doc:: AddData(CString name,float PerMoney,int R,int G,int B)
{
	fanData.name = name;
	fanData.PerMoney = PerMoney;
	fanData.R = R;
	fanData.G = G;
	fanData.B = B;
	fd.push_back(fanData);
	CalculatePer();

	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}

void CZHN_EXAM2_1Doc::MyUpDateView()
{
	UpdateAllViews(NULL);
}

void CZHN_EXAM2_1Doc::CalculatePer()
{
	float sumMoney = 0.0;
	for(int i=0;i<(fd.size());i++)
	{
		sumMoney += fd[i].PerMoney;
	}

	for(int i=0;i<(fd.size());i++)
	{
		fd[i].PerMoney = fd[i].PerMoney/sumMoney;	
	}
}

// CZHN_EXAM2_1Doc ���л�

void CZHN_EXAM2_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CZHN_EXAM2_1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CZHN_EXAM2_1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CZHN_EXAM2_1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CZHN_EXAM2_1Doc ���

#ifdef _DEBUG
void CZHN_EXAM2_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZHN_EXAM2_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CZHN_EXAM2_1Doc ����
