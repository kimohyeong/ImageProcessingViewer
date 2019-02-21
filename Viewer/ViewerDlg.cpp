
// ViewerDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Viewer.h"
#include "ViewerDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CViewerDlg 대화 상자



CViewerDlg::CViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VIEWER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PICTURE_IN, m_PicOri);
	DDX_Control(pDX, IDC_PICTURE_OUT, m_PicProc);
}

BEGIN_MESSAGE_MAP(CViewerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_FILEOPEN, &CViewerDlg::OnFileOpenMenuClick)
	ON_COMMAND(ID_FILE_FILECLOSE, &CViewerDlg::OnFileCloseMenuClick)
	ON_COMMAND(ID_CONVERT_CONVERTGRAY, &CViewerDlg::OnConvertGrayMenuClick)
	ON_COMMAND(ID_EDIT_SCALING, &CViewerDlg::OnEditScalingClick)
	ON_COMMAND(ID_EDIT_ROTATION, &CViewerDlg::OnEditRotationMenuClick)
	ON_COMMAND(ID_HISTOGRAM_GETHISTOGRAM, &CViewerDlg::OnGetHistogramMenuClick)
	ON_COMMAND(ID_HISTOGRAM_HISTOGRAMEQUALIZATION, &CViewerDlg::OnHistogramEqualizationMenuClick)
	ON_COMMAND(ID_HISTOGRAM_HISTOGRAMMATCHING, &CViewerDlg::OnHistogramMatchingMenuClick)
	ON_COMMAND(ID_EDIT_FILTER, &CViewerDlg::OnFilterMenuClicked)
	ON_COMMAND(ID_NOISEREDUCTION_ADDNOISE, &CViewerDlg::OnNoisereductionAddnoiseClicked)
	ON_COMMAND(ID_NOISEFILTERING_MEANFILTER, &CViewerDlg::OnNoisefilteringMeanfilterClicked)
	ON_COMMAND(ID_NOISEFILTERING_ORDER, &CViewerDlg::OnNoisefilteringOrderStatisticClicked)
	ON_COMMAND(ID_NOISEREDUCTION_GETPSNR32788, &CViewerDlg::OnGetpsnr)
END_MESSAGE_MAP()


// CViewerDlg 메시지 처리기

