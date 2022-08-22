#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include "geometric_function.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *m_plblX;
    QLabel *m_plblY;
    QLabel *m_plblCentreX;
    QLabel *m_plblCentreY;
    int x, y;
    QVector <int> myVector;
    Geometric_Function gf;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void additionalFunction(QPainter &prt);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
