#pragma once


// CUserListView ��ͼ

class CUserListView : public CListView
{
	DECLARE_DYNCREATE(CUserListView)

protected:
	CUserListView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void Updata();
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};


