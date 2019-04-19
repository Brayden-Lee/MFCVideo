
// MFCVideoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "MFCVideoDlg.h"
#include "afxdialogex.h"
#include "OpitionDialog.h"
#include "ValueDisplayDlg.h"
#include "AlertDisplayDlg.h"
#include "ChooseAlertLevel.h"
#include "constant.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCVideoDlg �Ի���


// ���캯��
CMFCVideoDlg::CMFCVideoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCVIDEO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCVideoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Ni, m_ListControl);
	DDX_Control(pDX, IDC_EditItem, m_Edit);
	DDX_Control(pDX, IDC_CURVE_1, m_ChartCtrl_Curve1);
	DDX_Control(pDX, IDC_OBSTACLE_PANEL, m_Obstacle_Panel);
	DDX_Control(pDX, IDC_METER_PANEL, m_Meter_Panel);
	DDX_Control(pDX, IDC_ROAD_MAP, m_Map);
	DDX_Control(pDX, IDC_VALUE, curve_value);
}

BEGIN_MESSAGE_MAP(CMFCVideoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_VIDEO_CLOSE, &CMFCVideoDlg::OnBnClickedVideoClose)
	ON_BN_CLICKED(IDC_VIDEO_PLAY, &CMFCVideoDlg::OnBnClickedVideoPlay)
	ON_BN_CLICKED(IDC_VIDEO_STOP, &CMFCVideoDlg::OnBnClickedVideoStop)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCVideoDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCVideoDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCVideoDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCVideoDlg::OnBnClickedRadio4)
	ON_NOTIFY(NM_DBLCLK, IDC_Ni, &CMFCVideoDlg::OnDblclkNi)
	ON_BN_CLICKED(IDC_BtnInsert, &CMFCVideoDlg::OnBnClickedInsert)
	ON_EN_KILLFOCUS(IDC_EditItem, &CMFCVideoDlg::OnEnKillfocusEdititem)
	ON_BN_CLICKED(IDC_DELETE_SOURCE, &CMFCVideoDlg::OnBnClickedDeleteSource)
	ON_NOTIFY(NM_HOVER, IDC_Ni, &CMFCVideoDlg::OnNMHoverNi)
	ON_BN_CLICKED(IDC_RADIO_SPEED_X, &CMFCVideoDlg::OnBnClickedRadioSpeedX)
	ON_BN_CLICKED(IDC_RADIO_SPEED_Y, &CMFCVideoDlg::OnBnClickedRadioSpeedY)
	ON_BN_CLICKED(IDC_RADIO_SPEED_Z, &CMFCVideoDlg::OnBnClickedRadioSpeedZ)
	ON_BN_CLICKED(IDC_DISPALY_VALUE, &CMFCVideoDlg::OnBnClickedDispalyValue)
	ON_BN_CLICKED(IDC_SET_ALERT, &CMFCVideoDlg::OnBnClickedSetAlert)
	ON_BN_CLICKED(IDC_ALERT_DETAIL, &CMFCVideoDlg::OnBnClickedAlertDetail)
	ON_STN_DBLCLK(IDC_VALUE, &CMFCVideoDlg::OnStnDblclickValue)
END_MESSAGE_MAP()


// CMFCVideoDlg ��Ϣ�������

