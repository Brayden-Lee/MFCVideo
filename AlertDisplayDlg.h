#pragma once

// CAlertDisplayDlg �Ի���

class CAlertDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAlertDisplayDlg)

public:
	CAlertDisplayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAlertDisplayDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALERTDISPLAYDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_Alert_List;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAlertlistRm();
};
