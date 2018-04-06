#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new TestObjectModel();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Add_clicked()
{
    model->insertRow(model->rowCount());
}

void MainWindow::on_pushButton_Remove_clicked()
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void MainWindow::on_pushButton_Down_clicked()
{

}

void MainWindow::on_pushButton_Up_clicked()
{

}
