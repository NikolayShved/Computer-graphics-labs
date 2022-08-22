#include "oglhyperbolicparaboloid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLHyperbolicParaboloid oglHyperbolicParaboloid;
    oglHyperbolicParaboloid.resize(800, 800);
    oglHyperbolicParaboloid.show();
    oglHyperbolicParaboloid.setWindowTitle("Построение гиперболического параболоида");
    return a.exec();
}
