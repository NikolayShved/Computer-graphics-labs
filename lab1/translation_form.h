#ifndef TRANSLATION_FORM_H
#define TRANSLATION_FORM_H

#include <QWidget>

namespace Ui {
class Translation_form;
}

class Translation_form : public QWidget
{
    Q_OBJECT

public:
    explicit Translation_form(QWidget *parent = nullptr);
    ~Translation_form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Translation_form *ui;
};

#endif // TRANSLATION_FORM_H
