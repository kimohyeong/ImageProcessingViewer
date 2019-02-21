// FilterDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Viewer.h"
#include "FilterDlg.h"
#include "afxdialogex.h"


// CFilterDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFilterDlg, CDialogEx)

CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILTERDIALOG, pParent)
	, m_radio_Filtertype(0)
{

}

CFilterDlg::~CFilterDlg()
{
}

void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_AVERAGEFILTERRADIO, m_radio_Filtertype);
	DDX_Control(pDX, IDC_EDIT_FILTERSIZE, m_EditFilterSize);
	DDX_Control(pDX, IDC_EDIT_SIGMA, m_EditSigma);

}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OKBUTTON_F, &CFilterDlg::OnBnClickedOkbuttonF)
	ON_BN_CLICKED(IDC_CANCELBUTTON_F, &CFilterDlg::OnBnClickedCancelbuttonF)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_AVERAGEFILTERRADIO, IDC_SMOOTHFILTERRADIO, OnClickedRadio)
END_MESSAGE_MAP()


// CFilterDlg 메시지 처리기입니다.


void CFilterDlg::OnBnClickedOkbuttonF()
{
	CString cstrTemp1, cstrTemp2;
	m_EditFilterSize.GetWindowTextA(cstrTemp1);
	nFilterSize = atoi(cstrTemp1);

	m_EditSigma.GetWindowTextA(cstrTemp2);
	dSigma = atof(cstrTemp2);

	CDialog::OnOK();
}


void CFilterDlg::OnBnClickedCancelbuttonF()
{
	CDialog::OnCancel();
}
void CFilterDlg::OnClickedRadio(UINT msg)
{
	UpdateData(TRUE);

	switch (m_radio_Filtertype)
	{
	case 0:
		nFilterType = 0;
		break;
	case 1:
		nFilterType = 1;
		break;

	case 2:
		nFilterType = 2;
		break;

	case 3:
		nFilterType = 3;
		break;


	}


}

int CFilterDlg::getFilterSize() {
	return nFilterSize;
}

int CFilterDlg::getFilterType() {
	return nFilterType;
}
double CFilterDlg::getSigma() {
	return dSigma;
}
