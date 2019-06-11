#ifndef BACKENDFUNCTION_H
#define BACKENDFUNCTION_H

#include <QObject>
#include <QRunnable>
#include <QThread>


class BackendNumericsData : public QRunnable
{
    int cm2HValue = 21;
    int mvValue =10;
    int o2Value =57;
    QObject *mReceiver;
    bool mRunning;
public:
    BackendNumericsData(QObject *receiver) {
        mReceiver = receiver;
        mRunning =false;
    }
    void run(){
        mRunning = true;
        while(mRunning){
            cm2HValue++;
            if (cm2HValue > 52)
                cm2HValue=8;
            mvValue++;
            if(mvValue > 15 )
                    mvValue=0;
            o2Value++;
            if(o2Value > 56)
                    o2Value=2;
            QMetaObject::invokeMethod(mReceiver, "setcm2H",
                                      Qt::QueuedConnection,
                                      Q_ARG(int, cm2HValue));
            QMetaObject::invokeMethod(mReceiver, "setmv",
                                      Qt::QueuedConnection,
                                      Q_ARG(int, mvValue));
            QMetaObject::invokeMethod(mReceiver, "seto2",
                                      Qt::QueuedConnection,
                                      Q_ARG(int, o2Value));
            QThread::msleep(1000);
        }
    }
    bool isRunning() const{
        return mRunning;
    }
    void stop(){
        mRunning = false;
    }
};

#endif // BACKENDFUNCTION_H
