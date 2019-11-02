
// ZHN_TEST1_3View.cpp : CZHN_TEST1_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZHN_TEST1_3.h"
#endif

#include "ZHN_TEST1_3Doc.h"
#include "ZHN_TEST1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZHN_TEST1_3View

IMPLEMENT_DYNCREATE(CZHN_TEST1_3View, CView)

BEGIN_MESSAGE_MAP(CZHN_TEST1_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RANDOM_NUM, &CZHN_TEST1_3View::OnRandomNum)

	ON_WM_TIMER()
	ON_COMMAND(ID_BUBBLE_SORT, &CZHN_TEST1_3View::OnBubbleSort)
	ON_COMMAND(ID_INSERT_SORT, &CZHN_TEST1_3View::OnInsertSort)
	ON_COMMAND(ID_SELECT_SORT, &CZHN_TEST1_3View::OnSelectSort)
	ON_COMMAND(ID_START_SORT, &CZHN_TEST1_3View::OnStartSort)
	ON_COMMAND(ID_END_SORT, &CZHN_TEST1_3View::OnEndSort)
	ON_UPDATE_COMMAND_UI(ID_BUBBLE_SORT, &CZHN_TEST1_3View::OnUpdateBubbleSort)
	ON_UPDATE_COMMAND_UI(ID_INSERT_SORT, &CZHN_TEST1_3View::OnUpdateInsertSort)
	ON_UPDATE_COMMAND_UI(ID_SELECT_SORT, &CZHN_TEST1_3View::OnUpdateSelectSort)
	ON_COMMAND(ID_SORT_STEP, &CZHN_TEST1_3View::OnSortStep)
	ON_UPDATE_COMMAND_UI(ID_SORT_STEP, &CZHN_TEST1_3View::OnUpdateSortStep)
END_MESSAGE_MAP()

// CZHN_TEST1_3View ����/����

CZHN_TEST1_3View::CZHN_TEST1_3View()
{
	// TODO: �ڴ˴���ӹ������
	//������ʼ��
	Bubble = FALSE;
	Select = FALSE;
	Insert = FALSE;
	SortOnTime = FALSE;
	SortStep = FALSE;
	Specialnum = 0;

	//������ɫ��ʼ��Ϊ��ɫ
	m_draw = true;
	m_pen.CreatePen(PS_SOLID, 10, RGB(0,0,0));

	//���������ʼ��
	m_font.CreateFont(
		25,10,0,0,100,
		FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,_T("����"));
}

CZHN_TEST1_3View::~CZHN_TEST1_3View()
{
}

BOOL CZHN_TEST1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZHN_TEST1_3View ����

void CZHN_TEST1_3View::OnDraw(CDC* /*pDC*/)
{
	
	//���û������ֺ���
	DrawNum();

	CZHN_TEST1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// CZHN_TEST1_3View ��ӡ

BOOL CZHN_TEST1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CZHN_TEST1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CZHN_TEST1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CZHN_TEST1_3View ���

#ifdef _DEBUG
void CZHN_TEST1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZHN_TEST1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZHN_TEST1_3Doc* CZHN_TEST1_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZHN_TEST1_3Doc)));
	return (CZHN_TEST1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZHN_TEST1_3View ��Ϣ�������

void CZHN_TEST1_3View::OnRandomNum()
{
	//�������
	ranNumCount = rand()%10 + 10;
	m_nums = new int[ranNumCount];
	for(int i=0;i<ranNumCount;i++)
	{
		m_nums[i] = rand() % 35 + 1;
	}
	Invalidate();
}

void CZHN_TEST1_3View::DrawNum(void)
{
	m_pdc = GetDC();

	//����˵��
	CString about;
	m_pdc->SetTextColor(RGB(255, 0, 0));
	about.Format(_T("����˵��:\n      1.�����㷨Ŀǰʵ����ð������ѡ������Ͳ�������\n      2.�������������������������������\n      3.��ʾ��ʽ���Խ��е���ִ�к�ֱ��ִ�У��������ִ�к󣬵��\n��ʼ�ɵ���ִ�У��ٴε������ִ�к󣬵����ʼ���ֱ��ִ��\n"));
	m_pdc->DrawTextW(about,  CRect(750, 50, 1600, 600),DT_LEFT);
	
	//�������ã��ȽϺͱ��Ƚϵ����֣�
	m_pdc->SelectObject(&m_pen);
	int startx = 100,starty=GetSystemMetrics(SM_CYFULLSCREEN) / 2;
	int intervalWidth = 50;
	CPen pen1,pen2;
	pen1.CreatePen(PS_SOLID, 10, RGB(255,0,0));
	pen2.CreatePen(PS_SOLID, 10, RGB(0,255,0));

	if(m_draw){
		for(int i=0;i<ranNumCount;i++){
			int endx = starty - m_nums[i] * 17, endy = starty - m_nums[i] * 10;
			if(i == first_num ){ //��ʾΪ�Ƚϵ�����

				CString first;
				m_pdc->SetTextColor(RGB(255, 0, 0));
				first.Format(_T("Number of swaps = %d"),m_nums[i]);
				m_pdc->DrawText(first,CRect(100, 630, 300, 550), DT_SINGLELINE | DT_LEFT | DT_VCENTER);
				m_pdc->SelectObject(&pen1);

			}else if(i == next_num){ //��ʾΪ���Ƚϵ�����

				CString next;
				m_pdc->SetTextColor(RGB(0, 255, 0));
				next.Format(_T("Number of comparisions = %d"),m_nums[i]);
				m_pdc->DrawText(next,CRect(100, 670, 400, 580), DT_SINGLELINE | DT_LEFT | DT_VCENTER);

				m_pdc->SelectObject(&pen2);
			}else  //����δ����Ƚϵ�����
			{
				m_pdc->SetTextColor(RGB(0, 0, 0));
				m_pdc->SelectObject(&m_pen);
			}

			// ͼ
			m_pdc->MoveTo(startx, starty);
			m_pdc->LineTo(startx, endy);

			// ����
			CString str;
			str.Format(_T("%d"),m_nums[i]);
			m_pdc->TextOutW(startx -10,starty +20,str);
			startx += intervalWidth;
		}
	}
}


void CZHN_TEST1_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	//�ж�����

	if(nIDEvent == ID_TIMER_BUBBLE){
		if(m_nums[m_first] > m_nums[m_first+1]) //ð���������ֽ���
		{
			swap(m_first, m_first+1);
		}
		m_first ++;
		first_num = m_first; //��¼�Ƚ������±�
		next_num = m_first+1; //��¼���Ƚ������±�
		if (m_first > ranNumCount - m_next -2) //ѭ���ȽϹ���
		{
			m_next ++;
			m_first = 0;
			first_num = m_first;
			next_num = m_first+1;

			if (m_next >= ranNumCount -1 ) //��ʾð���������
			{
				KillTimer(ID_TIMER_BUBBLE);
				first_num = ranNumCount + 1;
				next_num = ranNumCount + 1;
				Invalidate();
				MessageBox(_T("ð�����������"));
			}
		}
		if (SortStep)  //�ж��Ƿ񵥲�����
		{
			KillTimer(ID_TIMER_BUBBLE);
		}
		Invalidate();
	}
	if(nIDEvent == ID_TIMER_SELECT)
	{
		if(m_nums[first_num] > m_nums[m_first + 1]){ //ѡ���������
			first_num = m_first + 1;
			Specialnum = m_nums[m_first + 1];  //��¼��С���Ǹ���
		}
		m_first ++;
		next_num = m_first + 1; //���±��Ƚ����±�
		
		if(m_first > ranNumCount -1){
			swap(m_next,first_num);
			m_next++;
			m_first=m_next;
			first_num=m_next;

			if(m_next >= ranNumCount -1) //�ж�ѡ�������Ƿ����
			{
				first_num = ranNumCount + 1;
				next_num = ranNumCount + 1;
				Invalidate();
				KillTimer(ID_TIMER_SELECT);
				MessageBox(_T("ѡ�����������"));
			}
		}
		if(SortStep) //�ж��Ƿ񵥲�����
		{
			KillTimer(ID_TIMER_SELECT);
		}
		Invalidate();
	}
	if(nIDEvent == ID_TIMER_INSERT) //�����������
	{
		if(m_nums[first_num] > m_nums[next_num]){
			if(first_num == 0){
				int buf = m_nums[next_num];
				for(int i=next_num;i>0;i--){ //���κ���
					m_nums[i] = m_nums[i-1];
				}
				m_nums[0] = buf;
				next_num ++;
				first_num = next_num - 1;  //��¼�±�
			}else {
				if(m_nums[first_num - 1] <= m_nums[next_num]){
					int buf = m_nums[next_num];
					for(int i=next_num; i>=first_num; i--){ //���κ���
						m_nums[i] = m_nums[i-1];
					}
					m_nums[first_num] = buf;
					next_num ++;
					first_num = next_num - 1;
				}else{
					first_num --;
				}
			}
		}else {
			first_num --;
		}
		if(first_num < 0){
			next_num ++;
			first_num = next_num - 1;
		}
		if(next_num >= ranNumCount){ //�ж�ѡ�������Ƿ����
			first_num = ranNumCount + 1;
			next_num = ranNumCount + 1;
			Invalidate();
			KillTimer(ID_TIMER_INSERT);
			MessageBox(_T("ֱ�Ӳ������������"));
		}
		if (SortStep) //�ж��Ƿ񵥲�
		{
			KillTimer(ID_TIMER_INSERT);
		}
		Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}


void CZHN_TEST1_3View::OnBubbleSort()
{
	// TODO: �ڴ���������������
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);
	
	Bubble = TRUE;
	Select = FALSE;
	Insert = FALSE;


	SortStep = FALSE;
	SortOnTime = FALSE;

	m_first = 0; //��ʼֵ�±�
	m_next = 0;
	Specialnum = 0;
	first_num = 0; //����ֵ�±�
	next_num = 1;

	
}