BOOL CViewerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CViewerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CViewerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CViewerDlg::DisplayImage(Mat DispMat, bool bInOut) {
	if (bInOut) {
		GetDlgItem(IDC_PICTURE_IN)->GetWindowRect(rect);
		ScreenToClient(rect);
		m_pDC = m_PicOri.GetDC();
		m_PicOri.GetClientRect(&rect);

	}
	else {
		GetDlgItem(IDC_PICTURE_OUT)->GetWindowRect(rect);
		ScreenToClient(rect);
		m_pDC = m_PicProc.GetDC();
		m_PicProc.GetClientRect(&rect);

	}
	IplImage* Ori = &IplImage(DispMat);
	IplImage* Resize = NULL;

	ResizeImage(Ori, &Resize, &rect);
	DisplayBitmap(m_pDC, rect, Resize);

}
void CViewerDlg::DisplayBitmap(CDC * pDC, CRect rect, IplImage *DisplplImage) {
	BITMAPINFO bitmapInfo;
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biXPelsPerMeter = 100;
	bitmapInfo.bmiHeader.biYPelsPerMeter = 100;
	bitmapInfo.bmiHeader.biClrUsed = 0;
	bitmapInfo.bmiHeader.biClrImportant = 0;
	bitmapInfo.bmiHeader.biSizeImage = 0;
	bitmapInfo.bmiHeader.biWidth = DisplplImage->width;
	bitmapInfo.bmiHeader.biHeight = DisplplImage->height;

	if (DisplplImage->nChannels == 3) {
		IplImage* ReverseImg = cvCreateImage(CvSize(DisplplImage->width, DisplplImage->height), 8, 3);

		for (int h = 0; h<DisplplImage->height; h++)
		{
			for (int w = 0; w < DisplplImage->width; w++)
			{
				ReverseImg->imageData[h * DisplplImage->widthStep + w * 3] = DisplplImage->imageData[(DisplplImage->height - h) * DisplplImage->widthStep + w * 3];
				ReverseImg->imageData[h * DisplplImage->widthStep + w * 3 + 1] = DisplplImage->imageData[(DisplplImage->height - h) * DisplplImage->widthStep + w * 3 + 1];
				ReverseImg->imageData[h * DisplplImage->widthStep + w * 3 + 2] = DisplplImage->imageData[(DisplplImage->height - h) * DisplplImage->widthStep + w * 3 + 2];
			}
		}
		bitmapInfo.bmiHeader.biBitCount = DisplplImage->depth * DisplplImage->nChannels;
		pDC->SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(pDC->GetSafeHdc(), rect.left, rect.top, rect.right, rect.bottom, 0, 0, DisplplImage->width, DisplplImage->height, ReverseImg->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
		cvReleaseImage(&ReverseImg);

	}
	else {
		IplImage* ReverseImg = cvCreateImage(cvGetSize(DisplplImage), DisplplImage->depth, 1);
		for (int h = 0; h<DisplplImage->height; h++)
		{
			for (int w = 0; w < DisplplImage->width; w++)
			{
				ReverseImg->imageData[h * DisplplImage->widthStep + w] = DisplplImage->imageData[(DisplplImage->height - h)* DisplplImage->widthStep + w];
			}
		}
		IplImage * tmp = cvCreateImage(cvGetSize(DisplplImage), DisplplImage->depth, 3);
		cvCvtColor(ReverseImg, tmp, CV_GRAY2BGR);

		bitmapInfo.bmiHeader.biBitCount = tmp->depth * tmp->nChannels;
		pDC->SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(pDC->GetSafeHdc(), rect.left, rect.top, rect.right, rect.bottom, 0, 0, tmp->width, tmp->height, tmp->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);

		cvReleaseImage(&ReverseImg);
		cvReleaseImage(&tmp);
	}
}
void CViewerDlg::ResizeImage(IplImage * src, IplImage**dst, CRect* rect) {

	int ndst_width = 0, ndst_height = 0;

	//먼저, S 상의 가로와 세로 중 장측들 구한다.
	if (src->width > src->height) {
		ndst_width = rect->Width();
		ndst_height = (src->height * rect->Width()) / src->width;
	}
	else {
		ndst_width = (src->width * rect->Height()) / src->height;
		ndst_height = rect->Height();
	}
	(*dst) = cvCreateImage(cvSize(ndst_width, ndst_height), IPL_DEPTH_8U, src->nChannels);

	cvResize(src, (*dst));
	rect->right = rect->left + ndst_width;
	rect->bottom = rect->top + ndst_height;
}


unsigned char ** MemAlloc2D(int nHeight, int nWidth, unsigned char nInitVal) 
{
	unsigned char** rtn = new unsigned char*[nHeight];
	for (int n = 0; n < nHeight; n++)
	{
		rtn[n] = new unsigned char[nWidth];
		memset(rtn[n], nInitVal, sizeof(unsigned char) * nWidth);
	}
	return rtn;
}

void MemFree2D(unsigned char** Mem, int nHeight)
{
	for (int n = 0; n < nHeight; n++) 
	{
		delete[] Mem[n];

	}
	delete[] Mem;
}

void CViewerDlg::OnFileOpenMenuClick()
{
	CFileDialog dlg(TRUE);

	if (isImageOpened)
	{
		if (ch_in_1 != NULL)
		{
			MemFree2D(ch_in_1, nHeight_in);
		}
		if (ch_in_2 != NULL)
		{
			if (nFormat == FORMAT_YUV420)
			{
				MemFree2D(ch_in_2, nHeight_in / 2);
			}
			else MemFree2D(ch_in_2, nHeight_in);
		}
		if (ch_in_3 != NULL)
		{
			if (nFormat == FORMAT_YUV420)
			{
				MemFree2D(ch_in_3, nHeight_in / 2);
			}
			else MemFree2D(ch_in_3, nHeight_in);
		}
		if (ch_in_gray != NULL)
		{
			MemFree2D(ch_in_gray, nHeight_in);

		}
	}
	if (dlg.DoModal() == IDOK)
	{
		if (dlg.GetFileExt() != "jpg" && dlg.GetFileExt() != "JPG" && dlg.GetFileExt() != "raw" && dlg.GetFileExt() != "yuv")
		{
			MessageBox("JPG 또는 YUV, Gray 파일이 아닙니다.");
			return;
		}
		
		InpFileName = dlg.GetFileTitle();

		if (dlg.GetFileExt() == "jpg" || dlg.GetFileExt() == "JPG")
		{
			Ori_Img = imread((const char*)dlg.GetPathName());
			nHeight_in = Ori_Img.rows;
			nWidth_in = Ori_Img.cols;
			if (Ori_Img.channels() == 3)
			{
				ch_in_1 = MemAlloc2D(nHeight_in, nWidth_in, 0);
				ch_in_2 = MemAlloc2D(nHeight_in, nWidth_in, 0);
				ch_in_3 = MemAlloc2D(nHeight_in, nWidth_in, 0);

				for (int h = 0; h < nHeight_in; h++)
				{
					for (int w = 0; w < nWidth_in; w++)
					{
						Vec3b RGB = Ori_Img.at<Vec3b>(h, w);
						ch_in_1[h][w] = RGB[2];
						ch_in_2[h][w] = RGB[1];
						ch_in_3[h][w] = RGB[0];
					}

				}
				nFormat = FORMAT_RGB;
			}
			else
			{
				//Gray Image (Jpg)
				ch_in_gray = MemAlloc2D(nHeight_in, nWidth_in, 0);
				for (int h = 0; h < nHeight_in; h++)
				{
					for (int w = 0; w < nWidth_in; w++)
					{
						ch_in_gray[h][w] = Ori_Img.at<unsigned char>(h, w);
					}
				}
				nFormat = FORMAT_GRAY;
			}
			isImageOpened = true;
			DisplayImage(Ori_Img, true);

		}
		else {
			//raw, yuv file

			CRawInfoDlg RawInfoDlg;
			if (RawInfoDlg.DoModal() == IDOK)
			{
				nHeight_in = RawInfoDlg.GetRawHeight();
				nWidth_in = RawInfoDlg.GetRawWidth();
				nFormat = RawInfoDlg.GetRawFormat();

				if (nHeight_in == 0 || nWidth_in == 0)
				{
					MessageBox("값을 잘못 입력하였습니다.");
					return;
				}

				FILE * fp_in;
				fopen_s(&fp_in, (const char*)dlg.GetPathName(), "rb");
				if (nFormat == FORMAT_GRAY)
				{
					ch_in_gray = MemAlloc2D(nHeight_in, nWidth_in, 0);
					for (int h = 0; h < nHeight_in; h++)
					{
						fread(ch_in_gray[h], sizeof(unsigned char), nWidth_in, fp_in);
					}

					Ori_Img = Mat(nHeight_in, nWidth_in, CV_8UC1);
					for (int h = 0; h < nHeight_in; h++)
					{
						for (int w = 0; w < nWidth_in; w++)
						{
							Ori_Img.at<unsigned char>(h, w) = ch_in_gray[h][w];
						}
					}
				}
				else if (nFormat == FORMAT_YUV444)
				{
					ch_in_1 = MemAlloc2D(nHeight_in, nWidth_in, 0);
					ch_in_2 = MemAlloc2D(nHeight_in, nWidth_in, 0);
					ch_in_3 = MemAlloc2D(nHeight_in, nWidth_in, 0);
					for (int h = 0; h < nHeight_in; h++)
					{
						fread(ch_in_1[h], sizeof(unsigned char), nWidth_in, fp_in);
					}
					for (int h = 0; h < nHeight_in; h++)
					{
						fread(ch_in_2[h], sizeof(unsigned char), nWidth_in, fp_in);
					}
					for (int h = 0; h < nHeight_in; h++)
					{
						fread(ch_in_3[h], sizeof(unsigned char), nWidth_in, fp_in);
					}

					Ori_Img = Mat(nHeight_in, nWidth_in, CV_8UC3);
					for (int h = 0; h < nHeight_in; h++)
					{
						for (int w = 0; w < nWidth_in; w++)
						{
							Vec3b BGR;

							BGR[2] = static_cast<unsigned char>(ch_in_1[h][w] + 1.402 * (ch_in_3[h][w]));
							BGR[1] = static_cast<unsigned char>(ch_in_1[h][w] - 0.344 * (ch_in_2[h][w]) - 0.714 * (ch_in_3[h][w]));
							BGR[0] = static_cast<unsigned char>(ch_in_1[h][w] + 1.772 * (ch_in_2[h][w]));

							Ori_Img.at<Vec3b>(h, w) = BGR;

						}
					}
				}
				else if (nFormat == FORMAT_YUV420)
				{
					//nFormat == Format_YUV420

					ch_in_1 = MemAlloc2D(nHeight_in, nWidth_in, 0);
					ch_in_2 = MemAlloc2D(nHeight_in / 2, nWidth_in / 2, 0);
					ch_in_3 = MemAlloc2D(nHeight_in / 2, nWidth_in / 2, 0);

					for (int h = 0; h < nHeight_in; h++) 
					{
						fread(ch_in_1[h], sizeof(unsigned char), nWidth_in, fp_in);
					}
					for (int h = 0; h < nHeight_in / 2; h++) 
					{
						fread(ch_in_2[h], sizeof(unsigned char), nWidth_in / 2, fp_in);
					}
					for (int h = 0; h < nHeight_in / 2; h++) 
					{
						fread(ch_in_3[h], sizeof(unsigned char), nWidth_in / 2, fp_in);
					}

					Ori_Img = Mat(nHeight_in, nWidth_in, CV_8UC3);

					for (int h = 0; h < nHeight_in / 2; h++)
					{
						for (int w = 0; w < nWidth_in / 2; w++)
						{
							for (int y = 0; y < 2; y++)
							{
								for (int x = 0; x < 2; x++)
								{
									Vec3b BGR;
									BGR[2] = static_cast<unsigned char>(ch_in_1[h * 2 + y][w * 2 + x] + 1.402 *(ch_in_3[h][w]));
									BGR[1] = static_cast<unsigned char>(ch_in_1[h * 2 + y][w * 2 + x] - 0.344 * (ch_in_2[h][w]) - 0.714 * (ch_in_3[h][w]));
									BGR[0] = static_cast<unsigned char>(ch_in_1[h * 2 + y][w * 2 + x] + 1.772 * (ch_in_2[h][w]));

									Ori_Img.at<Vec3b>(h * 2 + y, w * 2 + x) = BGR;
								}
							}
						}
					}
					
				}
				fclose(fp_in);
				isImageOpened = true;
				DisplayImage(Ori_Img, true);
				
			}
		}
	}

}


void CViewerDlg::OnFileCloseMenuClick()
{
	if (isImageOpened)
	{
		if (ch_in_1 != NULL)
		{
			MemFree2D(ch_in_1, nHeight_in);
		}
		if (ch_in_2 != NULL)
		{
			if (nFormat == FORMAT_YUV420)
			{
				MemFree2D(ch_in_2, nHeight_in / 2);
			}
			else MemFree2D(ch_in_2, nHeight_in);
		}
		if (ch_in_3 != NULL)
		{
			if (nFormat == FORMAT_YUV420)
			{
				MemFree2D(ch_in_3, nHeight_in / 2);
			}
			else MemFree2D(ch_in_3, nHeight_in);
		}
		if (ch_in_gray != NULL)
		{
			MemFree2D(ch_in_gray, nHeight_in);
		}
	}
	::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
}


void CViewerDlg::OnConvertGrayMenuClick()
{
	if (isImageOpened)
	{
		if (nFormat == FORMAT_GRAY)
		{
			MessageBox("입력 영상이 회색조 영상입니다.");
			return;
		}

		if (nFormat == FORMAT_YUV444 || nFormat == FORMAT_YUV420)
		{
			Proc_Img = Mat(nHeight_in, nWidth_in, CV_8UC1);
			for (int h = 0; h < nHeight_in; h++)
			{
				for (int w = 0; w < nWidth_in; w++)
				{
					Proc_Img.at<unsigned char>(h, w) = ch_in_1[h][w];
				}
			}
			DisplayImage(Proc_Img, false);
			return;
		}
		if (nFormat == FORMAT_RGB)
		{
			if (ch_in_gray == NULL)
			{
				ch_in_gray = MemAlloc2D(nHeight_in, nWidth_in, 0);
			}
			for (int h = 0; h < nHeight_in; h++)
			{
				for (int w = 0; w < nWidth_in; w++)
				{
					ch_in_gray[h][w] = saturate_cast<unsigned char>(0.299 * ch_in_1[h][w] + 0.587*ch_in_2[h][w] + 0.114 * ch_in_3[h][w]);
				}
			}

			Proc_Img = Mat(nHeight_in, nWidth_in, CV_8UC1);
			for (int h = 0; h < nHeight_in; h++)
			{
				for (int w = 0; w < nWidth_in; w++)
				{
					Proc_Img.at<unsigned char>(h, w) = ch_in_gray[h][w];
				}
			}
			DisplayImage(Proc_Img, false);
			return;


		}

	}
	else
	{
		MessageBox("불러온 영상이 없습니다.");


	}
}


void CViewerDlg::OnEditScalingClick()
{
	if (isImageOpened && nFormat == FORMAT_GRAY)
	{
		if (ImgScalingDlg.DoModal() == IDOK) // 스케일링 정보를 받아옴
		{
			int nInterpolationType = ImgScalingDlg.GetInterpType(); // 보간 타입
			double dScaleRate = ImgScalingDlg.GetScaleRate(); // 스케일링 비율

			if (dScaleRate < 1 || dScaleRate > 2) // 스케일링 비율이 잘못되었음
			{
				MessageBox("스케일링 범위가 잘못되었습니다.");
				return;
			}
			// Scaling 후 영상의 크기 계산
			int nHeight_Scale = nHeight_in * dScaleRate;
			int nWidth_Scale = nWidth_in * dScaleRate;
			unsigned char** Out = MemAlloc2D(nHeight_Scale, nWidth_Scale, 0);

			for (int h = 0; h < nHeight_Scale; h++)
			{
				for (int w = 0; w < nWidth_Scale; w++)
				{
					double h_Ori = h / dScaleRate;
					double w_Ori = w / dScaleRate;
					if (isInsideBoundary(nHeight_Scale, nWidth_Scale, h_Ori, w_Ori))
					{
						if (nInterpolationType == BILINEAR) {
							Out[h][w] = BilinearInterpolation(ch_in_gray, nHeight_in, nWidth_in, h_Ori, w_Ori);
						}
						else {
							Out[h][w] = BicubicInterpolation(ch_in_gray, nHeight_in, nWidth_in, h_Ori, w_Ori);
						}
					}
				}
			}

			Ori_Img = Mat(nHeight_in, nWidth_in, CV_8UC1);
			Proc_Img = Mat(nHeight_Scale, nWidth_Scale, CV_8UC1);
			for (int h = 0; h < nHeight_in; h++)
			{
				for (int w = 0; w < nWidth_in; w++)
				{
					Ori_Img.at<unsigned char>(h, w) = ch_in_gray[h][w];
				}
			}
			for (int h = 0; h < nHeight_Scale; h++)
			{
				for (int w = 0; w < nWidth_Scale; w++)
				{
					Proc_Img.at<unsigned char>(h, w) = Out[h][w];
				}
			}
			imshow("Original Image", Ori_Img);
			imshow("Scaled Image", Proc_Img);
			waitKey(0);


		}
	}
	else {
		MessageBox("불러온 영상이 없거나 영상 포맷이 회색조 영상이 아닙니다.");
	}
}
bool CViewerDlg::isInsideBoundary(int nHeight, int nWidth, double h, double w)
{
	if (h >= 0 && w >= 0 && h < nHeight && w < nWidth) 
	{
		return true;
	}
	else {
		return false;
	}
}

unsigned char CViewerDlg::BilinearInterpolation(unsigned char** In, int nHeight_Ori, int nWidth_Ori, double h_Cvt, double w_Cvt)
{
	int x1, y1, x2, y2;
	x1 = floor(w_Cvt);		//소숫점으로 나온 결과를 내림.
	y1 = floor(h_Cvt);

	x2 = ceil(w_Cvt);			//소숫점으로 나온 결과를 올림.
	y2 = ceil(h_Cvt);

	if (x2 == nWidth_Ori)		//외곽 픽셀은 바로 인접한 값으로 계산
		x2 -= 1;

	if (y2 == nHeight_Ori)		//외곽 픽셀은 바로 인접한 값으로 계산
		y2 -= 1;

	double a = w_Cvt - x1;
	double b = h_Cvt - y1;

	double result = (1.0 - a) * (1.0 - b) * In[y1][x1]
		+ a * (1.0 - b) * In[y1][x2]
		+ (1.0 - a) * b * In[y2][x1]
		+ a * b * In[y2][x2];

	return result;
}

unsigned char CViewerDlg::BicubicInterpolation(unsigned char** In, int nHeight_Ori, int nWidth_Ori, double h_Cvt, double w_Cvt)
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	double p1, p2, p3, p4;
	double r1, r2, r3, r4;

	x2 = floor(w_Cvt);
	y2 = floor(h_Cvt);

	x1 = x2 - 1;
	x3 = x2 + 1;
	x4 = x2 + 2;

	y1 = y2 - 1;
	y3 = y2 + 1;
	y4 = y2 + 2;


	if (x1 < 0)
		x1 = 0;
	if (x3 >= nWidth_Ori)
		x3 = nWidth_Ori - 1;
	if (x4 >= nWidth_Ori)
		x4 = nWidth_Ori - 1;

	if (y1 < 0)
		y1 = 0;
	if (y3 >= nHeight_Ori)
		y3 = nHeight_Ori - 1;
	if (y4 >= nHeight_Ori)
		y4 = nHeight_Ori - 1;


	double d1 = w_Cvt - x2;
	double d2 = h_Cvt - y2;


	p1 = In[y1][x1];
	p2 = In[y1][x2];
	p3 = In[y1][x3];
	p4 = In[y1][x4];
	r1 = (((-1)*p1 + 3 * p2 + (-3)*p3 + p4)*d1*d1*d1 + (2 * p1 + (-5)*p2 + 4 * p3 + (-1)*p4)*d1*d1 + ((-1)*p1 + p3)*d1 + 2 * p2) / 2.0;

	p1 = In[y2][x1];
	p2 = In[y2][x2];
	p3 = In[y2][x3];
	p4 = In[y2][x4];
	r2 = (((-1)*p1 + 3 * p2 + (-3)*p3 + p4)*d1*d1*d1 + (2 * p1 + (-5)*p2 + 4 * p3 + (-1)*p4)*d1*d1 + ((-1)*p1 + p3)*d1 + 2 * p2) / 2.0;

	p1 = In[y3][x1];
	p2 = In[y3][x2];
	p3 = In[y3][x3];
	p4 = In[y3][x4];
	r3 = (((-1)*p1 + 3 * p2 + (-3)*p3 + p4)*d1*d1*d1 + (2 * p1 + (-5)*p2 + 4 * p3 + (-1)*p4)*d1*d1 + ((-1)*p1 + p3)*d1 + 2 * p2) / 2.0;

	p1 = In[y4][x1];
	p2 = In[y4][x2];
	p3 = In[y4][x3];
	p4 = In[y4][x4];
	r4 = (((-1)*p1 + 3 * p2 + (-3)*p3 + p4)*d1*d1*d1 + (2 * p1 + (-5)*p2 + 4 * p3 + (-1)*p4)*d1*d1 + ((-1)*p1 + p3)*d1 + 2 * p2) / 2.0;

	double result = (((-1)*r1 + 3 * r2 + (-3)*r3 + r4)*d2*d2*d2 + (2 * r1 + (-5)*r2 + 4 * r3 + (-1)*r4)*d2*d2 + ((-1)*r1 + r3)*d2 + 2 * r2) / 2.0;


	return result;
}


