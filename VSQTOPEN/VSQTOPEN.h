#pragma once

#include <QtWidgets/QWidget>
#include "ui_VSQTOPEN.h"
#include "ThreadGetCamPic.h"

class VSQTOPEN : public QWidget
{
    Q_OBJECT

public:
    VSQTOPEN(QWidget *parent = nullptr);

	//virtual void resizeEvent(QResizeEvent *event);
	//virtual void showEvent(QShowEvent *event);

    ~VSQTOPEN();

public slots:

    void onOpenCam();
    void on_btnOpen_clicked();
    void onFreshCurImg(const QImage &img);

private:
    Ui::VSQTOPENClass ui;

    QImage m_imgSrc;
    QImage m_img2Show;
	QPixmap m_pix2Show;

	ThreadGetCamPic m_threadGetCamPic;
};

