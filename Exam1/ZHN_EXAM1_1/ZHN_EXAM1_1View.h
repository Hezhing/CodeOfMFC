
// ZHN_EXAM1_1View.h : CZHN_EXAM1_1View ��Ľӿ�
//

#pragma once
#include "MyImage.h"

class CZHN_EXAM1_1View : public CView
{
protected: // �������л�����
	CZHN_EXAM1_1View();
	DECLARE_DYNCREATE(CZHN_EXAM1_1View)

// ����
public:
	CZHN_EXAM1_1Doc* GetDocument() const;

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
	virtual ~CZHN_EXAM1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

public:
	MyImage image;

};

#ifndef _DEBUG  // ZHN_EXAM1_1View.cpp �еĵ��԰汾
inline CZHN_EXAM1_1Doc* CZHN_EXAM1_1View::GetDocument() const
   { return reinterpret_cast<CZHN_EXAM1_1Doc*>(m_pDocument); }
#endif