void CViewerDlg::OnEditRotationMenuClick()
{
	if (isImageOpened && nFormat == FORMAT_GRAY)
	{
		if (RotationDlg.DoModal() == IDOK) // 스케일링 정보를 받아옴
		{
			int nInterpolationType = RotationDlg.GetInterpolationType(); // 보간 타입
			double nAngle = RotationDlg.GetAngle(); // 스케일링 비율

			if (nAngle < 0 || nAngle > 360)
			{
				MessageBox("회전 범위가 잘못 되었습니다.");
				return;
			}

			unsigned char** Out = MemAlloc2D(nHeight_in, nWidth_in, 0);
			int nHeight_2 = nHeight_in / 2;
			int nWidth_2 = nWidth_in / 2;

			double h_Rotate = 0;
			double w_Rotate = 0;

			for (int h = 0; h < nHeight_in; h++)
			{
				for (int w = 0; w < nWidth_in; w++)
				{
					//회전 계산

					int centerX = (nWidth_in / 2) - 1;
					int centerY = (nHeight_in / 2) - 1;
					double radion = 3.141592 / (180.0 / nAngle);

					w_Rotate = (h - centerY) * sin(-radion) + (w - centerX) * cos(-radion) + centerX;
					h_Rotate = (h - centerY) * cos(-radion) - (w - centerX) * sin(-radion) + centerY;

					if (w_Rotate < 0 || w_Rotate > nWidth_in - 1 || h_Rotate < 0 || h_Rotate > nHeight_in - 1)
						continue;

					if (isInsideBoundary(nHeight_in, nWidth_in, h_Rotate, w_Rotate))
					{
						if (nInterpolationType == BILINEAR) {
							Out[h][w] = BilinearInterpolation(ch_in_gray, nHeight_in, nWidth_in, h_Rotate, w_Rotate);
						}
						else {
							Out[h][w] = BicubicInterpolation(ch_in_gray, nHeight_in, nWidth_in, h_Rotate, w_Rotate);
						}
					}
				}
			}

			Proc_Img = Mat(nHeight_in, nWidth_in, CV_8UC1);
			for (int h = 0; h < nHeight_in; h++)
			{
				for (int w = 0; w < nWidth_in; w++)
				{
					Proc_Img.at<unsigned char>(h, w) = Out[h][w];
				}
			}

			DisplayImage(Proc_Img, false);
			MemFree2D(Out, nHeight_in);
		}
	}
	else {
		MessageBox("불러온 영상이 없거나 영상 포맷이 회색조 영상이 아닙니다.");
	}
}


