#pragma once


// Cadd �Ի���

class Cadd : public CDialog
{
	DECLARE_DYNAMIC(Cadd)

public:
	CString a_id;
	CString a_name;
	CString a_sex;
	CString a_card;
	CString a_level;
	CString a_time;
	CString a_like;
	CString a_remarks;
	CString m_aid;
	bool a_state;

	Cadd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cadd();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnDropdownCombo2();
};
