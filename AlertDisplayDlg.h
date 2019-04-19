#pragma once

// CAlertDisplayDlg 对话框

class CAlertDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAlertDisplayDlg)

public:
	CAlertDisplayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAlertDisplayDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALERTDISPLAYDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_Alert_List;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAlertlistRm();
};
