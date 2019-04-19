#pragma once
#include "afxwin.h"


// CChooseAlertLevel 对话框

class CChooseAlertLevel : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseAlertLevel)

public:
	CChooseAlertLevel(CWnd* pParent = NULL);   // 标准构造函数
	int GetAlertLevel();
	virtual ~CChooseAlertLevel();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOOSEALERTLEVEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	CComboBox *m_AlertLevelList;
	int cur_index;
public:
	afx_msg void OnCbnSelchangeAlertlevel();
};
