// OrderStatisticsDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Viewer.h"
#include "OrderStatisticsDlg.h"
#include "afxdialogex.h"


// COrderStatisticsDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(COrderStatisticsDlg, CDialogEx)

COrderStatisticsDlg::COrderStatisticsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ORDERSTATISTICSDLG, pParent)
	, m_radio_osf(0)
{

}

COrderStatisticsDlg::~COrderStatisticsDlg()
{
}

void COrderStatisticsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_MEDIANF, m_radio_osf);
	DDX_Control(pDX, IDC_EDIT_FILTERSIZE_OSF, Edit_FilterSize1);
	DDX_Control(pDX, IDC_EDIT_MAXFILTERSIZE_OSF, Edit_FilterSize2);
}


BEGIN_MESSAGE_MAP(COrderStatisticsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OKBUTTON_OSF, &COrderStatisticsDlg::OnBnClickedOkbuttonOsf)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_MEDIANF, IDC_RADIO_ADAPTIVEMEDIANF, OnRadioClicked)
END_MESSAGE_MAP()


// COrderStatisticsDlg �޽��� ó�����Դϴ�.


void COrderStatisticsDlg::OnBnClickedOkbuttonOsf()
{
	CString strTemp1, strTemp2;

	Edit_FilterSize1.GetWindowTextA(strTemp1);
	Edit_FilterSize2.GetWindowTextA(strTemp2);

	nFilterSize1 = atoi(strTemp1);
	nFilterSize2 = atoi(strTemp2);

	CDialog::OnOK();

}
void COrderStatisticsDlg::OnRadioClicked(UINT msg)
{
	UpdateData(TRUE);
	switch (m_radio_osf)
	{
	case 0:
		nOSFType = 4;
		break;
	case 1:
		nOSFType = 5;
		break;
	}
}

int COrderStatisticsDlg::GetFilterSize1()
{
	return nFilterSize1;

}
int COrderStatisticsDlg::GetFilterSize2()
{
	return nFilterSize2;

}
int COrderStatisticsDlg::GetOSFType()
{
	return nOSFType;
}

