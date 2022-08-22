#include "functional.h"
#include "math.h"
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;

Functional::Functional()
{
    str_x = "", str_y = "";
}

//функция вычисления всех точек на графике по определённому промежутку
void Functional::pointCalculation(double x1, double x2, double x_i)
{
    double x, y;
    int i = 1;
    while (x2 >= x1)
    {
        x = (x1*M_PI)/180;
        y=sin(x);
        str_x += (to_string(i) + ") " + to_string(x) + "\n");
        str_y += (to_string(i) + ") " + to_string(y) + "\n");
        x1 += x_i;
        i++;
        if (x_i == 0)
        {
            break;
        }
    }
}

//Функция, передающая все значения точек по переменной x
string Functional::getX()
{
    return str_x;
}

//Функция, передающая все значения точек по переменной y
string Functional::getY()
{
    return str_y;
}

//Функция перевода из радиан в градусы
string Functional::getDegreesFromRadians(double radian)
{
    int degree = (int)ceil(180 * radian);
    string str_degree = to_string(degree);
    return str_degree;
}
