#pragma once
#include "NumOfImage.h"
#include "DrawImage.h"
class MyImage
{
public: // 定义变量
	MyImage(void);
	~MyImage(void);

	NumOfImage NumImage;
	DrawImage drawImage;

	CFont Font;
	int x1,y1,x2,y2;
	int r;
	float num;

public: // 定义函数

	void myPoint(CDC *m_pdc);
	
};

