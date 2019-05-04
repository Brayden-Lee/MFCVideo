
// MFCVideoDlg.h : 头文件
//
#include "Export2Excel.h"
#include "ChartCtrl_source\ChartCtrl.h"
#include "ChartCtrl_source\ChartTitle.h"
#include "ChartCtrl_source\ChartLineSerie.h"
#include "ChartCtrl_source\ChartPointsSerie.h"
#include "Meter.h"
#include "CvideoIf.h"
#include "CvvImage.h"
#include "constant.h"
#include "CWindowSizeManager.h"
#include "xSkinButton.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "opencv2/opencv.hpp"

using namespace std;
#pragma once

#if defined _UNICODE ||defined UNICODE  
	typedef std::wstring TChartString;
	typedef std::wstringstream TChartStringStream;
#else  
	typedef std::string TChartString;
	typedef std::stringstream TChartStringStream;
#endif 

// 自定义结构体
struct Pos {
	double x[OBSTACLE_SIZE];
	double y[OBSTACLE_SIZE];
};

struct Loc {
	double latitude;    // 维度
	double longitude;    // 经度
	double speed;
};

// CMFCVideoDlg 对话框
class CMFCVideoDlg : public CDialogEx
{
	DECLARE_EASYSIZE
	// 构造
public:
	CMFCVideoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	CStatic test_video_num;
	CStatic test_video_frames;
	int cur_frame_count;
	int all_played_frames;    // 放完的视频的帧累计
	CExport2Excel Excel_Guandao;
	CExport2Excel Excel_Radar;
	CString name_GuanDao;
	CString name_Radar;
	UINT mTotalTime;
	CString m_resDir;
	UINT video_index_1;    // 将要播放的视频序号
	vector<CString> path_video1;
	CvideoIf* m_pVideoInfo1;
	HDC m_pPicCtlHdc1;
	CRect m_PicCtlRect1;
	CvvImage m_CvvImage1;
	CStatic m_PicCtrl_Video1;
	vector<int> total_frames;

	UINT video_index_2;
	vector<CString> path_video2;
	CvideoIf* m_pVideoInfo2;
	HDC m_pPicCtlHdc2;
	CRect m_PicCtlRect2;
	CvvImage m_CvvImage2;
	CStatic m_PicCtrl_Video2;

	UINT video_index_3;
	vector<CString> path_video3;
	CvideoIf* m_pVideoInfo3;
	HDC m_pPicCtlHdc3;
	CRect m_PicCtlRect3;
	CvvImage m_CvvImage3;
	CStatic m_PicCtrl_Video3;

	UINT video_index_4;
	vector<CString> path_video4;
	CvideoIf* m_pVideoInfo4;
	HDC m_pPicCtlHdc4;
	CRect m_PicCtlRect4;
	CvvImage m_CvvImage4;
	CStatic m_PicCtrl_Video4;

	CChartCtrl m_ChartCtrl_Curve1;
	// 实现

	char m_saveDataPath[MAX_PATH];
	vector<double> speed_X;
	vector<double> speed_Y;
	vector<double> speed_Z;
	vector<struct Pos> m_obstacle;
	vector<struct Loc> m_locOnmap;
	COLORREF Alert_Color[COLOR_TYPE];
	int m_index_speed;
	int m_global_count;    // loop time of all
	int m_cur_index;
	int m_index_radar;
	HICON m_hIcon;

	int m_Row;
	int m_Col;

	// 坐标轴上下限
	double y_min;
	double y_max;

	// 加载数据进度条
	UINT progress_total;
	UINT progress_cur;
protected:
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CxSkinButton m_BtnInsert;
	CxSkinButton m_BtnDelete;
	CxSkinButton m_BtnLoaddata;
	CxSkinButton m_BtnBegin;
	CxSkinButton m_BtnEnd;
	CxSkinButton m_BtnShowCur;
	CxSkinButton m_BtnSetAlert;
	CxSkinButton m_BtnAlertInfo;

	CWindowSizeMange m_WinsizeManage;
	CRect m_rect;
	CRect limit_rect;
	map<int, int> over_speed;
	CListCtrl m_ListControl;
	CSliderCtrl *m_Slider_All;
	UINT slider_count;    // 当前进度，也反映视频播放当前帧
	CEdit m_Edit;
	CStatic m_Obstacle_Panel;
	CMeter	m_Meter_Panel;
	CStatic m_Map;
	CStatic curve_value;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedVideoClose();
	afx_msg void OnBnClickedVideoPlay();
	afx_msg void OnBnClickedVideoStop();
	afx_msg UINT getSpeedRadio();
	afx_msg int getSpeedType();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnDblclkNi(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedInsert();
	afx_msg void GetPathFile(CString path, vector< CString> &all_file);
	afx_msg void OnEnKillfocusEdititem();

	afx_msg BOOL IsVideoFile(CString sName);
	afx_msg void ChangeVideo(CString dirName, CString sName, CvideoIf* cvinfo);
	afx_msg void OnBnClickedDeleteSource();
	afx_msg BOOL IsFileExist(const CString& csFile);
	afx_msg void saveData();
	afx_msg void loadData();
	afx_msg void saveAlertTag();
	afx_msg void loadAlertTag();
	afx_msg void OnNMHoverNi(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void load_speed_data();    // Guandao data
	afx_msg void load_radar_data();    // Radar data
	afx_msg void display_loading_progress();
	afx_msg void DrawSpeed(int type, bool firsttime);
	afx_msg void DrawOverSpeed();
	afx_msg void DrawRadarData();
	afx_msg void DrawMeter(double speed);
	afx_msg void DrawMap();
	afx_msg void DrawCar();
	afx_msg void LoadMap();
	afx_msg void ShowMap();
	afx_msg void init();
	afx_msg void release_mem();
	afx_msg void OnBnClickedRadioSpeedX();
	afx_msg void OnBnClickedRadioSpeedY();
	afx_msg void OnBnClickedRadioSpeedZ();
	afx_msg void DrawRadarPerpare();
	afx_msg void OnBnClickedDispalyValue();
	afx_msg void StopTimer();
	afx_msg void StartTimer(UINT eslapse);
	afx_msg void OnBnClickedSetAlert();
	afx_msg void OnBnClickedAlertDetail();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void ChangeSize(CWnd* pWnd, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnNMCustomdrawNi(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg int get_video_index_after_slider(vector<int> &v, int pos);
};
#pragma once