void CViewerDlg::OnGetHistogramMenuClick()
{
	if (isImageOpened &&nFormat == FORMAT_GRAY) {

		if (Hist == NULL)
		{
			Hist = new int[256];

		}
		memset(Hist, 0, sizeof(int) * 256);

		for (int h = 0; h < nHeight_in; h++)
		{
			for (int w = 0; w < nWidth_in; w++)
			{
				Hist[ch_in_gray[h][w]]++;
			}
		}

		int nMax = 0;

		for (int n = 0; n < 256; n++) {
			if (nMax < Hist[n])
			{
				nMax = Hist[n];

			}
		}

		double dNormalizeFactor = 255.0 / nMax;

		Mat HisDisp = Mat(256, 256, CV_8UC1);
		HisDisp = Scalar::all(0);

		for (int w = 0; w < 256; w++)
		{
			int dNormalizedValue = (int)Hist[w] * dNormalizeFactor;
			for (int h = 255; h > 255 - dNormalizedValue; h--)
			{
				HisDisp.at<unsigned char>(h, w) = 255;
			}
		}
		imshow("Histogram of Input Image", HisDisp);
		waitKey(0);
	}
}

void DisplayHistogram(int *Hist)
{
	int nMax = 0;

	for (int i = 0; i < 256; i++) {
		if (nMax < Hist[i]) {
			nMax = Hist[i];
		}
	}

	double dNormalizeFactor = 255.0 / nMax;

	Mat HisDisp = Mat(256, 256, CV_8UC1);
	HisDisp = Scalar::all(0);

	for (int w = 0; w < 256; w++)
	{
		int dNormalizedValue = (int)Hist[w] * dNormalizeFactor;
		for (int h = 255; h > 255 - dNormalizedValue; h--)
		{
			HisDisp.at<unsigned char>(h, w) = 255;
		}
	}
	imshow("Histogram", HisDisp);
	waitKey(0);

}

