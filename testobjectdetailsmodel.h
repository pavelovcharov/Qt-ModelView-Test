#ifndef TESTOBJECTDETAILSMODEL_H
#define TESTOBJECTDETAILSMODEL_H

#include <QAbstractTableModel>
#include "testobject.h"

class TestObjectDetailsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TestObjectDetailsModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;


    void setTestObject(TestObject* _testObject);
private:
    TestObject* _testObject;
};

#endif // TESTOBJECTDETAILSMODEL_H
