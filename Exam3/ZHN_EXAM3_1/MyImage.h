#pragma once
class CMyImage
{
public:
	CMyImage(void);
	~CMyImage(void);
	CMyImage(CDC *pDC); // �ع�
	void DrawImage(CDC *pDC,float PerMoney,CString name,int R,int G,int B); // ������ͼ
	void DrawMark(CDC *pDC,int R,int G,int B,CString name,int x1,int x2,int y1,int y2);

public:
	CFont Font;
	int x1,x2,y1,y2;
	int r;
	float num;
};

