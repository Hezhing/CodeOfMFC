#include "stdafx.h"
#include "NumOfImage.h"


NumOfImage::NumOfImage(void)
{
	
}

NumOfImage::~NumOfImage(void)
{
}

void NumOfImage::InitOfEat(void)
{
	Name = "�Է�";
	PerMoney = 0.3;
	R=0,G=0,B=255;
}

void NumOfImage::InitOfCloth(void)
{
	Name = "�·�";
	PerMoney = 0.15;
	R=50,G=201,B=50;
}

void NumOfImage::InitOfEnter(void)
{
	Name = "����";
	PerMoney = 0.1;
	R=50,G=50,B=255;
}

void NumOfImage::InitOfEdu(void)
{
	Name = "����";
	PerMoney = 0.1;
	R=100,G=0,B=255;
}

void NumOfImage::InitOfHouse(void)
{
	Name = "����";
	PerMoney = 0.35;
	R=201,G=100,B=255;
}
