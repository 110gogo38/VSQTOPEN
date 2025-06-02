#include "VSQTOPEN.h"
#include <opencv2/opencv.hpp> 
#include <QFileDialog>

VSQTOPEN::VSQTOPEN(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	/*m_imgSrc.load("E:\\QT6\\picture\\black.png");*/
	//cv::Mat image = cv::imread("E:\\QT6\\picture\\black.png"); // Load an image from file
	//cv::imshow("Image", image); // Display the image in a window
	//cv::waitKey(0);
	connect(&m_threadGetCamPic, &ThreadGetCamPic::sigSendCurImg, this, &VSQTOPEN::onFreshCurImg);
	connect(ui.btnOpen, &QPushButton::clicked, this, &VSQTOPEN::onOpenCam);
	//cv::VideoCapture stVideoCapture("E:\\QT6\\picture\\1.mp4");
	//cv::Mat matTemp;
	//while (true) 
	//{
	//	stVideoCapture >> matTemp; // Read a frame from the video
	//	if (matTemp.empty())
	//	{
	//		continue; // Exit the loop if no more frames are available
	//	}
	//	cv::imshow("Video Frame", matTemp); // Display the frame in a window
	//	cv::waitKey(30); // Wait for a key press before closing the window
	//}	
}

//void VSQTOPEN::resizeEvent(QResizeEvent *event)
//{
//	m_img2Show = m_imgSrc.scaled(ui.labelPic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//	m_pix2Show = QPixmap::fromImage(m_img2Show);
//	ui.labelPic->setPixmap(m_pix2Show);
//
//}

//void VSQTOPEN::showEvent(QShowEvent *event)
//{
//	m_img2Show = m_imgSrc.scaled(ui.labelPic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//	m_pix2Show = QPixmap::fromImage(m_img2Show);
//	ui.labelPic->setPixmap(m_pix2Show);
//}

void VSQTOPEN::on_btnOpen_clicked()
{
	// QString fileName = QFileDialog::getOpenFileName(this,
	// 	tr("Open Image"), "E:/QT6/picture", tr("Images (*.png *.xpm *.jpg *.mp4)"));
	// if(fileName.isEmpty()) {
	// 	return; // User cancelled the dialog
	// }
	// bool bRet=m_imgSrc.load(fileName);
	// cv::Mat matOpenImg = cv::imread(fileName.toLocal8Bit().data());
	// if (matOpenImg.empty()) 
	// {
	// 	return;
	// }
	
	// m_imgSrc = QImage(matOpenImg.data,matOpenImg.cols,matOpenImg.rows,matOpenImg.step,QImage::Format_BGR888).copy();
	// m_img2Show = m_imgSrc.scaled(ui.labelPic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	// m_pix2Show = QPixmap::fromImage(m_img2Show);
	// ui.labelPic->setPixmap(m_pix2Show);
}

void VSQTOPEN::onOpenCam() 
{
	m_threadGetCamPic.start(); // Start the thread to capture images from the camera
}


VSQTOPEN::~VSQTOPEN()
{}

void VSQTOPEN::onFreshCurImg(const QImage & img)
{
	m_imgSrc=img.copy();
	m_img2Show = m_imgSrc.scaled(ui.labelPic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	m_pix2Show = QPixmap::fromImage(m_img2Show);
	ui.labelPic->setPixmap(m_pix2Show);
}

