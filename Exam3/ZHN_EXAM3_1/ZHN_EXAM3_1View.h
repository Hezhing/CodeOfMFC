
// ZHN_EXAM3_1View.h : CZHN_EXAM3_1View 类的接口
//

#pragma once
#include "ZHN_EXAM3_1Doc.h"

class CZHN_EXAM3_1View : public CView
{
protected: // 仅从序列化创建
	CZHN_EXAM3_1View();
	DECLARE_DYNCREATE(CZHN_EXAM3_1View)

// 特性
public:
	CZHN_EXAM3_1Doc* GetDocument() const;

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
	virtual ~CZHN_EXAM3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // ZHN_EXAM3_1View.cpp 中的调试版本
inline CZHN_EXAM3_1Doc* CZHN_EXAM3_1View::GetDocument() const
   { return reinterpret_cast<CZHN_EXAM3_1Doc*>(m_pDocument); }
#endif

