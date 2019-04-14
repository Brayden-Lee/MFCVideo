// ValueDisplayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "ValueDisplayDlg.h"
#include "afxdialogex.h"


// CValueDisplayDlg 对话框

IMPLEMENT_DYNAMIC(CValueDisplayDlg, CDialogEx)

CValueDisplayDlg::CValueDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VALUEDISPLAYDLG, pParent)
{
	speed_x.Format("%f", 0.0);
	speed_y.Format("%f", 0.0);
	speed_z.Format("%f", 0.0);
}

CValueDisplayDlg::~CValueDisplayDlg()
{
}

void CValueDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_SPEED_X, speed_x);
	DDX_Text(pDX, IDC_TEXT_SPEED_Y, speed_y);
	DDX_Text(pDX, IDC_TEXT_SPEED_Z, speed_z);
}


BEGIN_MESSAGE_MAP(CValueDisplayDlg, CDialogEx)
END_MESSAGE_MAP()


// CValueDisplayDlg 消息处理程序
