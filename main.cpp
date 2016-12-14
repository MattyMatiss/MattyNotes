#include "mattynotesmainwindow.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setWindowIcon(QIcon(":/MattyNotes/Main_icon.ico"));

    MattyNotesMainWindow w;
    w.show();

    return a.exec();
}
