#pragma once


// CMeanFilterDlg 대화 상자입니다.

class CMeanFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMeanFilterDlg)

public:
	CMeanFilterDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMeanFilterDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEANFILTERDIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	
private:
	int nFilterSize;
	int nMeanFilterType;
	int Q;

	CEdit Edit_FilterSize;
	CEdit Edit_Q;
public:
	int m_radio_arithmetic;


	afx_msg void OnBnClickedOkbuttonNf();
	afx_msg void OnRadioClicked(UINT msg);

	int GetFilterSize();
	int GetMeanFilterType();
	int GetQ();
};
