#pragma once
class NumOfImage
{
public: // �������
	NumOfImage(void);
	~NumOfImage(void);

	float PerMoney;// �ٷ���
	CString Name; // ����
	int R,G,B; // ��ɫ

public: // ���庯��
	void InitOfEat(void); // ��ʼ���Է�
	void InitOfEnter(void); // ��ʼ������
	void InitOfCloth(void); // ��ʼ���·�
	void InitOfEdu(void); // ��ʼ������
	void InitOfHouse(void); // ��ʼ������
};

