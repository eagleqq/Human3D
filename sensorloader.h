#ifndef SENSORLOADER_H
#define SENSORLOADER_H

#include <QList>
#include <QVariant>

/*
WTarm1up是左上臂, WTarm2up是右上臂， WTleg1是左大腿, WTleg2是右大腿, WTarm2是腰
每行的最后九个数分别是加速度xyz轴，角速度xyz轴，角度xyz轴数据
*/

struct T_SensorData
{
  QString partName;
  double xAngle;
  double yAngle;
  double zAngle;
};
Q_DECLARE_METATYPE(T_SensorData)

class SensorLoader: public QObject
{
    Q_OBJECT

public:
    SensorLoader();

public slots:
    void stopWork();
    void parser(const QString &path);

signals:
    void resultReady(QVariant data);

private:
    bool isWork = true;
};

#endif // SENSORLOADER_H
