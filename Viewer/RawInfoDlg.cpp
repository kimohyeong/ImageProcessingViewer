// RawInfoDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Viewer.h"
#include "RawInfoDlg.h"
#include "afxdialogex.h"


// CRawInfoDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRawInfoDlg, CDialogEx)

CRawInfoDlg::CRawInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RAWINFODIALOG, pParent)
	, m_radio_rawFileInfo(0)
{
	nFormat = 3;
}

CRawInfoDlg::~CRawInfoDlg()
{
}

void CRawInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_GRAYFORMAT, m_radio_rawFileInfo);
	DDX_Control(pDX, IDC_EDIT_HEIGHT, m_EditHeight);
	DDX_Control(pDX, IDC_EDIT_WIDTH, m_EditWidth);

}


BEGIN_MESSAGE_MAP(CRawInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OKBUTTON_I, &CRawInfoDlg::OnBnClickedOkbuttonI)
	ON_BN_CLICKED(IDC_CANCELBUTTON_I, &CRawInfoDlg::OnBnClickedCancelbuttonI)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_GRAYFORMAT, IDC_RADIO_YUV444FORMAT, OnClickedRadio)
END_MESSAGE_MAP()


// CRawInfoDlg �޽��� ó�����Դϴ�.


void CRawInfoDlg::OnBnClickedOkbuttonI()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cTemp1, cTemp2;

	m_EditHeight.GetWindowTextA(cTemp1);
	m_EditWidth.GetWindowTextA(cTemp2);

	nHeight = atoi(cTemp1);
	nWidth = atoi(cTemp2);

	CDialogEx::OnOK();
}


void CRawInfoDlg::OnBnClickedCancelbuttonI()
{
	CDialogEx::OnCancel();
}

void CRawInfoDlg::OnClickedRadio(UINT msg) {
	UpdateData(TRUE);
	switch (m_radio_rawFileInfo)
	{
	case 0:
		nFormat = 3;
		break;
	case 1:
		nFormat = 1;
		break;
	case 2:
		nFormat = 2;
		break;
	}


}

int CRawInfoDlg::GetRawHeight()
{
	return nHeight;
}
int CRawInfoDlg::GetRawWidth()
{
	return nWidth;
}
int CRawInfoDlg::GetRawFormat() {
	return nFormat;
}