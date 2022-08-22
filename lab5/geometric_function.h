#ifndef GEOMETRIC_FUNCTION_H
#define GEOMETRIC_FUNCTION_H
#include <QPainter>

class Geometric_Function
{
public:
    Geometric_Function();
    QPoint lineIntersectionPoint(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    QPoint distanceFromPointToLine(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5);
};

#endif // GEOMETRIC_FUNCTION_H