void CViewerDlg::OnHistogramEqualizationMenuClick()
{
	if (isImageOpened && nFormat == FORMAT_GRAY)
	{
		if (Hist == NULL)
		{
			Hist = new int[256];

		}
		memset(Hist, 0, sizeof(int) * 256);

		for (int h = 0; h < nHeight_in; h++)
		{
			for (int w = 0; w < nWidth_in; w++)
			{
				Hist[ch_in_gray[h][w]]++;
			}
		}

		//Histogram Equalization
		double Hist_CDF[256] = { 0,0 };
		Mat Eq_Img = Mat(256, 256, CV_8UC1);

		Hist_CDF[0] = (double)Hist[0] / (nHeight_in *nWidth_in);

		for (int i = 1; i < 256; i++)
		{
			Hist_CDF[i] = (double)Hist[i] / (nHeight_in *nWidth_in) + Hist_CDF[i - 1];
		}

		for (int i = 0; i < 256; i++)
		{
			Hist_CDF[i] = round(Hist_CDF[i] * 255);
		}

		for (int h = 0; h < nHeight_in; h++) {
			for (int w = 0; w < nWidth_in; w++) {
				Eq_Img.at<unsigned char>(h, w) = Hist_CDF[ch_in_gray[h][w]];
			}
		}

		//Display Result
		int *Hist_Eq = new int[256];
		memset(Hist_Eq, 0, sizeof(int) * 256);

		for (int h = 0; h < nHeight_in; h++) {
			for (int w = 0; w < nWidth_in; w++) {
				Hist_Eq[Eq_Img.at<unsigned char>(h, w)]++;
			}
		}

		DisplayImage(Eq_Img, false);
		DisplayHistogram(Hist);
		DisplayHistogram(Hist_Eq);

		delete[] Hist_Eq;

	}
}


void CViewerDlg::OnHistogramMatchingMenuClick()
{
	if (isImageOpened && nFormat == FORMAT_GRAY)
	{
		if (Hist == NULL)
		{
			Hist = new int[256];

		}
		memset(Hist, 0, sizeof(int) * 256);

		for (int h = 0; h < nHeight_in; h++)
		{
			for (int w = 0; w < nWidth_in; w++)
			{
				Hist[ch_in_gray[h][w]]++;
			}
		}

		//Histogram Matching
		Mat MatchImg(256, 256, CV_8UC1), RefImg(nHeight_in, nWidth_in, CV_8UC1);
		int Hist_Ref[256] = { 0 };
		int Hist_Mat[256] = { 0 };
		float Hist_CDF[256], Hist_CDF_Ref[256];

		MatchImg = Scalar::all(0);
		RefImg = Scalar::all(0);

		//참조영상 생성및 히스토그램 계산
		srand(GetTickCount());
		for (int h = 0; h < RefImg.rows; h++)
		{
			for (int w = 0; w < RefImg.cols; w++)
			{
				RefImg.at<unsigned char>(h, w) = (unsigned char)rand() % 255;
				Hist_Ref[RefImg.at<unsigned char>(h, w)]++;
			}
		}

		//get cdf
		Hist_CDF[0] = (double)Hist[0] / (nHeight_in*nWidth_in);
		Hist_CDF_Ref[0] = (double)Hist_Ref[0] / (nHeight_in*nWidth_in);

		for (int n = 1; n < 256; n++) {
			Hist_CDF[n] = (double)Hist[n] / (nHeight_in*nWidth_in) + Hist_CDF[n - 1];
			Hist_CDF_Ref[n] = (double)Hist_Ref[n] / (nHeight_in*nWidth_in) + Hist_CDF_Ref[n - 1];

		}
		
		int* lut = NULL;	
		lut = (int *)malloc(sizeof(int) * nHeight_in);
		memset(lut, 0, sizeof(int) * nHeight_in);
		
		for (int w = 0; w < MatchImg.cols; w++)
		{
			for (int h = 0; h < MatchImg.rows; h++)
			{
				if (Hist_CDF[w] == Hist_CDF_Ref[h]) {   //lnput영상과 reference영상의 cdf가 같은경우
					lut[w] = Hist_CDF_Ref[h] * 255;
					break;
				}
				else if (Hist_CDF[w] < Hist_CDF_Ref[h]) {   //lnput영상보다 reference영상의 cdf가 큰경우
					lut[w] = Hist_CDF_Ref[h-1] * 255;
					break;
				}
			}
		}
	
		for (int h = 0; h < MatchImg.rows; h++) 
		{   
			for (int w = 0; w < MatchImg.cols; w++)
			{
				MatchImg.at<unsigned char>(h, w) = lut[ch_in_gray[h][w]];
			}
		}

		for (int h = 0; h < nHeight_in; h++)
		{   
			for (int w = 0; w < nWidth_in; w++) 
			{
				Hist_Mat[MatchImg.at<unsigned char>(h, w)]++;
			}
		}

			
		DisplayImage(MatchImg, false);
		DisplayHistogram(Hist_Ref);
		DisplayHistogram(Hist_Mat);

	}
}


void CViewerDlg::OnFilterMenuClicked()
{
	if (isImageOpened && nFormat == FORMAT_GRAY)
	{
		CFilterDlg FilterDlg;
		unsigned char** Pad, **Out;
		Out = MemAlloc2D(nHeight_in, nWidth_in, 0);

		if (FilterDlg.DoModal() == IDOK)
		{
			int nFilterType = FilterDlg.getFilterType();
			int nFilterSize = FilterDlg.getFilterSize();

			double dSigma = FilterDlg.getSigma();
			switch (nFilterType)
			{
			case FILTER_AVERAGE:
				if (nFilterSize >= 3) {
					if (nFilterSize % 2 == 0) {
						nFilterSize++;
					}
					Pad = Padding(ch_in_gray, nHeight_in, nWidth_in, nFilterSize);
					AverageFilter(Pad, Out, nHeight_in, nWidth_in, nFilterSize);
					MemFree2D(Pad, nHeight_in + (int)(nFilterSize / 2) * 2);
				}
				else {
					MessageBox("Filter Size가 잘못 되었습니다. Filter Size는 3이상의 정수 값을 가져야합니다.");

				}
				break;
			case FILTER_SMOOTH:
				Pad = Padding(ch_in_gray, nHeight_in, nWidth_in, 3);
				SmoothFilter(Pad, Out, nHeight_in, nWidth_in);
				MemFree2D(Pad, nHeight_in + 2);
				break;
			case FILTER_SHARPEN:
				Pad = Padding(ch_in_gray, nHeight_in, nWidth_in, 3);
				SharpenFilter(Pad, Out, nHeight_in, nWidth_in);
				MemFree2D(Pad, nHeight_in + 2);
				break;
			case FILTER_GAUSSIAN:
				if (nFilterSize >= 3) {
					if (nFilterSize % 2 == 0) {
						nFilterSize++;
					}
					Pad = Padding(ch_in_gray, nHeight_in, nWidth_in, nFilterSize);
					GaussianFilter(Pad, Out, nHeight_in, nWidth_in, nFilterSize,dSigma);
					MemFree2D(Pad, nHeight_in + (int)(nFilterSize / 2) * 2);
				}
				else {
					MessageBox("Filter Size가 잘못 되었습니다. Filter Size는 3이상의 정수 값을 가져야합니다.");

				}
				break;
			}

			Proc_Img = Mat(nHeight_in, nWidth_in, CV_8UC1);
			for (int h = 0; h < nHeight_in; h++) {
				for (int w = 0; w < nWidth_in; w++) {
					Proc_Img.at<unsigned char>(h, w) = Out[h][w];
				}
			}
			DisplayImage(Proc_Img, false);
			MemFree2D(Out, nHeight_in);



		}
	}
	else {
		MessageBox("불러온 영상이 없거나 영상 포맷이 회색조 영상이 아닙니다.");
	}
}


