#include <QtWidgets/QApplication>
#include "MyProject.h"
int main(int argc, char *argv[])
{ QApplication a(argc, argv);
    MyProject mw;
    mw.show();
    return a.exec();
}
