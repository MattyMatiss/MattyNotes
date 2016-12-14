#ifndef MATTYNOTESMAINWINDOW_H
#define MATTYNOTESMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class mattynotesmainwindow;
}

class mattynotesmainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mattynotesmainwindow(QWidget *parent = 0);
    ~mattynotesmainwindow();

private:
    Ui::mattynotesmainwindow *ui;
};

#endif // MATTYNOTESMAINWINDOW_H
