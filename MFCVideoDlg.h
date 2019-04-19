
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
#include <vector>
#include <map>
#include <string>
#include <sstream>

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
	CExport2Excel Excel_Guandao;
	CExport2Excel Excel_Radar;
	CString name_GuanDao;
	CString name_Radar;
	UINT mTotalTime;
	CString m_resDir;
	UINT video_index_1;
	vector<CString> path_video1;
	CvideoIf* m_pVideoInfo1;
	HDC m_pPicCtlHdc1;
	CRect m_PicCtlRect1;
	CvvImage m_CvvImage1;

	UINT video_index_2;
	vector<CString> path_video2;
	CvideoIf* m_pVideoInfo2;
	HDC m_pPicCtlHdc2;
	CRect m_PicCtlRect2;
	CvvImage m_CvvImage2;

	UINT video_index_3;
	vector<CString> path_video3;
	CvideoIf* m_pVideoInfo3;
	HDC m_pPicCtlHdc3;
	CRect m_PicCtlRect3;
	CvvImage m_CvvImage3;

	UINT video_index_4;
	vector<CString> path_video4;
	CvideoIf* m_pVideoInfo4;
	HDC m_pPicCtlHdc4;
	CRect m_PicCtlRect4;
	CvvImage m_CvvImage4;

	CChartCtrl m_ChartCtrl_Curve1;
	// 实现
protected:
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

	bool setAlertEnable;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	map<int, int> over_speed;
	CListCtrl m_ListControl;
	CEdit m_Edit;
	CProgressCtrl *m_ProgressCtrl;
	CStatic m_Obstacle_Panel;
	CMeter	m_Meter_Panel;
	CStatic m_Map;
	CStatic curve_value;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedVideoClose();
	afx_msg void OnBnClickedVideoPlay();
	afx_msg void OnBnClickedVideoStop();
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
	afx_msg void DrawSpeed(int type, bool firsttime);
	afx_msg void DrawOverSpeed();
	afx_msg void DrawCurrLabel();
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
	afx_msg void StartTimer();
	afx_msg void OnBnClickedSetAlert();
	afx_msg void OnBnClickedAlertDetail();
	afx_msg void OnStnDblclickValue();
};
#pragma once