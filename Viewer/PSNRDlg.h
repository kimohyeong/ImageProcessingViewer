#pragma once
#include "RawInfoDlg.h"
#include "ViewerDlg.h"

// CPSNRDlg ��ȭ �����Դϴ�.

class CPSNRDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPSNRDlg)

public:
	CPSNRDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPSNRDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PSNRDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
private:
	unsigned char** Ori, **Dst;

	int nHeight_Ori, nWidth_Ori;
	int nHeight_Dst, nWidth_Dst;

	CEdit Edit_File_Ori, Edit_File_Dst, Edit_PSNR;
	double GetPSNR(unsigned char ** Ori, unsigned char ** Dst, int nHeight, int nWidth);


public:
	afx_msg void OnBnClickedOriopenbutton();
	afx_msg void OnBnClickedNoiseopenbutton();
	afx_msg void OnBnClickedGetpsnrbutton();
	afx_msg void OnBnClickedClosebuttonPsnr();
};
