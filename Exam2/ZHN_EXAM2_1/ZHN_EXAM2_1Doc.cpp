
// ZHN_EXAM2_1Doc.cpp : CZHN_EXAM2_1Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CZHN_EXAM2_1Doc 构造/析构

CZHN_EXAM2_1Doc::CZHN_EXAM2_1Doc()
{
	// TODO: 在此添加一次性构造代码

}

CZHN_EXAM2_1Doc::~CZHN_EXAM2_1Doc()
{
}

BOOL CZHN_EXAM2_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	// 初始化数据

	// 1.吃饭
	fanData.PerMoney = 0.1;
	fanData.R = 0;
	fanData.G = 0;
	fanData.B = 255;
	fanData.name = TEXT("吃饭");
	fanData.idb = IDB_BITMAP2;
	fd.push_back(fanData);

	// 2.衣服
	fanData.PerMoney = 0.25;
	fanData.R = 50;
	fanData.G = 201;
	fanData.B = 50;
	fanData.name = TEXT("衣服");
	fanData.idb = IDB_BITMAP4;
	fd.push_back(fanData);

	// 3.娱乐
	fanData.PerMoney = 0.3;
	fanData.R = 255;
	fanData.G = 0;
	fanData.B = 255;
	fanData.name = TEXT("娱乐");
	fanData.idb = IDB_BITMAP3;
	fd.push_back(fanData);

	// 4.教育
	fanData.PerMoney = 0.15;
	fanData.R = 0;
	fanData.G = 255;
	fanData.B = 255;
	fanData.name = TEXT("教育");
	fanData.idb = IDB_BITMAP5;
	fd.push_back(fanData);

	// 5.房贷
	fanData.PerMoney = 0.2;
	fanData.R = 100;
	fanData.G = 0;
	fanData.B = 255;
	fanData.name = TEXT("房贷");
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

// CZHN_EXAM2_1Doc 序列化

void CZHN_EXAM2_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CZHN_EXAM2_1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CZHN_EXAM2_1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CZHN_EXAM2_1Doc 诊断

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


// CZHN_EXAM2_1Doc 命令
