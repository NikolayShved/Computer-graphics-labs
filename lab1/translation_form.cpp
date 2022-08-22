#include "translation_form.h"
#include "ui_translation_form.h"
#include <QIntValidator>
#include <QMessageBox>
#include "functional.h"

Translation_form::Translation_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Translation_form)
{
    ui->setupUi(this);
    QRegExp validator("[\\d,\\-,.]+");
    ui->lineEdit_rad->setValidator(new QRegExpValidator(validator));
}

Translation_form::~Translation_form()
{
    delete ui;
}

void Translation_form::on_pushButton_clicked()
{
    QString temp = ui->lineEdit_rad->text();
    double radian = temp.toDouble();
    if (radian)
    {
        Functional func;
        ui->lineEdit_deg->setText(QString::fromStdString(func.getDegreesFromRadians(radian)));
    }
    else
    {
        QMessageBox::warning(this, "Errors!", "Были введены некорректные данные или окно ввода пустое!");
    }
}