void CZHN_TEST1_3View::swap(int x,int y)
{
	int a = m_nums[x];
	m_nums[x] = m_nums[y];
	m_nums[y] = a;
}

void CZHN_TEST1_3View::OnInsertSort()
{
	// TODO: �ڴ���������������
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);

	Bubble = FALSE;
	Select = FALSE;
	Insert = TRUE;


	first_num = 0; //����ֵ�±�
	next_num = 1;
}



void CZHN_TEST1_3View::OnSelectSort()
{
	// TODO: �ڴ���������������
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);

	Bubble = FALSE;
	Select = TRUE;
	Insert = FALSE;

	SortStep = FALSE;
	SortOnTime = FALSE;

	m_first = 0; //��ʼֵ�±�
	m_next = 0;
	Specialnum = 0;
	first_num = 0; //����ֵ�±�
	next_num = 1;

}


void CZHN_TEST1_3View::OnStartSort()
{
	// TODO: �ڴ���������������

	if(Bubble){
		SetTimer(ID_TIMER_BUBBLE,1000,0);
	}else if(Select){
		SetTimer(ID_TIMER_SELECT,1000,0);
	}else if(Insert){
		SetTimer(ID_TIMER_INSERT,1000,0);
	}

}


void CZHN_TEST1_3View::OnEndSort()
{
	// TODO: �ڴ���������������
	KillTimer(ID_TIMER_BUBBLE);
	KillTimer(ID_TIMER_SELECT);
	KillTimer(ID_TIMER_INSERT);
	first_num = -1;
	next_num = -1;
	Invalidate();
}


void CZHN_TEST1_3View::OnUpdateBubbleSort(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(Bubble);
}


void CZHN_TEST1_3View::OnUpdateInsertSort(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(Insert);
}


void CZHN_TEST1_3View::OnUpdateSelectSort(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(Select);
}


void CZHN_TEST1_3View::OnSortStep()
{
	// TODO: �ڴ���������������
	SortStep = !SortStep;
	SortOnTime = FALSE;
}


void CZHN_TEST1_3View::OnUpdateSortStep(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(SortStep);
}
