
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ����ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ��������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ�����ר�ô����/����û���

	// ��this����ϲ��1��2��
	m_sWnd.CreateStatic(this,1,2);

	// ������ͼ
	m_sWnd.CreateView(0,0,RUNTIME_CLASS(CUserTreeView),CSize(230,600),pContext);

	// ��m_sWnd����ϲ�ֵڶ��е�����Ϊ2��1��
	m_sWnd1.CreateStatic(&m_sWnd,2,1,WS_CHILD|WS_VISIBLE,m_sWnd.IdFromRowCol(0, 1));
	m_sWnd1.CreateView(0,0,RUNTIME_CLASS(CUserFormView),CSize(50,500),pContext);
	m_sWnd1.CreateView(1,0,RUNTIME_CLASS(CMedicListView),CSize(50,200),pContext);
	

	// ��Ĭ�ϴ����ͻ�������ͼ�����Ρ�
	return TRUE;
	// return CFrameWnd::OnCreateClient(lpcs, pContext);
}