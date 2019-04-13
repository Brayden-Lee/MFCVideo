// OpitionDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCVideo.h"
#include "OpitionDialog.h"
#include "afxdialogex.h"


// COpitionDialog �Ի���

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


// COpitionDialog ��Ϣ�������


void COpitionDialog::OnBnClickedChoose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bi;	                   //BROWSEINFO�ṹ�кܶ��Ա���������Լ�����
	ZeroMemory(&bi, sizeof(BROWSEINFO));     //����&biΪ��ʼ��ַ����СΪsizeof(BROWSEINFO)���ڴ�������0���
											 //bi.ulFlags=BIF_BROWSEINCLUDEFILES;        //���õ����ĶԻ������ԡ��˴���˼Ϊ�����ļ�������������ֵ��Ĭ�ϵ���ֻ���ļ��С�ulFlags�����Զ���ܶ�������
											 //bi.ulFlags=BIF_NEWDIALOGSTYLE;            //���ڿ��Ե�����С�����½��ļ��а�ť
											 //bi.lpszTitle=L"ָ��Ҫ������ļ���";       //�ڴ�������ʾ��ʾ�û������
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   //Displays a dialog box enabling the user to select a Shell folder.
	TCHAR * path = new TCHAR[MAX_PATH];
	if (pidl != NULL)
	{
		SHGetPathFromIDList(pidl, path);      //Converts an item identifier list to a file system path
		ceditt.SetWindowText(path);
		//MessageBox(path);
	}
}
