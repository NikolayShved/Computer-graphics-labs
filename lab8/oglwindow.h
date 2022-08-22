#ifndef OGLWINDOW_H
#define OGLWINDOW_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class oglwindow : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit oglwindow(QWidget *parent = 0);

signals:

public slots:

protected:
     void initializeGL();
     void paintGL();
     void setViewport();
     void setProjection();
     void setModelView();

    public:
    int n = 15;
    double xA,  yA,  xB,  yB,  a = 0.4,  b = 0.2,  p = 130;
};

#endif // OGLWINDOW_H
