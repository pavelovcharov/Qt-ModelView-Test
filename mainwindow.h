#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "testobjectmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_pushButton_Down_clicked();

    void on_pushButton_Up_clicked();

private:
    Ui::MainWindow *ui;
    TestObjectModel* model;
};

#endif // MAINWINDOW_H