unsigned char** Padding(unsigned char** In, int nHeight, int nWidth, int nFilterSize) {
	int nPadSize = (int)(nFilterSize / 2);
	unsigned char** Pad = MemAlloc2D(nHeight + 2 * nPadSize, nWidth + 2 * nPadSize, 0);

	for (int h = 0; h < nHeight; h++) {
		for (int w = 0; w < nWidth; w++) {
			Pad[h + nPadSize][w + nPadSize] = In[h][w];
		}
	}

	for (int h = 0; h < nPadSize; h++) {
		for (int w = 0; w < nWidth; w++) {
			Pad[h][w + nPadSize] = In[0][w];
			Pad[h + (nHeight - 1)][w + nPadSize] = In[nHeight - 1][w];
		}
	}

	for (int h = 0; h < nHeight; h++) {
		for (int w = 0; w < nPadSize; w++) {
			Pad[h + nPadSize][w] = In[h][0];
			Pad[h + nPadSize][w + (nWidth - 1)] = In[h][nWidth - 1];
		}
	}

	for (int h = 0; h < nPadSize; h++) {
		for (int w = 0; w < nPadSize; w++) {
			Pad[h][w] = In[0][0];
			Pad[h + (nHeight - 1)][w] = In[nHeight - 1][0];
			Pad[h][w + (nWidth - 1)] = In[0][nWidth - 1];
			Pad[h + (nHeight - 1)][w + (nWidth - 1)] = In[nHeight - 1][nWidth - 1];
		}
	}
	return Pad;
}
void AverageFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth, int nFilterSize)
{
	int pad_size = (nFilterSize / 2);
	double **AverageF = new double *[nFilterSize];

	for (int i = 0; i < nFilterSize; i++) {
		AverageF[i] = new double[nFilterSize];
		for (int j = 0; j < nFilterSize; j++) {
			AverageF[i][j] = (1.0) / (nFilterSize * nFilterSize);
		}
	}

	for (int i = pad_size; i < nHeight + pad_size; i++)
	{
		for (int j = pad_size; j < nWidth + pad_size; j++)
		{
			double ftemp = 0;
			for (int mask_x = -pad_size; mask_x <= pad_size; mask_x++)
			{
				for (int mask_y = -pad_size; mask_y <= pad_size; mask_y++)
				{
					ftemp += (In_Pad[i + mask_x][j + mask_y] * AverageF[mask_x + pad_size][mask_y + pad_size]);

				}
			}
			Out[i - pad_size][j - pad_size] = (unsigned char)ftemp;
		}
	}
}


void SmoothFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth)
{
	int nFilterSize = 3;
	int pad_size = (nFilterSize / 2);
	double **SmoothF = new double *[nFilterSize];

	for (int i = 0; i < nFilterSize; i++) {
		SmoothF[i] = new double[nFilterSize];
		memset(SmoothF[i], 0, sizeof(double)*nFilterSize);
	}


	SmoothF[0][0] = 0.0625;
	SmoothF[1][0] = 0.125;
	SmoothF[2][0] = 0.0625;
	SmoothF[0][1] = 0.125;
	SmoothF[1][1] = 0.25;
	SmoothF[2][1] = 0.125;
	SmoothF[0][2] = 0.0625;
	SmoothF[1][2] = 0.125;
	SmoothF[2][2] = 0.0625;

	for (int i = pad_size; i < nHeight + pad_size; i++)
	{
		for (int j = pad_size; j < nWidth + pad_size; j++)
		{
			double ftemp = 0;
			for (int mask_x = -pad_size; mask_x <= pad_size; mask_x++)
			{
				for (int mask_y = -pad_size; mask_y <= pad_size; mask_y++)
				{
					ftemp += (In_Pad[i + mask_x][j + mask_y] * SmoothF[mask_x + pad_size][mask_y + pad_size]);

				}
			}
			Out[i - pad_size][j - pad_size] = (unsigned char)ftemp;
		}
	}

}

void SharpenFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth)
{

	int nFilterSize = 3;
	int pad_size = (nFilterSize / 2);
	double **SharpenF = new double *[nFilterSize];

	for (int i = 0; i < nFilterSize; i++) {
		SharpenF[i] = new double[nFilterSize];
		memset(SharpenF[i], 0, sizeof(double)*nFilterSize);
	}

	SharpenF[0][0] = 0.0;
	SharpenF[1][0] = -1.0;
	SharpenF[2][0] = 0.0;
	SharpenF[0][1] = -1.0;
	SharpenF[1][1] = 5.0;
	SharpenF[2][1] = -1.0;
	SharpenF[0][2] = 0.0;
	SharpenF[1][2] = -1.0;
	SharpenF[2][2] = 0.0;


	for (int i = pad_size; i < nHeight + pad_size; i++)
	{
		for (int j = pad_size; j < nWidth + pad_size; j++)
		{
			double ftemp = 0;
			for (int mask_x = -pad_size; mask_x <= pad_size; mask_x++)
			{
				for (int mask_y = -pad_size; mask_y <= pad_size; mask_y++)
				{
					ftemp += (In_Pad[i + mask_x][j + mask_y] * SharpenF[mask_x + pad_size][mask_y + pad_size]);

				}
			}
			if (ftemp < 0)
				ftemp = 0;
			else if (ftemp > 255)
				ftemp = 255;
			Out[i - pad_size][j - pad_size] = (unsigned char)ftemp;
		}
	}
}


void GaussianFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth, int nFilterSize, double dSigma)
{
	double powsigma2 = 2 * dSigma * dSigma;
	double PI = 3.141592;
	
	int pad_size = (nFilterSize / 2);
	double **GaussianF = new double *[nFilterSize];

	for (int i = 0; i < nFilterSize; i++) {
		GaussianF[i] = new double[nFilterSize];
		memset(GaussianF[i], 0, sizeof(double)*nFilterSize);
	}

	
	double total = 0;
	for (int mask_x = -pad_size; mask_x <= pad_size; mask_x++)
	{
		for (int mask_y = -pad_size; mask_y <= pad_size; mask_y++)
		{
			double pos = (mask_x* mask_x) + (mask_y * mask_y);
			GaussianF[mask_x + pad_size][mask_y + pad_size] = (1 / powsigma2 * PI)* exp((-1.0) * pos / powsigma2);
			total += GaussianF[mask_x + pad_size][mask_y + pad_size];
		}
	}
	
	for (int i = 0; i < nFilterSize; i++) 
	{	
		for (int j = 0; j < nFilterSize; j++) 
		{
			GaussianF[i][j] /= total;
		}
	}
	
	for (int i = pad_size; i < nHeight + pad_size; i++)
	{
		for (int j = pad_size; j < nWidth + pad_size; j++)
		{
			double ftemp = 0;
			for (int mask_x = -pad_size; mask_x <= pad_size; mask_x++)
			{
				for (int mask_y = -pad_size; mask_y <= pad_size; mask_y++)
				{
					ftemp += (In_Pad[i + mask_x][j + mask_y] * GaussianF[mask_x + pad_size][mask_y + pad_size]);
				}
			}
			Out[i - pad_size][j - pad_size] = (unsigned char)ftemp;
		}
	}
}


