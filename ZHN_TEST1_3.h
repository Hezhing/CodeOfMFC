
// ZHN_TEST1_3.h : ZHN_TEST1_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CZHN_TEST1_3App:
// �йش����ʵ�֣������ ZHN_TEST1_3.cpp
//

class CZHN_TEST1_3App : public CWinAppEx
{
public:
	CZHN_TEST1_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZHN_TEST1_3App theApp;
