#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelectionModel>
#include "testobjectmodel.h"
#include "testobjectdetailsmodel.h"

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

    void selectionChangedSlot(const QItemSelection & newSelection, const QItemSelection & oldSelection);
private:
    Ui::MainWindow *ui;
    TestObjectModel* model;
    TestObjectDetailsModel* detailsModel;
    QItemSelectionModel* selectionModel;
};

#endif // MAINWINDOW_H
