#pragma once


// CAddNoiseTab_2 ��ȭ �����Դϴ�.

class CAddNoiseTab_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseTab_2)

public:
	CAddNoiseTab_2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddNoiseTab_2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISE_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CEdit Edit_SN_Prob;
	CEdit Edit_PN_Prob;
};
