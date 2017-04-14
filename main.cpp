#include "idozito.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Idozito w;
    w.show();



    return a.exec();
}
