// OpitionDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "OpitionDialog.h"
#include "afxdialogex.h"


// COpitionDialog 对话框

IMPLEMENT_DYNAMIC(COpitionDialog, CDialogEx)

COpitionDialog::COpitionDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OPITIONS, pParent)
	, m_Name1(_T(""))
	, m_Driver1(_T(""))
	, m_Path1(_T(""))
{

}

COpitionDialog::~COpitionDialog()
{
}

void COpitionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, ceditt);
	DDX_Control(pDX, IDC_EDIT1, m_Name);
	DDX_Control(pDX, IDC_EDIT3, m_Driver);
	DDX_Text(pDX, IDC_EDIT1, m_Name1);
	DDX_Text(pDX, IDC_EDIT2, m_Path1);
	DDX_Text(pDX, IDC_EDIT3, m_Driver1);
}


BEGIN_MESSAGE_MAP(COpitionDialog, CDialogEx)
	ON_BN_CLICKED(IDC_CHOOSE_PATH, &COpitionDialog::OnBnClickedChoose)
END_MESSAGE_MAP()


// COpitionDialog 消息处理程序


void COpitionDialog::OnBnClickedChoose()
{
	// TODO: 在此添加控件通知处理程序代码
	BROWSEINFO bi;	                   //BROWSEINFO结构有很多成员参数可以自己设置
	ZeroMemory(&bi, sizeof(BROWSEINFO));     //将以&bi为起始地址，大小为sizeof(BROWSEINFO)的内存区域用0填充
											 //bi.ulFlags=BIF_BROWSEINCLUDEFILES;        //设置弹出的对话框属性。此处意思为包含文件。如果不设这个值，默认的是只有文件夹。ulFlags还可以定义很多别的属性
											 //bi.ulFlags=BIF_NEWDIALOGSTYLE;            //窗口可以调整大小，有新建文件夹按钮
											 //bi.lpszTitle=L"指定要处理的文件夹";       //在窗口内显示提示用户的语句
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   //Displays a dialog box enabling the user to select a Shell folder.
	TCHAR * path = new TCHAR[MAX_PATH];
	if (pidl != NULL)
	{
		SHGetPathFromIDList(pidl, path);      //Converts an item identifier list to a file system path
		ceditt.SetWindowText(path);
		//MessageBox(path);
	}
}
