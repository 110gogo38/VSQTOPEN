#pragma once
#include "E:\QT6_9\6.9.0\msvc2022_64\include\QtCore\qthread.h"
#include <qmutex.h>
class ThreadGetCamPic :
    public QThread
{
    Q_OBJECT

public:
    ThreadGetCamPic(QObject *parent = nullptr);
    ~ThreadGetCamPic();

	void run() override;

signals:
    void sigSendCurImg(const QImage &img);

private:
    bool m_bStop = true;
    QMutex m_mux;
};

