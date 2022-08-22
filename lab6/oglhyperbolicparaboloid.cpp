#include "oglhyperbolicparaboloid.h"
#include<QOpenGLFunctions>
#include <QMouseEvent>


OGLHyperbolicParaboloid::OGLHyperbolicParaboloid(QWidget* pwgt) : QOpenGLWidget(pwgt),
                                                                  m_xRotate(0),
                                                                  m_yRotate(0)
{}

void OGLHyperbolicParaboloid::initializeGL()
{
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    pFunc->glEnable(GL_DEPTH_TEST);
    m_nHyperbolicParaboloid = createHyperbolicParaboloid();
}

void OGLHyperbolicParaboloid::resizeGL(int nWidth, int nHeight)
{
    glViewport (0, 0, (GLint) nWidth, (GLint) nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

void OGLHyperbolicParaboloid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);
    glCallList(m_nHyperbolicParaboloid);
}

void OGLHyperbolicParaboloid::mousePressEvent(QMouseEvent *e)
{
    m_ptPosition = e->pos();
}

void OGLHyperbolicParaboloid::mouseMoveEvent(QMouseEvent *e)
{
    m_xRotate += 180 * (GLfloat) (e->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat) (e->x() - m_ptPosition.x()) / width();
    update();
    m_ptPosition = e->pos();
}

GLuint OGLHyperbolicParaboloid::createHyperbolicParaboloid()
{
    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);
    int a = 2, b = 3;
    GLfloat z;
    glBegin(GL_LINES_ADJACENCY);
    for (GLfloat i = -8.0; i <= 8.0; i = i + 0.05)
    {
        for (GLfloat j = -8.0; j <= 8.0; j = j + 0.05)
        {
            if ((j >= -8.0) and (j < -3.0))
            {
                glColor3f(1.0, 0.0, 0.0);
            }
            else if ((j >= -3.0) and (j < 4.0))
            {
                glColor3f(0.0, 1.0, 0.0);
            }
            else
            {
                glColor3f(0.0, 0.0, 1.0);
            }
            z = ((i*i) / (a*a)) - ((j*j) / (b*b));
            glVertex3d(i / 10.0, j / 10.0, z / 10.0);
        }
    }
    glEnd();
    glEndList();
    return n;
}
