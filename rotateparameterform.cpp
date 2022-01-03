#include "rotateparameterform.h"
#include "ui_rotateparameterform.h"

RotateParameterForm::RotateParameterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RotateParameterForm)
{
    ui->setupUi(this);
}

RotateParameterForm::~RotateParameterForm()
{
    delete ui;
}

void RotateParameterForm::on_spbRotateX_valueChanged(double arg1)
{
    double xA = ui->spbRotateX->value();
    double yA = ui->spbRotateY->value();
    double zA = ui->spbRotateZ->value();
    emit valueChanged(xA, yA, zA);
}

void RotateParameterForm::on_spbRotateY_valueChanged(double arg1)
{
    double xA = ui->spbRotateX->value();
    double yA = ui->spbRotateY->value();
    double zA = ui->spbRotateZ->value();
    emit valueChanged(xA, yA, zA);
}

void RotateParameterForm::on_spbRotateZ_valueChanged(double arg1)
{
    double xA = ui->spbRotateX->value();
    double yA = ui->spbRotateY->value();
    double zA = ui->spbRotateZ->value();
    emit valueChanged(xA, yA, zA);
}
