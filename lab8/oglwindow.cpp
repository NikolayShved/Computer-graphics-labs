#include "oglwindow.h"
 #include <cmath>

oglwindow::oglwindow(QWidget *parent) : QOpenGLWidget(parent)
{

}

void oglwindow::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    setViewport();
    setProjection();
}


void oglwindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    setModelView();
    for (int k = 1; k <= 2 * p; k++)
    {
        for (int j = -p; j <= p; j++)
        {
            double x0 = xA = 0.01f * j,  y0 = yA = 0.01f * (p-k);
            xB = pow(xA, 2) - pow(yA, 2)+a;
            yB = 2 * xA * yA + b;
            for (int i = 1; i <= n; i++)
            {
                xA = xB;
                yA = yB;
                xB = pow(xA, 2) - pow(yA, 2) + a;
                yB = 2 * xA * yA + b;
            }
            if (sqrt(xB*xB+yB*yB) < 1.5)
            {
                glColor3d(0.0f,  0.0f,  1.0f);
                glEnable(GL_POINT_SMOOTH);
                glPointSize(0.1f);
                glBegin(GL_POINTS);
                glVertex2d(y0 + 0.05, x0);
                glEnd();
            }
        }
    }
}

void oglwindow::setViewport()
{
    int width = this->width();
    int height = this->height();
    glViewport(0,0,width,height);
}

void oglwindow::setProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

void oglwindow::setModelView()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
