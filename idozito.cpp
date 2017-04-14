#include "idozito.h"

Idozito::Idozito(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Number display");
    setFixedSize(280,175);
    _timer = new QTimer();
    //_timer->setInterval(1000);
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    _timer->start(1000);
    time = 0;

    _lcdH = new QLCDNumber(2, this);
    _lcdMin = new QLCDNumber(2, this); // megadjuk a számjegyek számát is
    _lcdH->setGeometry(0, 0, 130, 175);
    _lcdMin->setGeometry(150, 0, 130, 175);
    _lcdMin->setPalette(Qt::blue);
    _lcdH->setPalette(Qt::blue);
}

Idozito::~Idozito()
{
    delete _lcdMin;
    delete _lcdH;
    delete _timer;
}


void Idozito::updateTime(){
    time++;
    int min = time % 60;
    int h = time / 60;
    _lcdMin->display(min);
    _lcdH->display(h);
}
