#pragma once
#include "AddNoiseTab_1.h"
#include "AddNoiseTab_2.h"
#include "afxcmn.h"


// CAddNoiseDlg ��ȭ �����Դϴ�.

class CAddNoiseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseDlg)

public:
	CAddNoiseDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddNoiseDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISEDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_mainTab;
	float GetVal_1();
	float GetVal_2();
	int GetNoiseType();
	BOOL OnInitDialog();

private:
	CAddNoiseTab_1 Tab1;
	CAddNoiseTab_2 Tab2;

	CWnd* m_pwndShow;

	float value_1;
	float value_2;
	int NoiseType;

public:
	afx_msg void OnTcnSelchangeAddnoisetab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOkbuttonN();
	afx_msg void OnBnClickedCancelbuttonN();
};
