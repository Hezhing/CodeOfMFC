
// ZHN_TEST2_1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CZHN_TEST2_1App:
// �йش����ʵ�֣������ ZHN_TEST2_1.cpp
//

class CZHN_TEST2_1App : public CWinApp
{
public:
	CZHN_TEST2_1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CZHN_TEST2_1App theApp;