#pragma once


// CAddNoiseTab_1 대화 상자입니다.

class CAddNoiseTab_1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseTab_1)

public:
	CAddNoiseTab_1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddNoiseTab_1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISE_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CEdit Edit_GN_Mean;
	CEdit Edit_GN_Stdev;
};
