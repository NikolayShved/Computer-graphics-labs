#include "geometric_function.h"
#include <QPainter>
#include <math.h>

Geometric_Function::Geometric_Function()
{

}

QPoint Geometric_Function::lineIntersectionPoint(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    QPoint I;
    double a1, a2, b1, b2, c1, c2;
    double x, y;

    a1 = y1 - y2;
    b1 = x2 - x1;
    c1 = x1 * y2 - x2 * y1;
    a2 = y3 - y4;
    b2 = x4 - x3;
    c2 = x3 * y4 - x4 * y3;

    double det = a1 * b2 - a2 * b1;
    x = (b1 * c2 - b2 * c1) / det;
    y = (a2 * c1 - a1 * c2) / det;
    I.setX(x);
    I.setY(y);

    return I;
}

QPoint Geometric_Function::distanceFromPointToLine(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5)
{
    double a1, b1, c1, a2, b2, c2, h1, h2;
    QPoint D;
    a1 = y1 - y2;
    b1 = x1 - x2;
    c1 = (y1 * x2) - (y2 * x1);
    h1 =((a1 * x5) + (b1 * y5) + c1) / sqrt((a1 * a1) + (b1 * b1));

    a2 = y3 - y4;
    b2 = x3 - x4;
    c2 = (y3 * x4) - (y4 * x3);
    h2 =((a2 * x5) + (b2 * y5) + c2) / sqrt((a2 * a2) + (b2 * b2));

    if (h1 >= h2)
    {
        int x6= ((x2-x1)*(y2-y1)*(y5-y1)+x1*pow(y2-y1, 2)+x5*pow(x2-x1, 2))/(pow(y2-y1, 2)+pow(x2-x1, 2));
        int y6 = (y2-y1)*(x6-x1)/(x2-x1)+y1;
        D.setX(x6);
        D.setY(y6);
    }
    else if (h2 > h1)
    {
        int x6= ((x4-x3)*(y4-y3)*(y5-y3)+x3*pow(y4-y3, 2)+x5*pow(x4-x3, 2))/(pow(y4-y3, 2)+pow(x4-x3, 2));
        int y6 = (y4-y3)*(x6-x3)/(x4-x3)+y3;
        D.setX(x6);
        D.setY(y6);
    }

    return D;
}
