#pragma once
#include<vector>
#include <iostream>
#include "ZHN_TEST3_1View.h"
#include "Add.h"
#include "Change.h"
#include "Search.h"
#include "UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
using namespace std;


// CMedicListView ��ͼ

class CMedicListView : public CListView
{
	DECLARE_DYNCREATE(CMedicListView)

protected:
	CMedicListView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMedicListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();

public:
	
	bool I_add;   //�Ƿ����
	int I_index;   //ɾ����
	bool clickList;

	void Updata();
	

};


