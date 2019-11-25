
// ZHN_TEST2_1Dlg.h : ͷ�ļ�
//

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "add.h"
#include "Change.h"
#include "Search.h"
// CZHN_TEST2_1Dlg �Ի���
class CZHN_TEST2_1Dlg : public CDialogEx
{
// ����
public:

	void reFile();
	bool clickList;
	void fileTreeOut(CString f_indexT);
	CString I_indexT;  //ɾ���Ľڵ�
	void fileListOut(int f_index);
	int I_index;   //ɾ����
	void xiaohui();
	void WriteFile();
	void initTree();
	void initList();
	void OpenFile(CString FilePath);
	void showInformation(int index);
	CString id;
	CString name;
	CString sex;
	CString card;
	CString level;
	CString time;
	CString like;
	CString remarks;
	CString m_EditItem;
	CMenu menu;
	bool I_add;   //�Ƿ����

	typedef struct  Information
	{
		CString I_id,
		I_name,
		I_sex,
		I_card,
		I_level,
		I_time,
		I_like,
		I_remarks;
	};
	Information * item;
	vector<Information*> save;
	vector<Information*>::iterator store;//������

	CZHN_TEST2_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ZHN_TEST2_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CImageList m_ImageList;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32776();
	afx_msg void On32777();
	DECLARE_MESSAGE_MAP()
	
private:
	Cadd add;
	CChange revise;
	CSearch query;
	
};
