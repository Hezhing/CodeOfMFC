
// ZHN_TEST3_1View.h : CZHN_TEST3_1View ��Ľӿ�
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
protected: // �������л�����
	CZHN_TEST3_1View();
	DECLARE_DYNCREATE(CZHN_TEST3_1View)

public:
	enum{ IDD = IDD_ZHN_TEST3_1_FORM };

// ����
public:
	CZHN_TEST3_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CZHN_TEST3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()





	

};

#ifndef _DEBUG  // ZHN_TEST3_1View.cpp �еĵ��԰汾
inline CZHN_TEST3_1Doc* CZHN_TEST3_1View::GetDocument() const
   { return reinterpret_cast<CZHN_TEST3_1Doc*>(m_pDocument); }
#endif