BOOL CMFCVideoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	init();
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);    // Radio 1Ĭ��ѡ��
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);

	((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Z))->SetCheck(FALSE);

	GetDlgItem(IDC_VALUE)->ShowWindow(SW_HIDE);

	m_ProgressCtrl = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS_ALL_VIDEO);
	GetCurrentDirectory(MAX_PATH, m_saveDataPath);
	strcat_s(m_saveDataPath, "\\data");
	//MessageBox(m_saveDataPath);
	if (PathIsDirectory(m_saveDataPath) == FALSE)
	{
		CreateDirectory(m_saveDataPath, 0);
	}

	m_Edit.ShowWindow(SW_HIDE);
	CRect rect; m_ListControl.GetClientRect(&rect);
	int iLength = rect.Width();
	m_ListControl.SetExtendedStyle(m_ListControl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ListControl.InsertColumn(0, _T("���"), LVCFMT_CENTER, 40);
	m_ListControl.InsertColumn(1, _T("��������"), LVCFMT_CENTER, 70);
	m_ListControl.InsertColumn(2, _T("��ʻԱ"), LVCFMT_CENTER, 60);
	m_ListControl.InsertColumn(3, _T("·��"), LVCFMT_CENTER, (iLength - 170));

	// ��Ƶ�����ʼ��
	m_pVideoInfo1 = new CvideoIf();
	m_pPicCtlHdc1 = GetDlgItem(IDC_PicCtl1)->GetDC()->GetSafeHdc();   //��ȡ���ھ��
	GetDlgItem(IDC_PicCtl1)->GetClientRect(&m_PicCtlRect1);   //��ȡ�ͻ���������
	m_pVideoInfo2 = new CvideoIf();
	m_pPicCtlHdc2 = GetDlgItem(IDC_PicCtl2)->GetDC()->GetSafeHdc();   //��ȡ���ھ��
	GetDlgItem(IDC_PicCtl2)->GetClientRect(&m_PicCtlRect2);   //��ȡ�ͻ���������
	m_pVideoInfo3 = new CvideoIf();
	m_pPicCtlHdc3 = GetDlgItem(IDC_PicCtl3)->GetDC()->GetSafeHdc();   //��ȡ���ھ��
	GetDlgItem(IDC_PicCtl3)->GetClientRect(&m_PicCtlRect3);   //��ȡ�ͻ���������
	m_pVideoInfo4 = new CvideoIf();
	m_pPicCtlHdc4 = GetDlgItem(IDC_PicCtl4)->GetDC()->GetSafeHdc();   //��ȡ���ھ��
	GetDlgItem(IDC_PicCtl4)->GetClientRect(&m_PicCtlRect4);   //��ȡ�ͻ���������

	// �����ʼ����
	loadData();

	// �������ʼ��
	CChartAxis *pAxis = NULL;
	pAxis = m_ChartCtrl_Curve1.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_ChartCtrl_Curve1.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	/*
	// ʱ��������
	CChartDateTimeAxis* pDateAxis = NULL;
	pDateAxis = m_ChartCtrl_Curve1.CreateDateTimeAxis(CChartCtrl::BottomAxis);
	pDateAxis->SetAutomatic(true);
	pDateAxis->SetTickLabelFormat(false, _T("%H:%M:%S"));
	CChartAxis *pAxis = NULL;
	pAxis = m_ChartCtrl_Curve1.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	*/
	TChartString strTitle;
	strTitle = _T("Speed");
	m_ChartCtrl_Curve1.GetTitle()->AddString(TChartString(strTitle));


	// ���ٱ�
	COLORREF m_colorNeedle;
	m_colorNeedle = RGB(255, 255, 235);//etSysColor(COLOR_ACTIVEBORDER);
	m_Meter_Panel.SetNeedleColor(m_colorNeedle);   //����ָ����ɫ
	m_Meter_Panel.SetColorTick(TRUE);
	m_Meter_Panel.UpdateNeedle(0.0);

	ShowWindow(SW_MAXIMIZE);    //������󻯵���
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCVideoDlg::init()
{
	name_GuanDao = "";
	name_Radar = "";
	mTotalTime = 0;
	m_resDir = "";
	memset(m_saveDataPath, '\0', MAX_PATH * sizeof(char));
	m_index_speed = -30;
	m_index_radar = 0;
	m_Row = 0;
	m_Col = 0;
	setAlertEnable = false;
	video_index_1 = 0;
	video_index_2 = 0;
	video_index_3 = 0;
	video_index_4 = 0;
}

void CMFCVideoDlg::release_mem()
{
	speed_X.clear();
	speed_Y.clear();
	speed_Z.clear();
	m_obstacle.clear();
	m_locOnmap.clear();
	path_video1.clear();
	path_video2.clear();
	path_video3.clear();
	path_video4.clear();
}

void CMFCVideoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCVideoDlg::OnPaint()
{
	if (IsIconic())    // ������С��
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCVideoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCVideoDlg::OnTimer(UINT_PTR nIDEvent)    //timer 
{
	CString tmpDir = "";
	switch (nIDEvent)
	{
	case TIMER_VIDEO_1:
		if (m_pVideoInfo1->m_pCapture)  //�ж���Ƶ֡�Ƿ�Ϊ�յ�
		{
			IplImage* frame;
			frame = cvQueryFrame(m_pVideoInfo1->m_pCapture);//��ͼ������� ΪNULL��ʾ�����Ƶ��������
			if (frame)
			{
				cvCopy(frame, m_pVideoInfo1->m_pFrameImage);//��ͼ�񿽱��Լ��Ŀռ�
				cvFlip(m_pVideoInfo1->m_pFrameImage);//���ͼ���ǵ��õ�ʱ��ʹ��
				m_CvvImage1.CopyOf(m_pVideoInfo1->m_pFrameImage);
				m_CvvImage1.DrawToHDC(m_pPicCtlHdc1, m_PicCtlRect1);
			}
			else if (video_index_1 < path_video1.size())    // ������һ����Ƶ
			{
				tmpDir = m_resDir + _T("\\") + _T(VIDEODIR_ONE);
				// �ͷ���һ����Ƶ����Դ
				cvReleaseCapture(&m_pVideoInfo1->m_pCapture);
				m_pVideoInfo1->m_pCapture = NULL;
				cvReleaseImage(&m_pVideoInfo1->m_pFrameImage);
				m_pVideoInfo1->m_pFrameImage = NULL;

				ChangeVideo(tmpDir, path_video1[video_index_1], m_pVideoInfo1);
				//MessageBox(path_video1.front());
				video_index_1++;
			}
		}
		break;
	case TIMER_VIDEO_2:
		if (m_pVideoInfo2->m_pCapture)  //�ж���Ƶ֡�Ƿ�Ϊ�յ�
		{
			IplImage* frame2;
			frame2 = cvQueryFrame(m_pVideoInfo2->m_pCapture);//��ͼ�������
			if (frame2)
			{
				cvCopy(frame2, m_pVideoInfo2->m_pFrameImage);//��ͼ�񿽱��Լ��Ŀռ�
				cvFlip(m_pVideoInfo2->m_pFrameImage);//���ͼ���ǵ��õ�ʱ��ʹ��
				m_CvvImage2.CopyOf(m_pVideoInfo2->m_pFrameImage);
				m_CvvImage2.DrawToHDC(m_pPicCtlHdc2, m_PicCtlRect2);
			}
		}
		break;
	case TIMER_VIDEO_3:
		if (m_pVideoInfo3->m_pCapture)  //�ж���Ƶ֡�Ƿ�Ϊ�յ�
		{
			IplImage* frame3;
			frame3 = cvQueryFrame(m_pVideoInfo3->m_pCapture);//��ͼ�������
			if (frame3)
			{
				cvCopy(frame3, m_pVideoInfo3->m_pFrameImage);//��ͼ�񿽱��Լ��Ŀռ�
				cvFlip(m_pVideoInfo3->m_pFrameImage);//���ͼ���ǵ��õ�ʱ��ʹ��
				m_CvvImage3.CopyOf(m_pVideoInfo3->m_pFrameImage);
				m_CvvImage3.DrawToHDC(m_pPicCtlHdc3, m_PicCtlRect3);
			}
		}
		break;
	case TIMER_VIDEO_4:
		if (m_pVideoInfo4->m_pCapture)  //�ж���Ƶ֡�Ƿ�Ϊ�յ�
		{
			IplImage* frame4;
			frame4 = cvQueryFrame(m_pVideoInfo4->m_pCapture);//��ͼ�������
			if (frame4)
			{
				cvCopy(frame4, m_pVideoInfo4->m_pFrameImage);//��ͼ�񿽱��Լ��Ŀռ�
				cvFlip(m_pVideoInfo4->m_pFrameImage);//���ͼ���ǵ��õ�ʱ��ʹ��
				m_CvvImage4.CopyOf(m_pVideoInfo4->m_pFrameImage);
				m_CvvImage4.DrawToHDC(m_pPicCtlHdc4, m_PicCtlRect4);
			}
		}
		break;
	case TIMER_PROGRESS:
	{
		static int pos = 0;
		pos = pos + 50;
		if (pos > mTotalTime) pos = mTotalTime;
		m_ProgressCtrl->SetPos(pos);
		break;
	}
	case TIMER_CURVE:
	{
		m_index_speed++;
		int type;
		if (((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->GetCheck()) {
			type = SPEED_X;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->GetCheck()) {
			type = SPEED_Y;
		}
		else {
			type = SPEED_Z;
		}
		double x[30], y[30];
		int row = speed_X.size();
		if (m_index_speed + m_cur_index > row)
			m_index_speed = -30;    // For test
		for (int i = 0; i < 30; i++)
		{
			x[i] = i;
			switch (type)
			{
			case SPEED_X:
				if (m_index_speed + i < 0)
					y[i] = 0;
				else
					y[i] = speed_X[(m_index_speed + i) % row];    // ÿ����ʾ30����
				break;
			case SPEED_Y:
				if (m_index_speed + i < 0)
					y[i] = 0;
				else
					y[i] = speed_Y[(m_index_speed + i) % row];
				break;
			default:
				if (m_index_speed + i < 0)
					y[i] = 0;
				else
					y[i] = speed_Z[(m_index_speed + i) % row];
				break;
			}
			
		}
		m_ChartCtrl_Curve1.EnableRefresh(false);
		CChartLineSerie *pLineSerie;
		m_ChartCtrl_Curve1.RemoveAllSeries();//�����  
		pLineSerie = m_ChartCtrl_Curve1.CreateLineSerie();
		pLineSerie->AddPoints(x, y, 30);
		pLineSerie->SetWidth(3);
		GetDlgItem(IDC_VALUE)->ShowWindow(SW_SHOW);
		CString text;
		text.Format(_T("%lf"), y[m_cur_index]);
		curve_value.SetWindowTextA(text);

		//DrawOverSpeed();
		m_ChartCtrl_Curve1.EnableRefresh(true);
		break;
	}
	case TIMER_RADAR:
		DrawRadarData();
		DrawMap();
		m_index_radar++;
		if (m_index_radar > m_locOnmap.size())
			m_index_radar = 0;
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CMFCVideoDlg::StopTimer()
{
	KillTimer(TIMER_VIDEO_1);
	KillTimer(TIMER_VIDEO_2);
	KillTimer(TIMER_VIDEO_3);
	KillTimer(TIMER_VIDEO_4);
	KillTimer(TIMER_PROGRESS);
	KillTimer(TIMER_CURVE);
	KillTimer(TIMER_RADAR);
}

void CMFCVideoDlg::StartTimer()
{
	UINT eslapse;
	if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
		eslapse = 20;
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
		eslapse = 15;
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
		eslapse = 8;
	}
	else if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
		eslapse = 5;
	}
	SetTimer(TIMER_VIDEO_1, eslapse, NULL);
	SetTimer(TIMER_VIDEO_2, eslapse, NULL);
	SetTimer(TIMER_VIDEO_3, eslapse, NULL);
	SetTimer(TIMER_VIDEO_4, eslapse, NULL);

	SetTimer(TIMER_PROGRESS, 200, NULL);
	SetTimer(TIMER_CURVE, 50, NULL);
	SetTimer(TIMER_RADAR, 100, NULL);
}

void CMFCVideoDlg::OnClose()   // �����˳�
{
	//MessageBox("close");
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_pVideoInfo1->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo1->m_pCapture);
		m_pVideoInfo1->m_pCapture = NULL;
	}
	if (m_pVideoInfo1->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo1->m_pFrameImage);
		m_pVideoInfo1->m_pFrameImage = NULL;
	}
	if (m_pVideoInfo2->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo2->m_pCapture);
		m_pVideoInfo2->m_pCapture = NULL;
	}
	if (m_pVideoInfo2->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo2->m_pFrameImage);
		m_pVideoInfo2->m_pFrameImage = NULL;
	}
	if (m_pVideoInfo3->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo3->m_pCapture);
		m_pVideoInfo3->m_pCapture = NULL;
	}
	if (m_pVideoInfo3->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo3->m_pFrameImage);
		m_pVideoInfo3->m_pFrameImage = NULL;
	}if (m_pVideoInfo4->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo4->m_pCapture);
		m_pVideoInfo4->m_pCapture = NULL;
	}
	if (m_pVideoInfo4->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo4->m_pFrameImage);
		m_pVideoInfo4->m_pFrameImage = NULL;
	}
	Excel_Guandao.Close();
	Excel_Radar.Close();
	release_mem();
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
	saveData();
	CDialogEx::OnClose();
}

