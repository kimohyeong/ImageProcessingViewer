// AddNoiseTab_2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Viewer.h"
#include "AddNoiseTab_2.h"
#include "afxdialogex.h"


// CAddNoiseTab_2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddNoiseTab_2, CDialogEx)

CAddNoiseTab_2::CAddNoiseTab_2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDNOISE_TAB2, pParent)
{

}

CAddNoiseTab_2::~CAddNoiseTab_2()
{
}

void CAddNoiseTab_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SPROB, Edit_SN_Prob);
	DDX_Control(pDX, IDC_EDIT_PPROB, Edit_PN_Prob);
}


BEGIN_MESSAGE_MAP(CAddNoiseTab_2, CDialogEx)
END_MESSAGE_MAP()


// CAddNoiseTab_2 �޽��� ó�����Դϴ�.
