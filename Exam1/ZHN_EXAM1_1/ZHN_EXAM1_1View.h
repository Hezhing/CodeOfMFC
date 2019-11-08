
// ZHN_EXAM1_1View.h : CZHN_EXAM1_1View 类的接口
//

#pragma once
#include "MyImage.h"

class CZHN_EXAM1_1View : public CView
{
protected: // 仅从序列化创建
	CZHN_EXAM1_1View();
	DECLARE_DYNCREATE(CZHN_EXAM1_1View)

// 特性
public:
	CZHN_EXAM1_1Doc* GetDocument() const;

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
	virtual ~CZHN_EXAM1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	MyImage image;

};

#ifndef _DEBUG  // ZHN_EXAM1_1View.cpp 中的调试版本
inline CZHN_EXAM1_1Doc* CZHN_EXAM1_1View::GetDocument() const
   { return reinterpret_cast<CZHN_EXAM1_1Doc*>(m_pDocument); }
#endif

