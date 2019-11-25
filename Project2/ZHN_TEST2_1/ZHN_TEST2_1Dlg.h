
// ZHN_TEST2_1Dlg.h : 头文件
//

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "add.h"
#include "Change.h"
#include "Search.h"
// CZHN_TEST2_1Dlg 对话框
class CZHN_TEST2_1Dlg : public CDialogEx
{
// 构造
public:

	void reFile();
	bool clickList;
	void fileTreeOut(CString f_indexT);
	CString I_indexT;  //删除的节点
	void fileListOut(int f_index);
	int I_index;   //删除行
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
	bool I_add;   //是否添加

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
	vector<Information*>::iterator store;//迭代器

	CZHN_TEST2_1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ZHN_TEST2_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	CImageList m_ImageList;
	// 生成的消息映射函数
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
