#include <QApplication>
#include "ogl_figure.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLFigure oglFigure;
    oglFigure.resize(200, 200);
    oglFigure.show();
    return a.exec();
}