void CMFCVideoDlg::OnBnClickedVideoClose()   // ������Ƶ����
{
	// MessageBox("video close");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pVideoInfo1->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo1->m_pCapture);
		m_pVideoInfo1->m_pCapture = NULL;
	}
	if (m_pVideoInfo1->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo1->m_pFrameImage);
		m_pVideoInfo1->m_pFrameImage = NULL;
	}if (m_pVideoInfo2->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo2->m_pCapture);
		m_pVideoInfo2->m_pCapture = NULL;
	}
	if (m_pVideoInfo2->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo2->m_pFrameImage);
		m_pVideoInfo2->m_pFrameImage = NULL;
	}
	if (m_pVideoInfo3->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo3->m_pCapture);
		m_pVideoInfo3->m_pCapture = NULL;
	}
	if (m_pVideoInfo3->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo3->m_pFrameImage);
		m_pVideoInfo3->m_pFrameImage = NULL;
	}if (m_pVideoInfo4->m_pCapture)  //�ͷ�
	{
		cvReleaseCapture(&m_pVideoInfo4->m_pCapture);
		m_pVideoInfo4->m_pCapture = NULL;
	}
	if (m_pVideoInfo4->m_pFrameImage)
	{
		cvReleaseImage(&m_pVideoInfo4->m_pFrameImage);
		m_pVideoInfo4->m_pFrameImage = NULL;
	}
	Excel_Guandao.Close();
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
}

