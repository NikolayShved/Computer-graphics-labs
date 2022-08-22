#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H
#include <string>

using namespace std;

class Functional
{
private:
    string str_x, str_y;
public:
    Functional();
    void pointCalculation(double x1, double x2, double x_i);
    string getX();
    string getY();
    string getDegreesFromRadians(double radian);
};

#endif // FUNCTIONAL_H
