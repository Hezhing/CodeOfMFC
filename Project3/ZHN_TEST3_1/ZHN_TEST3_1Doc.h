
// ZHN_TEST3_1Doc.h : CZHN_TEST3_1Doc 类的接口
//


#pragma once

#include<vector>
using namespace std;


class CZHN_TEST3_1Doc : public CDocument
{
protected: // 仅从序列化创建
	CZHN_TEST3_1Doc();
	DECLARE_DYNCREATE(CZHN_TEST3_1Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CZHN_TEST3_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
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
	vector<Information>::iterator store;//迭代器
	vector<Information>::iterator it;


public:
	afx_msg void On32775OpenFile();

};
