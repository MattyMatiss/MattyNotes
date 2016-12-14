#include "mattynotesmainwindow.h"
#include "ui_mattynotesmainwindow.h"

mattynotesmainwindow::mattynotesmainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mattynotesmainwindow)
{
    ui->setupUi(this);
}

mattynotesmainwindow::~mattynotesmainwindow()
{
    delete ui;
}