void CMFCVideoDlg::OnBnClickedVideoPlay()   //button ������Ƶ
{
	int index;
	index = m_ListControl.GetSelectionMark();
	if (index == -1)
		return;
	m_resDir = m_ListControl.GetItemText(index, 3);
	if (m_resDir == "")
		return;
	CString tmpDir = "";
	name_GuanDao = _T(GUANDAO);
	name_Radar = _T(RADAR);
	//  �����������Ƶ���β��ţ�����ȡ���е�ͷ
	tmpDir = m_resDir + _T("\\") + _T(VIDEODIR_ONE);
	//MessageBox(tmpDir);
	GetPathFile(tmpDir, path_video1);
	if (!path_video1.empty())
	{
		ChangeVideo(tmpDir, path_video1[video_index_1], m_pVideoInfo1);
		video_index_1++;
	}

	tmpDir = m_resDir + _T("\\") + _T(VIDEODIR_TWO);
	GetPathFile(tmpDir, path_video2);
	if (!path_video2.empty())
	{
		ChangeVideo(tmpDir, path_video2[video_index_2], m_pVideoInfo2);
		video_index_2++;
	}

	tmpDir = m_resDir + _T("\\") + _T(VIDEODIR_THREE);
	GetPathFile(tmpDir, path_video3);
	if (!path_video3.empty())
	{
		ChangeVideo(tmpDir, path_video3[video_index_3], m_pVideoInfo3);
		video_index_3++;
	}

	tmpDir = m_resDir + _T("\\") + _T(VIDEODIR_FOUR);
	GetPathFile(tmpDir, path_video4);
	if (!path_video4.empty())
	{
		ChangeVideo(tmpDir, path_video4[video_index_4], m_pVideoInfo4);
		video_index_4++;
	}

	CString path;
	path = m_resDir + _T("\\") + name_GuanDao;
	Excel_Guandao.OpenExcel(path);    // ����ʹ�õĵ���ģʽ��ֻ����һ������
	load_speed_data();

	path = m_resDir + _T("\\") + name_Radar;
	Excel_Radar.OpenExcel(path);
	load_radar_data();
}

void CMFCVideoDlg::ChangeVideo(CString dirName, CString sName, CvideoIf* cvinfo)
{
	// �����Ƶ·��
	CString videoName = dirName + _T("\\") + sName;
	cvinfo->m_pCapture = cvCreateFileCapture(videoName);//ȷ��Ҫ�����avi�ļ�
	if (cvinfo->m_pCapture)
	{
		//��ȡ֡��֡�߶�
		cvinfo->m_nFrameWidth = cvGetCaptureProperty(m_pVideoInfo1->m_pCapture, CV_CAP_PROP_FRAME_WIDTH);
		cvinfo->m_nFrameHeight = cvGetCaptureProperty(m_pVideoInfo1->m_pCapture, CV_CAP_PROP_FRAME_HEIGHT);
		cvinfo->m_pFrameImage = cvCreateImage(cvSize(m_pVideoInfo1->m_nFrameWidth, m_pVideoInfo1->m_nFrameHeight), 8, 3);
		cvZero(cvinfo->m_pFrameImage);
	}
}

void CMFCVideoDlg::OnBnClickedVideoStop()     //button ��ͣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int count = 0;
	if (!m_pVideoInfo1->m_pCapture)    // ��Ƶ������
	{
		return;
	}
	if (count % 2 == 1)
	{
		SetDlgItemTextA(IDC_VIDEO_STOP, ("����"));
		count = 0;
		KillTimer(TIMER_VIDEO_1);
		KillTimer(TIMER_VIDEO_2);
		KillTimer(TIMER_VIDEO_3);
		KillTimer(TIMER_VIDEO_4);
		KillTimer(TIMER_PROGRESS);
		KillTimer(TIMER_CURVE);
		KillTimer(TIMER_RADAR);
	}
	else {
		SetDlgItemTextA(IDC_VIDEO_STOP, ("��ͣ"));

		UINT eslapse;
		if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
			eslapse = 20;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
			eslapse = 15;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
			eslapse = 8;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {
			eslapse = 5;
		}
		SetTimer(TIMER_VIDEO_1, eslapse, NULL);
		SetTimer(TIMER_VIDEO_2, eslapse, NULL);
		SetTimer(TIMER_VIDEO_3, eslapse, NULL);
		SetTimer(TIMER_VIDEO_4, eslapse, NULL);

		// ���ƹߵ�����
		int type;
		if (((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->GetCheck()) {
			type = SPEED_X;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->GetCheck()) {
			type = SPEED_Y;
		}
		else {
			type = SPEED_Z;
		}
		DrawSpeed(type, true);
		// �����״�����
		DrawRadarPerpare();

		// ���ý�����
		int total = path_video1.size() + 1;
		mTotalTime = total * 60 * 1000;    // ÿ����Ƶ1min,�任Ϊ���뵥λ
		m_ProgressCtrl->SetRange(0, mTotalTime);
		m_ProgressCtrl->SetPos(0);
		SetTimer(TIMER_PROGRESS, 200, NULL);
		count = 1;
	}
}

void CMFCVideoDlg::OnBnClickedRadio1()   //���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
	KillTimer(TIMER_VIDEO_1);
	KillTimer(TIMER_VIDEO_2);
	KillTimer(TIMER_VIDEO_3);
	KillTimer(TIMER_VIDEO_4);
	SetTimer(TIMER_VIDEO_1, 20, NULL);
	SetTimer(TIMER_VIDEO_2, 20, NULL);
	SetTimer(TIMER_VIDEO_3, 20, NULL);
	SetTimer(TIMER_VIDEO_4, 20, NULL);
}

void CMFCVideoDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
	KillTimer(TIMER_VIDEO_1);
	KillTimer(TIMER_VIDEO_2);
	KillTimer(TIMER_VIDEO_3);
	KillTimer(TIMER_VIDEO_4);
	SetTimer(TIMER_VIDEO_1, 15, NULL);
	SetTimer(TIMER_VIDEO_2, 15, NULL);
	SetTimer(TIMER_VIDEO_3, 15, NULL);
	SetTimer(TIMER_VIDEO_4, 15, NULL);
}

void CMFCVideoDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
	KillTimer(TIMER_VIDEO_1);
	KillTimer(TIMER_VIDEO_2);
	KillTimer(TIMER_VIDEO_3);
	KillTimer(TIMER_VIDEO_4);
	SetTimer(TIMER_VIDEO_1, 8, NULL);
	SetTimer(TIMER_VIDEO_2, 8, NULL);
	SetTimer(TIMER_VIDEO_3, 8, NULL);
	SetTimer(TIMER_VIDEO_4, 8, NULL);
}

void CMFCVideoDlg::OnBnClickedRadio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
	KillTimer(TIMER_VIDEO_1);
	KillTimer(TIMER_VIDEO_2);
	KillTimer(TIMER_VIDEO_3);
	KillTimer(TIMER_VIDEO_4);
	SetTimer(TIMER_VIDEO_1, 5, NULL);
	SetTimer(TIMER_VIDEO_2, 5, NULL);
	SetTimer(TIMER_VIDEO_3, 5, NULL);
	SetTimer(TIMER_VIDEO_4, 5, NULL);
}

void CMFCVideoDlg::OnDblclkNi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	NM_LISTVIEW *pNMListView = (NM_LISTVIEW *)pNMHDR;
	CRect rc;
	m_Row = pNMListView->iItem;    // ��ѡ���е������
	m_Col = pNMListView->iSubItem;  // ��ѡ���е������

	//CString strMsg;
	//strMsg.Format("Value:%d, %d", m_Row, m_Col);
	//MessageBox(strMsg);
	if (m_Col == 1 && pNMListView->iItem >= 0)
	{
		m_ListControl.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc);
		m_Edit.SetParent(&m_ListControl);    // ת������Ϊ�б���е�����
		m_Edit.MoveWindow(rc);    // �ƶ�Edit��RECT��������λ��
		m_Edit.SetWindowTextA(m_ListControl.GetItemText(m_Row, m_Col));    // ���������е�ֵ����Edit�ؼ���
		m_Edit.ShowWindow(SW_SHOW);    // ��ʾEdit�ؼ�
		m_Edit.SetFocus();    // ����Edit����
		m_Edit.ShowCaret();   // ��ʾ���
		m_Edit.SetSel(-1);    // ������ƶ������
	}
	*pResult = 0;
}

void CMFCVideoDlg::OnEnKillfocusEdititem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString editContent;
	m_Edit.GetWindowTextA(editContent);
	m_ListControl.SetItemText(m_Row, m_Col, editContent);
	m_Edit.ShowWindow(SW_HIDE);
}

void CMFCVideoDlg::OnBnClickedInsert()
{
	//// TODO: �ڴ���ӿؼ�֪ͨ����������
	COpitionDialog dlg;
	CString name;
	CString path;
	CString driver;
	CString id;

	if (dlg.DoModal() == IDOK)
	{
		name = dlg.m_Name1;
		path = dlg.m_Path1;
		driver = dlg.m_Driver1;
		m_Row = m_ListControl.GetItemCount();
		id.Format(_T("%d"), m_Row);
		m_ListControl.InsertItem(m_Row, id);
		m_ListControl.SetItemText(m_Row, 1, name);
		m_ListControl.SetItemText(m_Row, 2, driver);
		m_ListControl.SetItemText(m_Row, 3, path);
	}
}

void CMFCVideoDlg::OnBnClickedDeleteSource()
{
	int index;
	index = m_ListControl.GetSelectionMark();
	m_ListControl.DeleteItem(index);
}

void CMFCVideoDlg::GetPathFile(CString path, vector<CString> &all_file)
{
	CFileFind finder;
	CString sName = "";
	BOOL find_one = finder.FindFile(path + _T("\\*.mp4"));
	//MessageBox((path + _T("\\*.mp4")));
	while (find_one)
	{
		find_one = finder.FindNextFileA();
		sName = finder.GetFileName();
		//MessageBox(sName);
		all_file.push_back(sName);
	}
}

BOOL CMFCVideoDlg::IsVideoFile(CString name)
{
	MessageBox(name);
	if (strcmp(name, "mp4") == 0 || strcmp(name, "avi"))
		return TRUE;
	return FALSE;
}

