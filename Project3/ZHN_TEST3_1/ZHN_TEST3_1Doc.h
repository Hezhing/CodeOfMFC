
// ZHN_TEST3_1Doc.h : CZHN_TEST3_1Doc ��Ľӿ�
//


#pragma once

#include<vector>
using namespace std;


class CZHN_TEST3_1Doc : public CDocument
{
protected: // �������л�����
	CZHN_TEST3_1Doc();
	DECLARE_DYNCREATE(CZHN_TEST3_1Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CZHN_TEST3_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	
public:
	
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
	

	void OpenFile(CString FilePath);
	void OpenFiles();

	struct Information
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
	Information item;
	vector<Information> save;
	vector<Information>::iterator store;//������
	vector<Information>::iterator it;


public:
	afx_msg void On32775OpenFile();

};
