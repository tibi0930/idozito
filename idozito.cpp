#include "idozito.h"

Idozito::Idozito(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Number display");
    setFixedSize(300,175);
    _timer = new QTimer();
    //_timer->setInterval(1000);
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    _timer->start(1000);
    time = 0;

    _lcdNumber = new QLCDNumber(4, this); // megadjuk a számjegyek számát is
    //_lcdNumber->display(0); // megjelenített érték (egyben eseménykezelő is)
    _lcdNumber->setGeometry(0, 0, 300, 175);
    _lcdNumber->setPalette(Qt::blue);



}

Idozito::~Idozito()
{
    delete _lcdNumber;
    delete _timer;
}


void Idozito::updateTime(){
    time++;
    time = time % 10;
    _lcdNumber->display(time);
}
