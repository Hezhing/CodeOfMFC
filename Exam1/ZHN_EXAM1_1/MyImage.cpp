#include "stdafx.h"
#include "MyImage.h"
#include "math.h"
#include "resource.h"

MyImage::MyImage(void)
{
	num = 0;
	x1=392;
	y1=330;
	r=100;
}


MyImage::~MyImage(void)
{

}



void MyImage::myPoint(CDC *m_pdc)
{
	Font.CreatePointFont(100,TEXT("楷体"));

	// 吃饭
	CBitmap bitmap1; // 定义位图对象
	CDC dccom1;
	BITMAP bmp1;
	bitmap1.LoadBitmap(IDB_BITMAP2); // 获取位图句柄
	bitmap1.GetBitmap(&bmp1); // 获取位图信息
	dccom1.CreateCompatibleDC(m_pdc);  // 创建内存设备环境
	dccom1.SelectObject(&bitmap1); // 把位图对象选入内存设备环境
	
	m_pdc->Ellipse(200,200,400,400);// 设定椭圆大小

	NumImage.InitOfEat(); // 初始化
	num=num+NumImage.PerMoney;  // 计算消费占比
	CBrush br1(RGB(NumImage.R,NumImage.G,NumImage.B)); // 定义画刷颜色
	m_pdc->SelectObject(&br1); // 设置颜色
	x2=int(r*cos(num*3.14*2)+300);
	y2=int(-r*sin(num*3.14*2)+300); //计算坐标
	drawImage.FanPoint(m_pdc,num,x1,y1,x2,y2); // 画饼图
	//将内存DC中的位图复制到设备DC
	m_pdc->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dccom1,0,0,bmp1.bmWidth,bmp1.bmHeight,SRCCOPY);
	x1=x2;y1=y2;
	drawImage.PointText(m_pdc,500,50,520,70,NumImage); // 添加右上角标志


	// 娱乐

	CBitmap bitmap2;
	CDC dccom2;
	BITMAP bmp2;
	bitmap2.LoadBitmap(IDB_BITMAP3);
	bitmap2.GetBitmap(&bmp2);
	dccom2.CreateCompatibleDC(m_pdc);
	dccom2.SelectObject(&bitmap2);

	NumImage.InitOfEnter();
	num=num+NumImage.PerMoney;
	CBrush br2(RGB(NumImage.R,NumImage.G,NumImage.B));
	m_pdc->SelectObject(&br2);
	x2=int(r*cos(num*3.14*2)+300);
	y2=int(-r*sin(num*3.14*2)+300);
	drawImage.FanPoint(m_pdc,num,x1,y1,x2,y2);
	m_pdc->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dccom2,0,0,bmp2.bmWidth,bmp2.bmHeight,SRCCOPY);
	x1=x2;y1=y2;
	drawImage.PointText(m_pdc,500,90,520,110,NumImage);


	// 衣服
	CBitmap bitmap3;
	CDC dccom3;
	BITMAP bmp3;
	bitmap3.LoadBitmap(IDB_BITMAP4);
	bitmap3.GetBitmap(&bmp3);
	dccom3.CreateCompatibleDC(m_pdc);
	dccom3.SelectObject(&bitmap3);

	NumImage.InitOfCloth();
	num=num+NumImage.PerMoney;
	CBrush br3(RGB(NumImage.R,NumImage.G,NumImage.B));
	m_pdc->SelectObject(&br3);
	x2=int(r*cos(num*3.14*2)+300);
	y2=int(-r*sin(num*3.14*2)+300);
	drawImage.FanPoint(m_pdc,num,x1,y1,x2,y2);
	m_pdc->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dccom3,0,0,bmp3.bmWidth,bmp3.bmHeight,SRCCOPY);
	x1=x2;y1=y2;
	drawImage.PointText(m_pdc,500,130,520,150,NumImage);

	// 教育
	CBitmap bitmap4;
	CDC dccom4;
	BITMAP bmp4;
	bitmap4.LoadBitmap(IDB_BITMAP5);
	bitmap4.GetBitmap(&bmp4);
	dccom4.CreateCompatibleDC(m_pdc);
	dccom4.SelectObject(&bitmap4);

	NumImage.InitOfEdu();
	num=num+NumImage.PerMoney;
	CBrush br4(RGB(NumImage.R,NumImage.G,NumImage.B));
	m_pdc->SelectObject(&br4);
	x2=int(r*cos(num*3.14*2)+300);
	y2=int(-r*sin(num*3.14*2)+300);
	drawImage.FanPoint(m_pdc,num,x1,y1,x2,y2);
	m_pdc->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dccom4,0,0,bmp4.bmWidth,bmp4.bmHeight,SRCCOPY);
	x1=x2;y1=y2;
	drawImage.PointText(m_pdc,500,170,520,190,NumImage);


	// 房贷
	CBitmap bitmap5;
	CDC dccom5;
	BITMAP bmp5;
	bitmap5.LoadBitmap(IDB_BITMAP1);
	bitmap5.GetBitmap(&bmp5);
	dccom5.CreateCompatibleDC(m_pdc);
	dccom5.SelectObject(&bitmap5);
	
	NumImage.InitOfHouse();
	num=num+NumImage.PerMoney;
	CBrush br5(RGB(NumImage.R,NumImage.G,NumImage.B));
	m_pdc->SelectObject(&br5);
	x2=int(r*cos(num*3.14*2)+300);
	y2=int(-r*sin(num*3.14*2)+300);
	drawImage.FanPoint(m_pdc,num,x1,y1,x2,y2);
	m_pdc->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dccom5,0,0,bmp5.bmWidth,bmp5.bmHeight,SRCCOPY);
	x1=x2;y1=y2;
	drawImage.PointText(m_pdc,500,210,520,230,NumImage);
	
}

