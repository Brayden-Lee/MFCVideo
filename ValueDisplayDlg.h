#pragma once


// CValueDisplayDlg �Ի���

class CValueDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CValueDisplayDlg)

public:
	CValueDisplayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CValueDisplayDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VALUEDISPLAYDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString speed_x;
	CString speed_y;
	CString speed_z;
};
