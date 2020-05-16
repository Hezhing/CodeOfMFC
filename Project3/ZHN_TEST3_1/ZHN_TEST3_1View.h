
// ZHN_TEST3_1View.h : CZHN_TEST3_1View 类的接口
//

#pragma once

#include "resource.h"
#include "ZHN_TEST3_1Doc.h"
#include "UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
#include "Add.h"
#include "Change.h"
#include "Search.h"

#include<vector>
#include <iostream>
using namespace std;


class CZHN_TEST3_1View : public CFormView
{
protected: // 仅从序列化创建
	CZHN_TEST3_1View();
	DECLARE_DYNCREATE(CZHN_TEST3_1View)

public:
	enum{ IDD = IDD_ZHN_TEST3_1_FORM };

// 特性
public:
	CZHN_TEST3_1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CZHN_TEST3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()





	

};

#ifndef _DEBUG  // ZHN_TEST3_1View.cpp 中的调试版本
inline CZHN_TEST3_1Doc* CZHN_TEST3_1View::GetDocument() const
   { return reinterpret_cast<CZHN_TEST3_1Doc*>(m_pDocument); }
#endif

