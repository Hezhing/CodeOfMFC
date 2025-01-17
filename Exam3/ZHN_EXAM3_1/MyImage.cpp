#include "stdafx.h"
#include "MyImage.h"
#include <math.h>


CMyImage::CMyImage(void)
{
}


CMyImage::~CMyImage(void)
{
}

CMyImage::CMyImage(CDC *pDC)
{
	pDC->Ellipse(200,200,400,400); // 定义圆
	Font.CreatePointFont(100,TEXT("楷体")); // 改变字体
	// 初始化
	num = 0;
	x1=392;
	y1=330;
	r=100;
}

void CMyImage::DrawImage(CDC *pDC,float PerMoney,CString name,int R,int G,int B)
{
	// 画刷
	CBrush br(RGB(R,G,B));
	pDC->SelectObject(&br);
	// 计算位置
	num = num + PerMoney;
	x2 = int(r*cos(num*3.14*2)+300);
	y2 = int(-r*sin(num*3.14*2)+300);
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
	x1=x2;y1=y2;
}

void CMyImage::DrawMark(CDC *pDC,int R,int G,int B,CString name,int x1,int x2,int y1,int y2)
{
	CBrush br(RGB(R,G,B));
	pDC->SelectObject(&br);
	pDC->Rectangle(x1,x2,y1,y2);
	pDC->TextOutW(x1+30,x2,name);
}