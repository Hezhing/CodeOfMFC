#pragma once


// CSearch �Ի���

class CSearch : public CDialog
{
	DECLARE_DYNAMIC(CSearch)

public:
	CString q_id;
	CString q_name;
	CString q_sex;
	CString q_card;
	CString q_level;
	CString q_time;
	CString q_like;
	CString q_remarks;
	bool q_state;

	CSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSearch();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnDropdownCombo2();
};
