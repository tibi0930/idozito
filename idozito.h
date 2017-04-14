#ifndef IDOZITO_H
#define IDOZITO_H

#include <QWidget>
#include <QTimer>
#include <QLCDNumber>

class Idozito : public QWidget
{
    Q_OBJECT
private slots:
    void updateTime();
public:
    Idozito(QWidget *parent = 0);
    ~Idozito();
private:
    QTimer * _timer;
    QLCDNumber* _lcdMin;
    QLCDNumber* _lcdH;
    int time;
};

#endif // IDOZITO_H
