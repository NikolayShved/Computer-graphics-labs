#include "widget.h"
#include "ui_widget.h"
#include <QIntValidator>
#include <QMessageBox>
#include "functional.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{ 
    ui->setupUi(this);
    QRegExp validator("[\\d,\\-,.]+");
    ui->lineEdit_1->setValidator(new QRegExpValidator(validator));
    ui->lineEdit_2->setValidator(new QRegExpValidator(validator));
    ui->lineEdit_3->setValidator(new QRegExpValidator(validator));

    tForm = new Translation_form();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString temp1 = ui->lineEdit_1->text();
    QString temp2 = ui->lineEdit_2->text();
    QString temp3 = ui->lineEdit_3->text();
    double a1 = temp1.toDouble(), a2 = temp2.toDouble(), a3 = temp3.toDouble();
    if (((!a1) and (temp1 != "0")) or ((!a2) and (temp2 != "0")) or ((!a3) and (temp3 != "0")))
    {
        QMessageBox::warning(this, "Errors!", "Были введены некорректные данные или окно ввода пустое!");
    }
    else if ((temp1 == "0") and (temp2 == "0") and (temp3 == "0"))
    {
        QMessageBox::warning(this, "Errors!", "Во всех окнах было введено нулевое значение!");
    }
    else
    {
        Functional func;
        func.pointCalculation(a1, a2, a3);
        ui->textEdit_1->setText(QString::fromStdString(func.getX()));
        ui->textEdit_2->setText(QString::fromStdString(func.getY()));
    }
}

void Widget::on_pushButton_2_clicked()
{
    tForm->show();
}
