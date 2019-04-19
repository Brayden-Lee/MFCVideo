#pragma once
#include "afxwin.h"


// CChooseAlertLevel �Ի���

class CChooseAlertLevel : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseAlertLevel)

public:
	CChooseAlertLevel(CWnd* pParent = NULL);   // ��׼���캯��
	int GetAlertLevel();
	virtual ~CChooseAlertLevel();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOOSEALERTLEVEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	CComboBox *m_AlertLevelList;
	int cur_index;
public:
	afx_msg void OnCbnSelchangeAlertlevel();
};
