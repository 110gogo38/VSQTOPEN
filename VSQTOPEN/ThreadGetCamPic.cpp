#include "ThreadGetCamPic.h"
#include <opencv2/opencv.hpp> 
#include <qimage.h>

ThreadGetCamPic::ThreadGetCamPic(QObject *parent)
	: QThread(parent)
{
	m_stDlibEx.init();
}

ThreadGetCamPic::~ThreadGetCamPic()
{
	if (!this->isInterruptionRequested())
	{
		{
			QMutexLocker lock(&m_mux);
			m_bStop = true;
		}
		this->requestInterruption();
		this->wait();
	}

}

void ThreadGetCamPic::run()
{
	cv::VideoCapture stVideoCapture;
	bool bRet = stVideoCapture.open(0); // Open the default camera (index 0)
	cv::Mat matTemp;
	QImage imgTemp;
	m_bStop = false;
	while (!m_bStop) 
	{
		stVideoCapture >> matTemp; // Read a frame from the video
		if (matTemp.empty())
		{
			msleep(20);
			continue; // Exit the loop if no more frames are available
		}
		cv_image<bgr_pixel> cimg(matTemp);
		std::vector<rectangle> faces = m_stDlibEx.detectFaces(cimg);

		imgTemp= QImage(matTemp.data, matTemp.cols, matTemp.rows, matTemp.step, QImage::Format_BGR888).copy();
		emit sigSendCurImg(imgTemp, faces);
		msleep(20);
	}	
}
