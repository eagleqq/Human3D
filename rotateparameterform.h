#ifndef ROTATEPARAMETERFORM_H
#define ROTATEPARAMETERFORM_H

#include <QWidget>

namespace Ui {
class RotateParameterForm;
}

class RotateParameterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RotateParameterForm(QWidget *parent = 0);
    ~RotateParameterForm();

signals:
    void valueChanged(double xA, double yA, double zA);

private slots:
    void on_spbRotateX_valueChanged(double arg1);

    void on_spbRotateY_valueChanged(double arg1);

    void on_spbRotateZ_valueChanged(double arg1);

private:
    Ui::RotateParameterForm *ui;
};

#endif // ROTATEPARAMETERFORM_H
