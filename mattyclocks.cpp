#include "MattyClocks.h"

#include <QTimer>
#include <QTime>

MattyClocks::MattyClocks(QWidget *parent) : QLCDNumber(parent)
{
    this->setFixedSize(96, 51);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}


MattyClocks::~MattyClocks()
{
}


void MattyClocks::showTime()
{
    display(QTime::currentTime().toString().mid(0, 5));
}
