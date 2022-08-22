#include "widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter myContent(this);
    QVector <int> myVector;
    QObjectList list = this->children();
    foreach(QObject * child, list)
    {
        if (child->isWidgetType())
        {
            if (child->objectName().left(7) == "spinBox")
            {
                QSpinBox *i = static_cast<QSpinBox*>(static_cast<QWidget*>(child));
                myVector << i->value();
            }
        }
    }
    drawLines(myContent, myVector);
}

void Widget::drawLines(QPainter &prt, QVector<int> myVector)
{
     ui->setupUi(this);
     QPen pen(Qt::green, 3, Qt::SolidLine);
     prt.setPen(pen);
     prt.drawLine(myVector.at(0), myVector.at(1), myVector.at(2), myVector.at(3));
     prt.drawLine(myVector.at(2), myVector.at(3), myVector.at(4), myVector.at(5));
     prt.drawLine(myVector.at(0), myVector.at(1), myVector.at(6), myVector.at(7));
     prt.drawLine(myVector.at(2), myVector.at(3), myVector.at(6), myVector.at(7));
     prt.drawLine(myVector.at(4), myVector.at(5), myVector.at(6), myVector.at(7));
     pen.setStyle(Qt::DashLine);
     prt.setPen(pen);
     prt.drawLine(myVector.at(4), myVector.at(5), myVector.at(0), myVector.at(1));
}
