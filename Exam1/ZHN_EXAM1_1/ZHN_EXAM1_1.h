
// ZHN_EXAM1_1.h : ZHN_EXAM1_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CZHN_EXAM1_1App:
// �йش����ʵ�֣������ ZHN_EXAM1_1.cpp
//

class CZHN_EXAM1_1App : public CWinAppEx
{
public:
	CZHN_EXAM1_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZHN_EXAM1_1App theApp;