void CMFCVideoDlg::saveData()
{
	CString fileStr = "";
	CString tmpStr;
	tmpStr.Format("%s", m_saveDataPath);
	CStdioFile file;
	fileStr = tmpStr + "\\itemfile.txt";
	file.Open(fileStr, CFile::modeCreate | CFile::modeWrite);
	file.SeekToBegin();
	for (int i = 0; i < m_ListControl.GetItemCount(); i++)
	{
		tmpStr = m_ListControl.GetItemText(i, 1) + _T("|") + m_ListControl.GetItemText(i, 2) + _T("|") + m_ListControl.GetItemText(i, 3) + "\n";
		/*
		NOTE:
		��ʾ���� Linux: \r\n, Windows: \n, Max OS: \r
		*/
		file.Seek(0, CFile::end);
		file.WriteString(tmpStr);
	}
	file.Close();
}

void CMFCVideoDlg::loadData()
{
	CString fileStr = "";
	CString tmpStr;
	tmpStr.Format("%s", m_saveDataPath);
	CStdioFile file;
	fileStr = tmpStr + "\\itemfile.txt";
	file.Open(fileStr, CFile::modeRead);

	CString name;
	CString path;
	CString driver;
	CString id;
	while(file.ReadString(tmpStr))
	{
		AfxExtractSubString(name, tmpStr, 0, '|');
		AfxExtractSubString(driver, tmpStr, 1, '|');
		AfxExtractSubString(path, tmpStr, 2, '|');

		m_Row = m_ListControl.GetItemCount();
		id.Format(_T("%d"), m_Row);
		m_ListControl.InsertItem(m_Row, id);
		m_ListControl.SetItemText(m_Row, 1, name);
		m_ListControl.SetItemText(m_Row, 2, driver);
		m_ListControl.SetItemText(m_Row, 3, path);
		//MessageBox(path + "\\data.txt");
	}
	file.Close();
}

void CMFCVideoDlg::OnNMHoverNi(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	MessageBox("hello");
}

// ��������
void CMFCVideoDlg::load_speed_data()
{
	speed_X.clear();
	speed_Y.clear();
	speed_Z.clear();
	CString text;
	int row;
	int i;
	row = Excel_Guandao.GetRowCount();
	for (i = 2; i <= row; i++)
	{
		text = Excel_Guandao.GetText(i, 2);    // Excel�±��1��ʼ
		speed_X.push_back(atof(text));    // CString to double

		text = Excel_Guandao.GetText(i, 3);
		speed_Y.push_back(atof(text));

		text = Excel_Guandao.GetText(i, 4);
		speed_Z.push_back(atof(text));
	}
	//m_index_speed = 0;
}

void CMFCVideoDlg::load_radar_data()
{
	CString text;
	int row;
	int i, j;
	row = Excel_Radar.GetRowCount();
	for (i = 2; i <= row; i += OBSTACLE_SIZE)
	{
		struct Loc loc;
		text = Excel_Radar.GetText(i, 5);
		loc.latitude = atof(text);
		text = Excel_Radar.GetText(i, 6);
		loc.longitude = atof(text);
		text = Excel_Radar.GetText(i, 7);
		loc.speed = atof(text);
		m_locOnmap.push_back(loc);
		struct Pos pos;
		for (j = i; j < i + OBSTACLE_SIZE; j++)
		{
			text = Excel_Radar.GetText(j, 3);
			pos.y[j - i] = atof(text);
			text = Excel_Radar.GetText(j, 4);
			pos.x[j - i] = atof(text);
		}
		m_obstacle.push_back(pos);
	}
}

void CMFCVideoDlg::DrawSpeed(int type, bool firsttime)
{
	double x[30], y[30];
	int row = speed_X.size();
	if (firsttime)
	{
		for (int i = 0; i < 30; i++)
		{
			x[i] = i;
			y[i] = 0;
		}
		/*
		for (int i = 15; i < 30; i++)
		{
			x[i] = i;
			switch (type)
			{
			case SPEED_X:
				y[i] = speed_X[(m_index_speed + i) % row];    // ÿ����ʾ30����
				break;
			case SPEED_Y:
				y[i] = speed_Y[(m_index_speed + i) % row];
				break;
			default:
				y[i] = speed_Z[(m_index_speed + i) % row];
				break;
			}
		}
		*/
	}
	else
	{
		for (int i = 0; i < 30; i++)
		{
			x[i] = i;
			switch (type)
			{
			case SPEED_X:
				y[i] = speed_X[(m_index_speed + i) % row];    // ÿ����ʾ30����
				break;
			case SPEED_Y:
				y[i] = speed_Y[(m_index_speed + i) % row];
				break;
			default:
				y[i] = speed_Z[(m_index_speed + i) % row];
				break;
			}
			if (m_index_speed + i < 0)
				y[i] = 0;
		}
	}
	
	m_ChartCtrl_Curve1.EnableRefresh(false);
	CChartLineSerie *pLineSerie;
	m_ChartCtrl_Curve1.RemoveAllSeries();//�����
	pLineSerie = m_ChartCtrl_Curve1.CreateLineSerie();
	pLineSerie->SetSeriesOrdering(poNoOrdering);
	pLineSerie->AddPoints(x, y, 30);
	pLineSerie->SetWidth(3);
	pLineSerie->SetColor(RGB(0, 0, 255));
	m_cur_index = 29;    // current
	GetDlgItem(IDC_VALUE)->ShowWindow(SW_SHOW);
	CString text;
	text.Format(_T("%lf"), y[m_cur_index]);
	curve_value.SetWindowTextA(text);
	m_ChartCtrl_Curve1.EnableRefresh(true);
	m_ChartCtrl_Curve1.cur_Enable = true;
	SetTimer(TIMER_CURVE, 50, NULL);
}

