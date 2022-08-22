#pragma once
#include <QOpenGLWidget>
#include <QMouseEvent>

class OGLFigure : public QOpenGLWidget {
private:
GLuint m_nFigure; // переменная для хранения номера дисплейного списка фигуры для её отображения.
GLfloat m_xRotate; // переменная для хранения углов поворота по оси Х.
GLfloat m_yRotate; // переменная для хранения углов поворота по оси Y.
QPoint m_ptPosition; // переменная, которая хранит координату указателя мыши в момент нажатия.
protected:
virtual void initializeGL();
virtual void resizeGL(int nWidth, int nHeight);
virtual void paintGL();
virtual void mousePressEvent(QMouseEvent *e);
virtual void mouseMoveEvent (QMouseEvent *e);
void createPartOne(GLfloat size = 1.0f);
void createPartTwo(GLfloat size = 1.0f);
void createPartThree(GLfloat size = 1.0f);
void createPartFour();
GLuint createFigure(GLfloat size = 1.0f);

public:
OGLFigure (QWidget *pwgt = 0);
};
