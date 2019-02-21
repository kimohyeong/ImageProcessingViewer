#pragma once


// CMeanFilterDlg ��ȭ �����Դϴ�.

class CMeanFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMeanFilterDlg)

public:
	CMeanFilterDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMeanFilterDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEANFILTERDIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
