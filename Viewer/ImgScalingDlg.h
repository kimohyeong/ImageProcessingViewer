#pragma once


// CImgScalingDlg ��ȭ �����Դϴ�.

class CImgScalingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImgScalingDlg)

public:
	CImgScalingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CImgScalingDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMGSCALEDIALOG };
#endif
private:
	CStatic m_EditScaleRate;

	double dScaleRate;
	int nInterpolationType;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_radio_interp;
	afx_msg void OnBnClickedOkbuttonS();
	afx_msg void OnRadioClicked(UINT msg);


	double GetScaleRate();
	int GetInterpType();
};
