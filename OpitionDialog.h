#pragma once
#include "afxwin.h"


// COpitionDialog �Ի���

class COpitionDialog : public CDialogEx
{
	DECLARE_DYNAMIC(COpitionDialog)

public:
	COpitionDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COpitionDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPITIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChoose();

	CEdit ceditt;
	CEdit m_Name;
	CEdit m_Driver;
	CString m_Name1;
	CString m_Path1;
	CString m_Driver1;
};
