// AlertDisplayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "AlertDisplayDlg.h"
#include "afxdialogex.h"


// CAlertDisplayDlg 对话框

IMPLEMENT_DYNAMIC(CAlertDisplayDlg, CDialogEx)

CAlertDisplayDlg::CAlertDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ALERTDISPLAYDLG, pParent)
{
	
}

CAlertDisplayDlg::~CAlertDisplayDlg()
{
}

void CAlertDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ALERT_LIST, m_Alert_List);
}

BEGIN_MESSAGE_MAP(CAlertDisplayDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ALERTLIST_RM, &CAlertDisplayDlg::OnBnClickedAlertlistRm)
END_MESSAGE_MAP()


// CAlertDisplayDlg 消息处理程序


BOOL CAlertDisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_Alert_List.GetClientRect(&rect);
	int iLength = rect.Width();
	m_Alert_List.SetExtendedStyle(m_Alert_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_Alert_List.InsertColumn(0, _T("编号"), LVCFMT_CENTER, 60);
	m_Alert_List.InsertColumn(1, _T("时刻"), LVCFMT_CENTER, 140);
	m_Alert_List.InsertColumn(2, _T("危险级别"), LVCFMT_CENTER, (iLength - 200));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CAlertDisplayDlg::OnBnClickedAlertlistRm()
{
	int index;
	index = m_Alert_List.GetSelectionMark();
	m_Alert_List.DeleteItem(index);
}
