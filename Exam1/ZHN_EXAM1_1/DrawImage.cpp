#include "stdafx.h"
#include "DrawImage.h"


DrawImage::DrawImage(void)
{
}


DrawImage::~DrawImage(void)
{
}

void DrawImage::PointText(CDC *pDC,int x1,int x2,int y1,int y2,NumOfImage NumImage)
{
	pDC->Rectangle(x1,x2,y1,y2);
	pDC->TextOutW(x1+30,x2,NumImage.Name);
}



void DrawImage::FanPoint(CDC *pDC,int num,int x1,int y1,int x2,int y2)
{
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
}