void CMFCVideoDlg::DrawOverSpeed()
{
	vector<double> v1;
	vector<double> v2;
	map<int, int>::iterator iter;
	for (iter = over_speed.begin(); iter != over_speed.end(); iter++)
	{
		if (iter->first < m_index_speed + m_cur_index && iter->first >= m_index_speed)
		{
			v1.push_back(iter->first);
			v2.push_back(iter->second);
		}
	}
	double *x = NULL;
	double *y = NULL;
	x = new double[v1.size()];
	y = new double[v2.size()];
	for (int i = 0; i < v1.size(); i++)
	{
		x[i] = v1[i];
	}
	//m_ChartCtrl_Curve1.EnableRefresh(false);
	CChartPointsSerie *pointSerie;
	pointSerie = m_ChartCtrl_Curve1.CreatePointsSerie();
	pointSerie->AddPoints(x, y, v1.size());
	pointSerie->SetPointType(CChartPointsSerie::PointType(CChartPointsSerie::ptTriangle));
	pointSerie->SetPointSize(10, 10);
	pointSerie->SetColor(RGB(0, 255, 0));
	//m_ChartCtrl_Curve1.EnableRefresh(true);
}

void CMFCVideoDlg::DrawCurrLabel()
{
	CWnd *pWnd = GetDlgItem(IDC_CURVE_1);
	CDC *pDC = pWnd->GetDC();
	CPen pen(PS_SOLID, 2, RGB(0, 255, 0));
	CPen *pOldpen = pDC->SelectObject(&pen);

	CRect rect;
	GetDlgItem(IDC_CURVE_1)->GetClientRect(&rect);
	int height = rect.Height();
	int weight = rect.Width();

	CString text;
	text.Format(_T("%d"), height);
	//MessageBox(text);
	CChartLineSerie *pLineSerie;
	pLineSerie = m_ChartCtrl_Curve1.CreateLineSerie();
	pLineSerie->SetWidth(3);

	CPoint ScreenPoint;
	pLineSerie->ValueToScreen(m_cur_index, 0.0, ScreenPoint);
	pDC->MoveTo(ScreenPoint.x, 0);
	pDC->LineTo(ScreenPoint.x, height);
	text.Format(_T("%lf"), ScreenPoint.x);
	//MessageBox(text);
	pWnd->ReleaseDC(pDC);
}

void CMFCVideoDlg::DrawRadarData()
{
	// ������
	CWnd *pwnd = GetDlgItem(IDC_OBSTACLE_PANEL);     //��ȡ���ھ��
	CDC *pdc = pwnd->GetDC();
	CRect rect;
	pwnd->Invalidate();
	pwnd->UpdateWindow();
	m_Obstacle_Panel.GetClientRect(&rect);
	pdc->Rectangle(0, 0, rect.right, rect.bottom);
	int width = rect.Width();
	int height = rect.Height();
	CPen ppenRed(PS_SOLID, 2, RGB(255, 0, 0));
	CGdiObject *pOldpen = pdc->SelectObject(&ppenRed);
	CBrush brush;
	brush.CreateSolidBrush(RGB(0, 0, 255));    // ��ɫ��ˢ
	pdc->SelectObject(brush);
	static bool flag = true;
	if (flag)
	{
		pdc->Rectangle(width / 2 - 10, height - 20, width / 2 + 10, height);
		flag = false;
	}
	else {
		pdc->Rectangle(width / 2 - 10, height - 15, width / 2 + 10, height);
		flag = true;
	}

	// �����ϰ���
	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255, 255, 0));    // ��ɫ��ˢ
	pdc->SelectObject(brush);
	struct Pos pos = m_obstacle[m_index_radar];
	int x, y;
	int weight_x = 50;
	int weight_y = 20;
	for (int i = 0; i < OBSTACLE_SIZE; i++)
	{
		//x = static_cast<int> (pos.x[i] * (width / 20.0));
		//y = static_cast<int> (pos.y[i] * (height / 15.0));
		x = pos.x[i] * weight_x + width / 2;
		y = height - pos.y[i] * weight_y;
		if (x - 3 > width || x - 3 < 0 || y - 3 < 0)
			continue;
		pdc->Rectangle(x - 3, y - 3, x + 3, y + 3);
	}
	brush.DeleteObject();
	pwnd->ReleaseDC(pdc);
}

void CMFCVideoDlg::DrawMeter(double speed)
{
	COLORREF m_colorNeedle;
	m_colorNeedle = RGB(255, 255, 235);//etSysColor(COLOR_ACTIVEBORDER);
	m_Meter_Panel.SetNeedleColor(m_colorNeedle);   //����ָ����ɫ
	m_Meter_Panel.SetColorTick(TRUE);
	m_Meter_Panel.UpdateNeedle(speed);
}

void CMFCVideoDlg::DrawMap()
{
	//LoadMap();
	//ShowMap();
	struct Loc loc = m_locOnmap[m_index_radar];
	DrawMeter(loc.speed);
	CWnd *pwnd = GetDlgItem(IDC_ROAD_MAP);
	CDC *pdc = pwnd->GetDC();
	CRect rect;
	m_Map.GetClientRect(&rect);
	//pdc->Rectangle(0, 0, rect.right, rect.bottom);
	CPen *ppenRed = new CPen;
	ppenRed->CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	CGdiObject *pOldpen = pdc->SelectObject(ppenRed);
	CBrush brush(RGB(0, 0, 255));
	int width = rect.Width();
	int height = rect.Height();
	int x, y;
	x = (loc.latitude - MAP_LAT) * 5;
	y = (loc.longitude - MAP_LONG) * 5;
	//x = static_cast<int> (loc.latitude * width / 100);
	//y = static_cast<int> (loc.longitude * height / 100);
	pdc->Ellipse(x - 3, y - 3, x + 3, y + 3);
	pwnd->ReleaseDC(pdc);
}

void CMFCVideoDlg::OnBnClickedRadioSpeedX()
{
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Z))->SetCheck(FALSE);
	KillTimer(TIMER_CURVE);
	DrawSpeed(SPEED_X, false);
}


void CMFCVideoDlg::OnBnClickedRadioSpeedY()
{
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Z))->SetCheck(FALSE);
	KillTimer(TIMER_CURVE);
	DrawSpeed(SPEED_Y, false);
}


