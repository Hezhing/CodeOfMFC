#pragma once
#include "NumOfImage.h"
class DrawImage
{
public:
	DrawImage(void);
	~DrawImage(void);

public:
	void PointText(CDC *pDC,int x1,int x2,int y1,int y2,NumOfImage NumImage);
	void FanPoint(CDC *pDC,int num,int x1,int x2,int y1,int y2);
};

