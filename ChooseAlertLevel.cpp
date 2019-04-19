// ChooseAlertLevel.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "ChooseAlertLevel.h"
#include "afxdialogex.h"


// CChooseAlertLevel 对话框

IMPLEMENT_DYNAMIC(CChooseAlertLevel, CDialogEx)

CChooseAlertLevel::CChooseAlertLevel(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHOOSEALERTLEVEL, pParent)
{
}

int CChooseAlertLevel::GetAlertLevel()
{
	return cur_index;
}

CChooseAlertLevel::~CChooseAlertLevel()
{
}

void CChooseAlertLevel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CChooseAlertLevel::OnInitDialog()
{
	m_AlertLevelList = (CComboBox*)GetDlgItem(IDC_ALERTLEVEL);
	int index = 0;
	m_AlertLevelList->InsertString(index++, "Slow");
	m_AlertLevelList->InsertString(index++, "Normal");
	m_AlertLevelList->InsertString(index++, "Overspeed");
	m_AlertLevelList->InsertString(index++, "High Overspeed");
	m_AlertLevelList->SetCurSel(0);
	cur_index = 0;
	return TRUE;
}


BEGIN_MESSAGE_MAP(CChooseAlertLevel, CDialogEx)
	ON_CBN_SELCHANGE(IDC_ALERTLEVEL, &CChooseAlertLevel::OnCbnSelchangeAlertlevel)
END_MESSAGE_MAP()


// CChooseAlertLevel 消息处理程序


void CChooseAlertLevel::OnCbnSelchangeAlertlevel()
{
	cur_index = m_AlertLevelList->GetCurSel();
}
