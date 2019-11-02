
// ZHN_TEST1_3View.h : CZHN_TEST1_3View 类的接口
//

#pragma once


class CZHN_TEST1_3View : public CView
{
protected: // 仅从序列化创建
	CZHN_TEST1_3View();
	DECLARE_DYNCREATE(CZHN_TEST1_3View)

// 特性
public:
	CZHN_TEST1_3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CZHN_TEST1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnRandomNum();
	void DrawNum(void);
	void swap(int m, int n);

	int *m_nums;
	int ranNumCount;
	
	int m_first;
	int m_next;
	int first_num;
	int next_num;
	int Specialnum;

	
	int startx;
	int starty;
	int intervalWidth;


	bool Select;
	bool Insert;
	bool Bubble;
	bool m_draw;
	bool SortOnTime;
	bool SortStep;
	


	CDC *m_pdc;
	CPen m_pen;
	CFont m_font;

	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBubbleSort();
	afx_msg void OnInsertSort();
	afx_msg void OnSelectSort();
	afx_msg void OnStartSort();
	afx_msg void OnEndSort();
	afx_msg void OnUpdateBubbleSort(CCmdUI *pCmdUI);
	afx_msg void OnUpdateInsertSort(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSelectSort(CCmdUI *pCmdUI);
	afx_msg void OnSortStep();
	afx_msg void OnUpdateSortStep(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // ZHN_TEST1_3View.cpp 中的调试版本
inline CZHN_TEST1_3Doc* CZHN_TEST1_3View::GetDocument() const
   { return reinterpret_cast<CZHN_TEST1_3Doc*>(m_pDocument); }
#endif

