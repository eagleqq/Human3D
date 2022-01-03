#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sensorloader.h"

#include <QMainWindow>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT
  QThread workerThread;
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void moveWindowToCenter();

public slots:
  void slot_OnValueChanged(double xA, double yA, double zA);
  void slot_handleResult(QVariant data);

signals:
    void stopped();
    void open(const QString &path);

private slots:
    void on_tbnSelectFile_clicked();

    void on_btnLoadRun_clicked();

    void on_btnStop_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
