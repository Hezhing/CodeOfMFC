
// ZHN_EXAM3_1View.h : CZHN_EXAM3_1View ��Ľӿ�
//

#pragma once
#include "ZHN_EXAM3_1Doc.h"

class CZHN_EXAM3_1View : public CView
{
protected: // �������л�����
	CZHN_EXAM3_1View();
	DECLARE_DYNCREATE(CZHN_EXAM3_1View)

// ����
public:
	CZHN_EXAM3_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CZHN_EXAM3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	double a,b,c;
	float preNum;
	float cosNum;
	float compareNum;
	float Num;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnNewObj();
	afx_msg void OnManagerObj();
};

#ifndef _DEBUG  // ZHN_EXAM3_1View.cpp �еĵ��԰汾
inline CZHN_EXAM3_1Doc* CZHN_EXAM3_1View::GetDocument() const
   { return reinterpret_cast<CZHN_EXAM3_1Doc*>(m_pDocument); }
#endif

