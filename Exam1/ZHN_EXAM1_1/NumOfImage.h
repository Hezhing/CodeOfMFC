#pragma once
class NumOfImage
{
public: // 定义变量
	NumOfImage(void);
	~NumOfImage(void);

	float PerMoney;// 百分率
	CString Name; // 名称
	int R,G,B; // 颜色

public: // 定义函数
	void InitOfEat(void); // 初始化吃饭
	void InitOfEnter(void); // 初始化娱乐
	void InitOfCloth(void); // 初始化衣服
	void InitOfEdu(void); // 初始化教育
	void InitOfHouse(void); // 初始化房贷
};

