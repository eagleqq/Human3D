#include "sensorloader.h"
#include <QDebug>
#include <QThread>

SensorLoader::SensorLoader()
{

}

void SensorLoader::stopWork()
{
    isWork = false;
    qDebug() << "stop";
}

void SensorLoader::parser(const QString &path)
{
    isWork = true;
    qDebug() << path;
    QFile file;
    file.setFileName(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!file.atEnd())
        {
//            qDebug() << "isWork" << isWork;
            if(!isWork)
            {
                break;
            }
            QThread::msleep(50);
            QString linedata = file.readLine();
            QStringList dataList = linedata.split(" ");
            QString s_name = dataList.value(0, "");
            QString s_xA = dataList.value(10, "0");
            QString s_yA = dataList.value(11, "0");
            QString s_zA = dataList.value(12, "0");
            T_SensorData sensordata;
            sensordata.partName = s_name;
            sensordata.xAngle = s_xA.toDouble();
            sensordata.yAngle = s_yA.toDouble();
            sensordata.zAngle = s_zA.toDouble();
            QVariant data;
            data.setValue(sensordata);
            emit resultReady(data);
        }
        file.close();
    }
}