void CViewerDlg::OnNoisereductionAddnoiseClicked()
{

	CAddNoiseDlg AddNoiseDlg;
	BYTE** NoiseImg = MemAlloc2D(nHeight_in, nWidth_in, 0);

	if (isImageOpened && nFormat == FORMAT_GRAY)
	{
		if (AddNoiseDlg.DoModal() == IDOK)
		{
			CString OutFileName = InpFileName;
			float Value_1 = AddNoiseDlg.GetVal_1();
			float Value_2 = AddNoiseDlg.GetVal_2();
			int nNoiseType = AddNoiseDlg.GetNoiseType();

			if (nNoiseType == NOISE_GN)
			{
				if (Value_2 < 1)
				{
					MessageBox("표준편차 값이 잘못되었습니다. 표준편차 값은 1 이상이여야 합니다.");
					MemFree2D(NoiseImg, nHeight_in);
					return;
				}
				InputGaussianNoise(ch_in_gray, NoiseImg, nHeight_in, nWidth_in, Value_1, Value_2);
				OutFileName += "_GN.raw";

			}
			else
			{
				if (Value_1 <= 0 && Value_2 <= 0)
				{
					MessageBox("두 개의 확률 값 중 적어도 하나는 0보다 커야 합니다.");
					MemFree2D(NoiseImg, nHeight_in);
					return;
				}
				InputSaltPepperNoise(ch_in_gray, NoiseImg, nHeight_in, nWidth_in, Value_1, Value_2);
				OutFileName += "_SPN.raw";
			}

			FILE* fp;

			fopen_s(&fp, OutFileName, "wb");
			for (int h = 0; h<nHeight_in; h++)
			{
				fwrite(NoiseImg[h], sizeof(unsigned char), nWidth_in, fp);
			}

			fclose(fp);
			MemFree2D(NoiseImg, nHeight_in);
		}
	}
}


void InputGaussianNoise(unsigned char** In, unsigned char ** Out, int nHeight, int nWidth, float fMean, float fStdev)
{
	float fTemp = 0, fPDF[256] = { 0.0f };

	GetGaussianPDF(fPDF, 256, fMean, fStdev);

	srand(GetTickCount());

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			fTemp = (float)In[h][w] + GetNoise(fPDF, 256);
			Out[h][w] = static_cast<unsigned char>(fTemp);
		}
	}
}

void InputSaltPepperNoise(unsigned char** In, unsigned char ** Out, int nHeight, int nWidth, float fSProb, float fPProb)
{
	float Low = fSProb;
	float High = 1.0f - fPProb;
	float fRand;

	srand(GetTickCount());
	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			fRand = ((float)rand() / RAND_MAX);
			if (fRand < Low)
			{
				Out[h][w] = 255;
			}
			else if (fRand > High)
			{
				Out[h][w] = 0;
			}
			else Out[h][w] = In[h][w];
		}
	}
}

void GetGaussianPDF(float* EmptyPDF, int nLength, float fMean, float fStDev)
{
	int n;
	int Center = nLength / 2;
	float x;
	double PI = 3.141592;

	for (n = 0; n<nLength; n++)
	{
		x = (float)(n - Center);
		EmptyPDF[n] = (1 / ((float)sqrt(2 * PI) * fStDev)) * exp(-pow(x - fMean, 2) / (2 * fStDev * fStDev));
	}
}

float GetNoise(float* PDF, int nLength)
{
	int n;
	int Center = nLength / 2;
	float fRand, fComp, fTemp = 0;
	float x = 0, fDiff;
	float* CDF = new float[nLength];

	CDF[0] = 0;

	fRand = (float)rand() / (RAND_MAX + 1); // 0~1 Uniform Distribution

	for (n = 1; n<nLength; n++)
	{
		CDF[n] = (PDF[n] + PDF[n - 1]) / 2 + CDF[n - 1];
		fDiff = fRand - CDF[n];
		if (fDiff < 0)
		{
			x = ((float)n - Center);
			break;
		}
	}
	fComp = (fRand - CDF[n - 1]) / (CDF[n] - CDF[n - 1]);

	delete[] CDF;

	return x + fComp;
}



void CViewerDlg::OnNoisefilteringMeanfilterClicked()
{
	CMeanFilterDlg MFDlg;

	if (isImageOpened == true && nFormat == FORMAT_GRAY) 
	{
		if (MFDlg.DoModal() == IDOK)
		{
			int nFilterSize = MFDlg.GetFilterSize();
			int nFilterType = MFDlg.GetMeanFilterType();

			if (nFilterSize < 3)
			{
				MessageBox("필터 크기가 잘못되었습니다.");
				return;

			}
			if (nFilterSize % 2 == 0) 
			{
				nFilterSize++;
			}

			CString OutFileName = InpFileName;
			unsigned char ** Out = MemAlloc2D(nHeight_in, nWidth_in, 0);

			switch (nFilterType)
			{
			case NF_ARITHMETIC:
				ArithmeticMeanFilter(ch_in_gray, Out, nHeight_in, nWidth_in, nFilterSize);
				OutFileName += "_AMF.raw";
				break;
			case NF_GEOMETRIC:
				GeometricMeanFilter(ch_in_gray, Out, nHeight_in, nWidth_in, nFilterSize);
				OutFileName += "_GMF.raw";
				break;
			case NF_HARMONIC:
				HarmonicMeanFilter(ch_in_gray, Out, nHeight_in, nWidth_in, nFilterSize);
				OutFileName += "_HMF.raw";
				break;
			case NF_CONTRAHARMONIC:
				int Q = MFDlg.GetQ();
				ContraharmonicMeanFilter(ch_in_gray, Out, nHeight_in, nWidth_in, nFilterSize, Q);
				OutFileName += "_CHMF.raw";
				break;
			}

			DisplayImage(GrayToMat(Out, nHeight_in, nWidth_in), false);
			
			FILE* fp;
			fopen_s(&fp, OutFileName, "wb");
			for (int h = 0; h < nHeight_in; h++)
			{
				fwrite(Out[h], sizeof(unsigned char), nWidth_in, fp);

			}
			fclose(fp);
		}

	}
}


void ArithmeticMeanFilter(unsigned char **Img_in, unsigned char ** Out, int nHeight, int nWidth, int nFilterSize)
{
	int nTemp, nPadSize = (int)(nFilterSize / 2);
	unsigned char ** Img_Pad = Padding(Img_in, nHeight, nWidth, nFilterSize);

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			nTemp = 0;

			for (int m = 0; m < nFilterSize; m++)
			{
				for (int n = 0; n < nFilterSize; n++)
				{
					nTemp += Img_Pad[h + m][w + n];
				}
			}
			Out[h][w] = static_cast<unsigned char>(nTemp / (nFilterSize*nFilterSize));
		}
	}

	MemFree2D(Img_Pad, nHeight + 2 * nPadSize);
}

void GeometricMeanFilter(unsigned char **Img_in, unsigned char ** Out, int nHeight, int nWidth, int nFilterSize)
{
	double nTemp;
	int nPadSize = (int)(nFilterSize / 2);
	unsigned char ** Img_Pad = Padding(Img_in, nHeight, nWidth, nFilterSize);

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			nTemp = 1;

			for (int m = 0; m < nFilterSize; m++)
			{
				for (int n = 0; n < nFilterSize; n++)
				{
					nTemp *= Img_Pad[h + m][w + n];
				}
			}
			Out[h][w] = static_cast<unsigned char>(pow(nTemp, 1.0 / (double)(nFilterSize*nFilterSize)));

		}
	}

	MemFree2D(Img_Pad, nHeight + 2 * nPadSize);
}

