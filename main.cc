#include "bokstavman.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BokstavMan w;
    w.show();

    return a.exec();
}
