#include <QtGui/QApplication>
#include "dialog.h"

char name[40];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    
    return a.exec();
}
