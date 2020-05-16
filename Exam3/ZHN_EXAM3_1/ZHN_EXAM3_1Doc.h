
// ZHN_EXAM3_1Doc.h : CZHN_EXAM3_1Doc 类的接口
//

#include<vector>

#pragma once


class CZHN_EXAM3_1Doc : public CDocument
{
protected: // 仅从序列化创建
	CZHN_EXAM3_1Doc();
	DECLARE_DYNCREATE(CZHN_EXAM3_1Doc)

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
	virtual ~CZHN_EXAM3_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//数据
public:
	struct FanData{
		float PerMoney;
		int R;
		int G;
		int B;
		CString name;
	};
	struct FanData fanData;
	std::vector<FanData> fd;
	void AddData(CString name,float PerMoney,int R,int G,int B);
	void CalculatePer();
	void MyUpDateView();


protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
