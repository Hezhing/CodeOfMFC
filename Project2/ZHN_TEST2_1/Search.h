#pragma once


// CSearch 对话框

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

	CSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSearch();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnDropdownCombo2();
};
