#pragma once

#include <vector>
#include <iostream>
#include "Add.h"
#include "Change.h"
#include "Search.h"
#include "UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
using namespace std;


// CUserTreeView 视图

class CUserTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CUserTreeView)

protected:
	CUserTreeView();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserTreeView();

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
	

	CImageList imageList;
	void Updata();
};


