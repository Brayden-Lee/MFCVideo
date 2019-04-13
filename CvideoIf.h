#pragma once
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
class CvideoIf
{
public:
	CvCapture* m_pCapture;  //��������ͼ�����Ϣ��������Ƶʱ���ó������һ֡λ��
	IplImage* m_pFrameImage;   //�洢����ͼ�� 
	int m_nFrameWidth;
	int m_nFrameHeight;

	CvideoIf();
	~CvideoIf();
};

