#pragma once


// COrderStatisticsDlg ��ȭ �����Դϴ�.

class COrderStatisticsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderStatisticsDlg)

public:
	COrderStatisticsDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COrderStatisticsDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ORDERSTATISTICSDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
private:
	int nFilterSize1;
	int nFilterSize2;
	int nOSFType;

	CEdit Edit_FilterSize1;
	CEdit Edit_FilterSize2;

public:
	int m_radio_osf;
	afx_msg void OnBnClickedOkbuttonOsf();
	afx_msg void OnRadioClicked(UINT msg);

	int GetFilterSize1();
	int GetFilterSize2();
	int GetOSFType();


};
 