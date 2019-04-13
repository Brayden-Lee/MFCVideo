#pragma once
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
class CvideoIf
{
public:
	CvCapture* m_pCapture;  //用来保存图像的信息，处理视频时，让程序读下一帧位置
	IplImage* m_pFrameImage;   //存储数据图像 
	int m_nFrameWidth;
	int m_nFrameHeight;

	CvideoIf();
	~CvideoIf();
};

