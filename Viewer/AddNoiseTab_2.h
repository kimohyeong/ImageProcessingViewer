#pragma once


// CAddNoiseTab_2 대화 상자입니다.

class CAddNoiseTab_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseTab_2)

public:
	CAddNoiseTab_2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddNoiseTab_2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISE_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CEdit Edit_SN_Prob;
	CEdit Edit_PN_Prob;
};