void CMFCVideoDlg::OnBnClickedRadioSpeedZ()
{
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO_SPEED_Z))->SetCheck(TRUE);
	KillTimer(TIMER_CURVE);
	DrawSpeed(SPEED_Z, false);
}

void CMFCVideoDlg::LoadMap()
{
	// ���ص�ͼ
	ATL::CImage image;
	//image.Load("D:\\Workstation\\Works\\data\\map.png");
	image.Load("res\\map.png");
	CRect rectCtrl;
	CWnd *pWnd = GetDlgItem(IDC_ROAD_MAP);
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	pWnd->GetClientRect(&rectCtrl);
	CDC *pDc = pWnd->GetDC();
	//pDc->Rectangle(0, 0, rectCtrl.right, rectCtrl.bottom);
	SetStretchBltMode(pDc->m_hAttribDC, STRETCH_HALFTONE);
	((CStatic*)GetDlgItem(IDC_ROAD_MAP))->SetBitmap(NULL);
	//CRect rect(0, 0, 1000, 1000);
	image.Draw(pDc->m_hDC, rectCtrl);
	image.Destroy();
	pWnd->ReleaseDC(pDc);
}

void CMFCVideoDlg::ShowMap()
{
	ATL::CImage image;
	//image.Load("D:\\Workstation\\Works\\data\\map.png");
	image.Load("res\\map.png");
	CRect rectCtrl;
	CWnd *pWnd = GetDlgItem(IDC_ROAD_MAP);
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	pWnd->GetClientRect(&rectCtrl);
	CDC *pDc = pWnd->GetDC();
	pDc->Rectangle(0, 0, rectCtrl.right, rectCtrl.bottom);
	SetStretchBltMode(pDc->m_hAttribDC, STRETCH_HALFTONE);
	((CStatic*)GetDlgItem(IDC_ROAD_MAP))->SetBitmap(NULL);

	CDC dcMemory;
	if (!dcMemory.CreateCompatibleDC(pDc))
		return;
	CPoint point;
	point.x = rectCtrl.bottom;
	point.y = rectCtrl.right;
	image.BitBlt(dcMemory, point);
}

void CMFCVideoDlg::DrawRadarPerpare()
{
	LoadMap();
	//ShowMap();
	DrawCar();
	SetTimer(TIMER_RADAR, 100, NULL);
}

void CMFCVideoDlg::DrawCar()
{
	CWnd *pwnd = GetDlgItem(IDC_OBSTACLE_PANEL);     //��ȡ���ھ��
	CDC *pdc = pwnd->GetDC();
	CRect rect;
	pwnd->Invalidate();
	pwnd->UpdateWindow();
	m_Obstacle_Panel.GetClientRect(&rect);
	pdc->Rectangle(0, 0, rect.right, rect.bottom);
	int width = rect.Width();
	int height = rect.Height();
	CPen ppenRed(PS_SOLID, 2, RGB(255, 0, 0));
	CGdiObject *pOldpen = pdc->SelectObject(&ppenRed);
	CBrush brush(RGB(0, 0, 255));
	pdc->SelectObject(brush);
	static bool flag = true;
	if (flag)
	{
		pdc->Rectangle(width / 2 - 10, height - 20, width / 2 + 10, height);
		flag = false;
	}
	else {
		pdc->Rectangle(width / 2 - 10, height - 15, width / 2 + 10, height);
		flag = true;
	}
	pwnd->ReleaseDC(pdc);
}

void CMFCVideoDlg::OnBnClickedDispalyValue()
{
	CValueDisplayDlg valuedisplayDlg;
	StopTimer();
	valuedisplayDlg.speed_x.Format("%lf", speed_X[m_index_speed]);
	valuedisplayDlg.speed_y.Format("%lf", speed_Y[m_index_speed]);
	valuedisplayDlg.speed_z.Format("%lf", speed_Z[m_index_speed]);
	valuedisplayDlg.DoModal();
	StartTimer();
}


void CMFCVideoDlg::OnBnClickedSetAlert()
{
	StopTimer();
	setAlertEnable = true;
	//StartTimer();
}


void CMFCVideoDlg::OnBnClickedAlertDetail()
{
	CAlertDisplayDlg alertDlg;
	StopTimer();
	alertDlg.DoModal();
	StartTimer();
}


void CMFCVideoDlg::OnStnDblclickValue()
{
	if (setAlertEnable)
	{
		CChooseAlertLevel chooseAlertDlg;
		
		if (chooseAlertDlg.DoModal() == IDCANCEL)
		{
			setAlertEnable = false;
			return;
		}
		int level = chooseAlertDlg.GetAlertLevel();
		double x[1];
		double y[1];
		int index = 0;
		index = m_cur_index + m_index_speed;
		if (((CButton *)GetDlgItem(IDC_RADIO_SPEED_X))->GetCheck()) {
			x[0] = 15;
			y[0] = speed_X[index % speed_X.size()];
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO_SPEED_Y))->GetCheck()) {
			x[0] = m_cur_index;
			y[0] = speed_Y[index % speed_X.size()];
		}
		else {
			x[0] = m_cur_index;
			y[0] = speed_Z[index % speed_X.size()];
		}

		m_ChartCtrl_Curve1.EnableRefresh(false);
		CChartPointsSerie *pointSerie;
		pointSerie = m_ChartCtrl_Curve1.CreatePointsSerie();
		pointSerie->AddPoints(x, y, 1);
		pointSerie->SetPointType(CChartPointsSerie::PointType(CChartPointsSerie::ptTriangle));
		pointSerie->SetPointSize(10, 10);
		pointSerie->SetColor(RGB(0, 255, 0));
		m_ChartCtrl_Curve1.EnableRefresh(true);
		setAlertEnable = false;
		over_speed.insert(pair<int, int>(index, level));
		//StartTimer();
	}
}
