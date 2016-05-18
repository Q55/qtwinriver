#include "computethread.h"

ComputeThread::ComputeThread(QObject *parent) :
    QThread(parent)
{
}


void ComputeThread::run()
{
    qDebug()<<this->currentThreadId()<<":Begin computing!"<<endl;
//    int time = 1000000000;
//    float result=0;
//    for(int i=1;i<=time;i++)
//    {
//        double value=4.0/(2*i-1);
//        if (i % 2 == 1) result+=value;
//        else result-=value;
//    }
    float result = 0;
    int i = 0;
    while (i++ < 10000000)
        if (i == 10000000) {
            emit this->computeFinish(result);
            i = 0;
            result++;
        }
}