void HarmonicMeanFilter(unsigned char **Img_in, unsigned char ** Out, int nHeight, int nWidth, int nFilterSize)
{
	double nTemp;
	int nPadSize = (int)(nFilterSize / 2);
	unsigned char ** Img_Pad = Padding(Img_in, nHeight, nWidth, nFilterSize);

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			nTemp = 0;

			for (int m = 0; m < nFilterSize; m++)
			{
				for (int n = 0; n < nFilterSize; n++)
				{
					nTemp += 1.0 / Img_Pad[h + m][w + n];
				}
			}
			Out[h][w] = static_cast<unsigned char>((double)(nFilterSize*nFilterSize)/nTemp);
		}
	}

	MemFree2D(Img_Pad, nHeight + 2 * nPadSize);
}

void ContraharmonicMeanFilter(unsigned char **Img_in, unsigned char ** Out, int nHeight, int nWidth, int nFilterSize, int Q)
{
	double nTemp;
	double nTemp2;
	int nPadSize = (int)(nFilterSize / 2);
	unsigned char ** Img_Pad = Padding(Img_in, nHeight, nWidth, nFilterSize);

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			nTemp = 0;
			nTemp2 = 0;
			for (int m = 0; m < nFilterSize; m++)
			{
				for (int n = 0; n < nFilterSize; n++)
				{
					nTemp += pow(Img_Pad[h + m][w + n], Q);
					nTemp2 += pow(Img_Pad[h + m][w + n], Q+1);
				}
			}
			Out[h][w] = static_cast<unsigned char>(nTemp2 / nTemp);
		}
	}

	MemFree2D(Img_Pad, nHeight + 2 * nPadSize);
}

Mat GrayToMat(unsigned char ** Img, int nHeight, int nWidth)
{
	Mat rtn = Mat(nHeight, nWidth, CV_8UC1);

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			rtn.at<unsigned char>(h, w) = Img[h][w];
		}
	}
	return rtn;
}

void CViewerDlg::OnNoisefilteringOrderStatisticClicked()
{
	COrderStatisticsDlg OSFDlg;

	if (isImageOpened == true && nFormat == FORMAT_GRAY)
	{
		if (OSFDlg.DoModal() == IDOK)
		{
			int nFilterSize = OSFDlg.GetFilterSize1();
			int nFilterType = OSFDlg.GetOSFType();
			
			if (nFilterSize < 3)
			{
				MessageBox("필터 크기가 잘못되었습니다.");
				return;

			}
			if (nFilterSize % 2 == 0)
			{
				nFilterSize++;
			}

			CString OutFileName = InpFileName;
			unsigned char ** Out = MemAlloc2D(nHeight_in, nWidth_in, 0);

			switch (nFilterType)
			{
			case NF_MEDIAN:
				MedianFilter(ch_in_gray, Out, nHeight_in, nWidth_in, nFilterSize);
				OutFileName += "_MEDF.raw";
				break;
			case NF_ADAPTIVEMEDIAN:
				int MaxFilterSize = OSFDlg.GetFilterSize2();
				AdaptiveMedianFilter(ch_in_gray, Out, nHeight_in, nWidth_in, nFilterSize, MaxFilterSize);
				OutFileName += "_AMEDF.raw";
				break;


			}

			DisplayImage(GrayToMat(Out, nHeight_in, nWidth_in), false);

			FILE* fp;
			fopen_s(&fp, OutFileName, "wb");
			for (int h = 0; h < nHeight_in; h++)
			{
				fwrite(Out[h], sizeof(unsigned char), nWidth_in, fp);

			}
			fclose(fp);

		}
	}
}

void insertionSort(double arr[],int num)
{
	int temp, i, j;
	for (i = 0; i < num; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void MedianFilter(unsigned char **Img_in, unsigned char ** Out, int nHeight, int nWidth, int nFilterSize)
{
	int nPadSize = (int)(nFilterSize / 2);
	unsigned char ** Img_Pad = Padding(Img_in, nHeight, nWidth, nFilterSize);
	double * nTemp = (double*)malloc(sizeof(double)*nFilterSize*nFilterSize);

	for (int h = 0; h < nHeight; h++)
	{
		for (int w = 0; w < nWidth; w++)
		{
			int num = 0;
			for (int m = 0; m < nFilterSize; m++)
			{
				for (int n = 0; n < nFilterSize; n++)
				{
					nTemp[num++] = (double)Img_Pad[h + m][w + n];

				}
			}
			
			insertionSort(nTemp, nFilterSize*nFilterSize);

			Out[h][w] = static_cast<unsigned char>(nTemp[(nFilterSize*nFilterSize)/2]);
			
		}
	}

	MemFree2D(Img_Pad, nHeight + 2 * nPadSize);
}

void AdaptiveMedianFilter(unsigned char **Img_in, unsigned char ** Out, int nHeight, int nWidth, int nFilterSize_min, int nFilterSize_Max)
{
	int nFilterSize = nFilterSize_min;
	int nPadSize = (int)(nFilterSize_Max / 2);
	unsigned char ** Img_Pad = Padding(Img_in, nHeight, nWidth, nFilterSize_Max);
	double a1, a2, b1, b2;

	double * nTemp;

	int diff;
	int w, h;

	for (h = 0; h < nHeight; h++)
	{
		for (w = 0; w < nWidth; w++)
		{

			if (nFilterSize_Max == nFilterSize)
				diff = 0;
			else
				diff = (nFilterSize_Max - nFilterSize) / 2;

			nTemp = (double*)malloc(sizeof(double)*nFilterSize*nFilterSize);

			int num = 0;
			for (int m = 0; m < nFilterSize; m++)
			{
				for (int n = 0; n < nFilterSize; n++)
				{
					nTemp[num++] = (double)Img_Pad[h + diff + m][w + diff + n];

				}
			}

			insertionSort(nTemp, nFilterSize*nFilterSize);

			a1 = nTemp[(nFilterSize*nFilterSize) / 2] - nTemp[0];		// Zmed - Zmin
			a2 = nTemp[(nFilterSize*nFilterSize) / 2] - nTemp[(nFilterSize*nFilterSize) - 1];	//Zmed-Zmax

			if (a1 > 0 && a2 < 0)
			{
				//level B
				b1 = (double)Img_Pad[h + nPadSize][w + nPadSize] - nTemp[0];	//Zxy-Zmin
				b2 = (double)Img_Pad[h + nPadSize][w + nPadSize] - nTemp[(nFilterSize*nFilterSize) - 1];	///Zxy-Zmax

				if (b1 > 0 && b2 < 0) {
					Out[h][w] = static_cast<unsigned char>(Img_Pad[h + nPadSize][w + nPadSize]);
				}
				else {
					Out[h][w] = static_cast<unsigned char>(nTemp[(nFilterSize*nFilterSize) / 2]);
				}

				nFilterSize = nFilterSize_min;
				
				
			}
			else
			{
				nFilterSize += 2;
				if (nFilterSize <= nFilterSize_Max)
				{
					if (w > 0)
						w--;
					else
						w = -1;
		
				}
				else {
					Out[h][w] = static_cast<unsigned char>(Img_Pad[h + nPadSize][w + nPadSize]);
					nFilterSize = nFilterSize_min;
				
				}
			}

			delete[] nTemp;
			
				
		}
	}
	
	MemFree2D(Img_Pad, nHeight + 2 * nPadSize);
}

void CViewerDlg::OnGetpsnr()
{
	CPSNRDlg PSNRDlg;

	PSNRDlg.DoModal();
}
