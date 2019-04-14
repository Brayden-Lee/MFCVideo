// AlertDisplayDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "AlertDisplayDlg.h"
#include "afxdialogex.h"


// CAlertDisplayDlg �Ի���

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


// CAlertDisplayDlg ��Ϣ�������


BOOL CAlertDisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_Alert_List.GetClientRect(&rect);
	int iLength = rect.Width();
	m_Alert_List.SetExtendedStyle(m_Alert_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_Alert_List.InsertColumn(0, _T("���"), LVCFMT_CENTER, 60);
	m_Alert_List.InsertColumn(1, _T("ʱ��"), LVCFMT_CENTER, 140);
	m_Alert_List.InsertColumn(2, _T("Σ�ռ���"), LVCFMT_CENTER, (iLength - 200));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CAlertDisplayDlg::OnBnClickedAlertlistRm()
{
	int index;
	index = m_Alert_List.GetSelectionMark();
	m_Alert_List.DeleteItem(index);
}
