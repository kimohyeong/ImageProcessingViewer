// AddNoiseTab_1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Viewer.h"
#include "AddNoiseTab_1.h"
#include "afxdialogex.h"


// CAddNoiseTab_1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddNoiseTab_1, CDialogEx)

CAddNoiseTab_1::CAddNoiseTab_1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDNOISE_TAB1, pParent)
{

}

CAddNoiseTab_1::~CAddNoiseTab_1()
{
}

void CAddNoiseTab_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GNMEAN, Edit_GN_Mean);
	DDX_Control(pDX, IDC_EDIT_GNSTDEV, Edit_GN_Stdev);

}


BEGIN_MESSAGE_MAP(CAddNoiseTab_1, CDialogEx)
END_MESSAGE_MAP()


// CAddNoiseTab_1 �޽��� ó�����Դϴ�.
