
// ZHN_EXAM1_1.h : ZHN_EXAM1_1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CZHN_EXAM1_1App:
// 有关此类的实现，请参阅 ZHN_EXAM1_1.cpp
//

class CZHN_EXAM1_1App : public CWinAppEx
{
public:
	CZHN_EXAM1_1App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZHN_EXAM1_1App theApp;
