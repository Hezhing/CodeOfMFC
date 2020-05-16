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


// CMedicListView 视图

class CMedicListView : public CListView
{
	DECLARE_DYNCREATE(CMedicListView)

protected:
	CMedicListView();           // 动态创建所使用的受保护的构造函数
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
	
	bool I_add;   //是否添加
	int I_index;   //删除行
	bool clickList;

	void Updata();
	

};


