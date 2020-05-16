#pragma once
#include <vector>
#include <iostream>
#include "Add.h"
#include "Change.h"
#include "Search.h"
#include "UserFormView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
using namespace std;


// CUserFormView ������ͼ

class CUserFormView : public CFormView
{
	DECLARE_DYNCREATE(CUserFormView)

protected:
	CUserFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserFormView();

public:
	enum { IDD = IDD_USERFORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
public:
	void reFile();
	bool clickList;
	void fileTreeOut(CString f_indexT);	
	void fileListOut(int f_index);	
	void xiaohui();
	void WriteFile();
	void initTree();
	void initList();
	void OpenFile(CString FilePath);
	void showInformation(int index);

	int I_index;   //ɾ����
	CString I_indexT;  //ɾ���Ľڵ�
	bool I_add;   //�Ƿ����
	
	
		
private:
	CAdd add;
	CChange revise;
	CSearch query;
public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelect();
	afx_msg void OnBnClickedChange();
	afx_msg void OnBnClickedSearch();
	afx_msg void On32771Add();
	afx_msg void On32772Delect();
	afx_msg void On32773Change();
	afx_msg void On32774Search();
	
};


