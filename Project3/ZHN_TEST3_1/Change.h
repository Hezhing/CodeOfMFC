#pragma once


// CChange �Ի���

class CChange : public CDialog
{
	DECLARE_DYNAMIC(CChange)

public:
	CString r_id;
	CString r_name;
	CString r_sex;
	CString r_card;
	CString r_level;
	CString r_time;
	CString r_like;
	CString r_remarks;
	bool r_state;
	CString	m_rid;

	CChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChange();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnDropdownCombo2();
};
