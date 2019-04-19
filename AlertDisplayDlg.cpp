// AlertDisplayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "AlertDisplayDlg.h"
#include "afxdialogex.h"
#include <map>
#include "MFCVideoDlg.h"

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

	// Get Data From Parent
	CString alert_tag[4];
	alert_tag[0] = "Slow";
	alert_tag[1] = "Normal";
	alert_tag[2] = "Overspeed";
	alert_tag[3] = "High Overspeed";
	CMFCVideoDlg* parentDlg = (CMFCVideoDlg *)GetParent();
	map<int, int>::iterator iter;
	CString id;
	CString time;
	CString level;
	int row = 0;
	for (iter = parentDlg->over_speed.begin(); iter != parentDlg->over_speed.end(); iter++)
	{
		time.Format("%d", iter->first);
		level = alert_tag[iter->second];

		id.Format(_T("%d"), row);
		m_Alert_List.InsertItem(row, id);
		m_Alert_List.SetItemText(row, 1, time);
		m_Alert_List.SetItemText(row, 2, level);
		row++;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CAlertDisplayDlg::OnBnClickedAlertlistRm()
{
	int index;
	index = m_Alert_List.GetSelectionMark();
	if (index == -1)
		return;
	CString delete_item;
	delete_item = m_Alert_List.GetItemText(index, 1);
	m_Alert_List.DeleteItem(index);
	CMFCVideoDlg* parentDlg = (CMFCVideoDlg *)GetParent();
	parentDlg->over_speed.erase(_ttoi(delete_item));
}
