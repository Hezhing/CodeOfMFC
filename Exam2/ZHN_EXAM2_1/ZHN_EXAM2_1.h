
// ZHN_EXAM2_1.h : ZHN_EXAM2_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CZHN_EXAM2_1App:
// �йش����ʵ�֣������ ZHN_EXAM2_1.cpp
//

class CZHN_EXAM2_1App : public CWinApp
{
public:
	CZHN_EXAM2_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZHN_EXAM2_1App theApp;
