#include "computethread.h"
#include "rawdatafromdb.h"

extern RawDataFromDB *raw_data;

ComputeThread::ComputeThread(QObject *parent) :
    QThread(parent)
{
}


void ComputeThread::run()
{
    qDebug()<<this->currentThreadId()<<":Begin computing!"<<endl;
//    int time = 10000;
//    float result=0;
//    for(int i=1;i<=time;i++)
//    {
//        double value=4.0/(2*i-1);
//        if (i % 2 == 1) result+=value;
//        else result-=value;
//    }
//    emit this->computeFinish(result);
    float result = 111;
    result = raw_data->GetDataModel()->record(1).value(3).toDouble();
    qDebug()<<result;
    int i = 0;
    emit this->computeFinish(result);
//    while (i++ < 10000000)
//        if (i == 10000000) {
//            emit this->computeFinish(result);
//            i = 0;
//            result++;
//        }
}

