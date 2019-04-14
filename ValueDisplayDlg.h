#pragma once


// CValueDisplayDlg 对话框

class CValueDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CValueDisplayDlg)

public:
	CValueDisplayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CValueDisplayDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VALUEDISPLAYDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString speed_x;
	CString speed_y;
	CString speed_z;
};
