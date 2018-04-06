#include "testobjectdetailsmodel.h"

TestObjectDetailsModel::TestObjectDetailsModel(QObject *parent)
    : QAbstractTableModel(parent), _testObject(0)
{
}

QVariant TestObjectDetailsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Prop");
            case 1:
                return QString("Value");

            }
        }
        else {
            switch (section)
            {
            case 0:
                return QString("P3");
            case 1:
                return QString("P4");

            }
        }
    }
    return QVariant();
}

int TestObjectDetailsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 2; //properties to show
}

int TestObjectDetailsModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 1; // one object - one column
}

QVariant TestObjectDetailsModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && _testObject != 0){
        if (role == Qt::DisplayRole)
        {
            return QString::number(index.column() == 0 ? _testObject->prop3() : _testObject->prop4());
        }
    }
    return QVariant();
}

bool TestObjectDetailsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        switch (index.column()) {
        case 0:
            _testObject->setProp3(value.toDouble());
            break;
        case 1:
            _testObject->setProp4(value.toDouble());
        default:
            break;
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TestObjectDetailsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

      return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void TestObjectDetailsModel::setTestObject(TestObject *to)
{
    _testObject = to;
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}
