#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new TestObjectModel();
    ui->tableView->setModel(model);

    detailsModel = new TestObjectDetailsModel();
    ui->tableView_2->setModel(detailsModel);

    selectionModel = ui->tableView->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
            this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));
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
    QModelIndex current = ui->tableView->currentIndex();
    model->moveRowDown(current.row());
    if(current.row() < model->rowCount() - 1) {
        QModelIndex newIndex  = model->index(current.row() + 1, current.column());
        ui->tableView->selectionModel()->select(newIndex, QItemSelectionModel::Select);
        ui->tableView->setCurrentIndex(newIndex);
    }
}

void MainWindow::on_pushButton_Up_clicked()
{
    QModelIndex current = ui->tableView->currentIndex();
    model->moveRowUp(ui->tableView->currentIndex().row());
    if(current.row() > 0) {
        QModelIndex newIndex  = model->index(current.row() - 1, current.column());
        ui->tableView->selectionModel()->select(newIndex, QItemSelectionModel::Select);
        ui->tableView->setCurrentIndex(newIndex);
    }
}

void MainWindow::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/)
{
    const QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    if(!index.isValid()) return;
    TestObject* to = model->getTestObject(index.row());
    detailsModel->setTestObject(to);
}
