
// ZHN_TEST3_1Doc.cpp : CZHN_TEST3_1Doc 类的实现
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

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZHN_TEST3_1Doc

IMPLEMENT_DYNCREATE(CZHN_TEST3_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CZHN_TEST3_1Doc, CDocument)
	ON_COMMAND(ID_32775, &CZHN_TEST3_1Doc::On32775OpenFile)
END_MESSAGE_MAP()


// CZHN_TEST3_1Doc 构造/析构

CZHN_TEST3_1Doc::CZHN_TEST3_1Doc()
{
	// TODO: 在此添加一次性构造代码
	
}

CZHN_TEST3_1Doc::~CZHN_TEST3_1Doc()
{
}

BOOL CZHN_TEST3_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	
	return TRUE;
}




// CZHN_TEST3_1Doc 序列化

void CZHN_TEST3_1Doc::Serialize(CArchive& ar)
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
void CZHN_TEST3_1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CZHN_TEST3_1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CZHN_TEST3_1Doc::SetSearchContent(const CString& value)
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

// CZHN_TEST3_1Doc 诊断

#ifdef _DEBUG
void CZHN_TEST3_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZHN_TEST3_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CZHN_TEST3_1Doc 命令

void CZHN_TEST3_1Doc::OpenFile(CString FilePath)
{

	ifstream file;
	file.open("会员数据.txt",ios::in);
	if(!file)
	{
		//MessageBox("Cannot open file!");
		return ;
	}
	save.clear();
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
		item.I_id = s;
		s.Format(_T("%s"),name.c_str());
		item.I_name = s;
		s.Format(_T("%s"),sex.c_str());
		item.I_sex = s;
		s.Format(_T("%s"),card.c_str());
		item.I_card = s;
		s.Format(_T("%s"),level.c_str());
		item.I_level = s;
		s.Format(_T("%s"),time.c_str());
		item.I_time = s;
		s.Format(_T("%s"),like.c_str());
		item.I_like = s;
		s.Format(_T("%s"),remarks.c_str());
		item.I_remarks = s;
		save.push_back(item);
	}

	UpdateAllViews(NULL);
}

void CZHN_TEST3_1Doc::On32775OpenFile()
{
	CZHN_TEST3_1Doc *pDoc;
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

	UpdateAllViews(NULL);
}

void CZHN_TEST3_1Doc::OpenFiles()
{
	ifstream file;
	file.open("会员数据.txt",ios::in);
	if(!file)
	{
		//MessageBox("Cannot open file!");
		return ;
	}
	save.clear();
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
		item.I_id = s;
		s.Format(_T("%s"),name.c_str());
		item.I_name = s;
		s.Format(_T("%s"),sex.c_str());
		item.I_sex = s;
		s.Format(_T("%s"),card.c_str());
		item.I_card = s;
		s.Format(_T("%s"),level.c_str());
		item.I_level = s;
		s.Format(_T("%s"),time.c_str());
		item.I_time = s;
		s.Format(_T("%s"),like.c_str());
		item.I_like = s;
		s.Format(_T("%s"),remarks.c_str());
		item.I_remarks = s;
		save.push_back(item);
	}

	UpdateAllViews(NULL);
}
