#include "mattynotesmainwindow.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/All/resources/Main_icon.ico"));

    MattyNotesMainWindow w;
    w.show();

    return a.exec();
}
