
// MFCVideo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <Windows.h>

// CMFCVideoApp: 
// �йش����ʵ�֣������ MFCVideo.cpp
//

class CMFCVideoApp : public CWinApp
{
public:
	CMFCVideoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CMFCVideoApp theApp;