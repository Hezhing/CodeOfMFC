
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "ZHN_TEST3_1.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	// 在this框架上拆分1行2列
	m_sWnd.CreateStatic(this,1,2);

	// 创建视图
	m_sWnd.CreateView(0,0,RUNTIME_CLASS(CUserTreeView),CSize(230,600),pContext);

	// 在m_sWnd框架上拆分第二列的数据为2行1列
	m_sWnd1.CreateStatic(&m_sWnd,2,1,WS_CHILD|WS_VISIBLE,m_sWnd.IdFromRowCol(0, 1));
	m_sWnd1.CreateView(0,0,RUNTIME_CLASS(CUserFormView),CSize(50,500),pContext);
	m_sWnd1.CreateView(1,0,RUNTIME_CLASS(CMedicListView),CSize(50,200),pContext);
	

	// 把默认创建客户区（视图）屏蔽。
	return TRUE;
	// return CFrameWnd::OnCreateClient(lpcs, pContext);
}
