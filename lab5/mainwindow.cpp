#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "geometric_function.h"
#include <QLabel>
#include <QPainter>
#include<QMouseEvent>
#include<QStatusBar>

MainWindow::~MainWindow()
{

}

void MainWindow::mouseMoveEvent(QMouseEvent* pe)
{
     m_plblX->setText("X=" + QString().setNum(pe->x()));
     m_plblY->setText("Y=" + QString().setNum(pe->y()));
}

void MainWindow::mousePressEvent(QMouseEvent* pe)
{
    QPainter myContent(this);
    x = pe->x();
    y = pe->y();
    myVector << x;
    myVector << y;
    if ((myVector.size() == 4) || (myVector.size() == 8) || (myVector.size() == 10))
    {
        update();
    }
}

void MainWindow::additionalFunction(QPainter &prt)
{
    QPen pen(Qt::black, 3, Qt::SolidLine);
    prt.setPen(pen);
    prt.drawLine(myVector.at(0), myVector.at(1), myVector.at(2), myVector.at(3));
    prt.drawLine(myVector.at(4), myVector.at(5), myVector.at(6), myVector.at(7));
    QPoint I = gf.lineIntersectionPoint(myVector.at(0), myVector.at(1), myVector.at(2), myVector.at(3),
                             myVector.at(4), myVector.at(5), myVector.at(6), myVector.at(7));

    QPen pen1(Qt::red, 9, Qt::SolidLine);
    prt.setPen(pen1);
    prt.drawPoint(I.x(), I.y());
    m_plblCentreX->setText("Координаты точки пересечения отрезков: X=" + QString().setNum(I.x()));
    m_plblCentreY->setText(" Y=" + QString().setNum(I.y()));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter prt(this);
    if (myVector.size() == 4)
    {
        QPen pen1(Qt::black, 3, Qt::SolidLine);
        prt.setPen(pen1);
        prt.drawLine(myVector.at(0), myVector.at(1), myVector.at(2), myVector.at(3));
    }
    else if (myVector.size() == 8)
    {
        additionalFunction(prt);
    }
    else if (myVector.size() == 10)
    {
        additionalFunction(prt);
        QPen pen2(Qt::blue, 9, Qt::SolidLine);
        prt.setPen(pen2);
        prt.drawPoint(myVector.at(8), myVector.at(9));
        QPoint D = gf.distanceFromPointToLine(myVector.at(0), myVector.at(1), myVector.at(2), myVector.at(3), myVector.at(4),
                                              myVector.at(5), myVector.at(6), myVector.at(7), myVector.at(8), myVector.at(9));
        QPen pen4(Qt::black, 3, Qt::SolidLine);
        prt.setPen(pen4);
        prt.drawLine(myVector.at(8), myVector.at(9), D.x(), D.y());
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMouseTracking(true);
    m_plblX = new QLabel(this);
    m_plblY = new QLabel(this);
    m_plblCentreX = new QLabel(this);
    m_plblCentreY = new QLabel(this);
    statusBar()->addWidget(m_plblX);
    statusBar()->addWidget(m_plblY);
    statusBar()->addWidget(m_plblCentreX);
    statusBar()->addWidget(m_plblCentreY);
}
