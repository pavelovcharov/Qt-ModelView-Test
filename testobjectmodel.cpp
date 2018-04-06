#include "testobjectmodel.h"

TestObjectModel::TestObjectModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    TestObject* test = new TestObject();
    test->setProp1(1.01);
    test->setProp2(1.02);
    test->setProp3(1.03);
    test->setProp4(1.04);
    objects.push_back(test);
}

QVariant TestObjectModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("p1");
            case 1:
                return QString("p2");

            }
        }
    }
    return QVariant();
}
/*
bool TestObjectModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

*/
int TestObjectModel::rowCount(const QModelIndex &parent) const
{
    return objects.size();
}

int TestObjectModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant TestObjectModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid()){
        if (role == Qt::DisplayRole)
        {
            TestObject* to = objects[index.row()];
            return QString::number(index.column() == 0 ? to->prop1() : to->prop2());
        }
    }
    return QVariant();
}

bool TestObjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        TestObject* to = objects[index.row()];
        switch (index.column()) {
        case 0:
            to->setProp1(value.toDouble());
            break;
        case 1:
            to->setProp2(value.toDouble());
        default:
            break;
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TestObjectModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

      return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool TestObjectModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    TestObject* to = new TestObject();
    to->setProp1(99);
    to->setProp2(0.99);
    objects.insert(row, to);
    endInsertRows();
}

//bool TestObjectModel::insertColumns(int column, int count, const QModelIndex &parent)
//{
//    beginInsertColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endInsertColumns();
//}

bool TestObjectModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    TestObject* to = objects[row];
    objects.remove(row);
    delete to;
    endRemoveRows();
}

bool TestObjectModel::insertRow(int row)
{
    //TODO: check row is valid
    return insertRows(row, 1);
}

bool TestObjectModel::removeRow(int row)
{
    //TODO: check row is valid
    return removeRows(row, 1);
}

bool TestObjectModel::moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) {
    if(count != 1 || destinationChild < 0 || destinationChild >= rowCount()) return false;
    beginMoveRows(sourceParent, sourceRow, sourceRow, destinationParent, sourceRow < destinationChild ? destinationChild+1 : destinationChild);
    TestObject* to1 = objects[sourceRow];
    TestObject* to2 = objects[destinationChild];
    objects[sourceRow] = to2;
    objects[destinationChild] = to1;
    endMoveRows();
    return true;
}

bool TestObjectModel::moveRowUp(int row)
{
    QModelIndex sourceParent = index(row, 0);
    return moveRow(sourceParent, row, sourceParent, row - 1);
}

bool TestObjectModel::moveRowDown(int row)
{
    QModelIndex sourceParent = index(row, 0);
    return moveRow(sourceParent, row, sourceParent, row + 1);
}

//bool TestObjectModel::removeColumns(int column, int count, const QModelIndex &parent)
//{
//    beginRemoveColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endRemoveColumns();
//}
