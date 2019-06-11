#ifndef DATA_H
#define DATA_H

#include "Backend_NumericsData.h"
#include <QObject>
#include <QThreadPool>

class Data : public QObject
{
    Q_OBJECT
       Q_PROPERTY(int cm2H READ cm2H WRITE setcm2H NOTIFY cm2HChanged)
    Q_PROPERTY(int mv READ mv WRITE setmv NOTIFY mvChanged)
    Q_PROPERTY(int o2 READ o2 WRITE seto2 NOTIFY o2Changed)
    public:
        explicit Data(QObject *parent = nullptr):QObject(parent){
            m_cm2H = 21;
            m_mv = 10;
            m_o2 =57;
            runnable = new BackendNumericsData(this);
        }
      ~Data(){
            runnable->stop();
        }
        Q_INVOKABLE void start(){
            if(!runnable->isRunning())
                QThreadPool::globalInstance()->start(runnable);
        }
        int cm2H() const {
            return m_cm2H;
        }
        int mv() const {
            return m_mv;
        }
        int o2() const {
            return m_o2;
        }
    public slots:
        void setcm2H(int cm2H){
            if(cm2H == m_cm2H){
                return;
            }
            m_cm2H = cm2H;
            emit cm2HChanged(m_cm2H);
        }
        void setmv(int mv){
            if(mv == m_mv)
                return;
            m_mv = mv;
            emit mvChanged(m_mv);
        }
        void seto2(int o2){
            if(o2 == m_o2)
                return;
            m_o2 = o2;
            emit o2Changed(m_o2);
        }
    signals:
        void cm2HChanged(int);
        void mvChanged(int);
        void o2Changed(int);
    private:
        int m_cm2H;
        int m_mv;
        int m_o2;
        BackendNumericsData *runnable;
};
#endif // DATA_H
