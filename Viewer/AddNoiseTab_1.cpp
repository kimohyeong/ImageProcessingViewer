// AddNoiseTab_1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Viewer.h"
#include "AddNoiseTab_1.h"
#include "afxdialogex.h"


// CAddNoiseTab_1 대화 상자입니다.

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


// CAddNoiseTab_1 메시지 처리기입니다.
