
// ZHN_EXAM3_1Doc.h : CZHN_EXAM3_1Doc ��Ľӿ�
//

#include<vector>

#pragma once


class CZHN_EXAM3_1Doc : public CDocument
{
protected: // �������л�����
	CZHN_EXAM3_1Doc();
	DECLARE_DYNCREATE(CZHN_EXAM3_1Doc)

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
	virtual ~CZHN_EXAM3_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//����
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

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
