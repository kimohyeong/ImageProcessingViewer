#pragma once


// CAddNoiseTab_1 ��ȭ �����Դϴ�.

class CAddNoiseTab_1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseTab_1)

public:
	CAddNoiseTab_1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddNoiseTab_1();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISE_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CEdit Edit_GN_Mean;
	CEdit Edit_GN_Stdev;
};
