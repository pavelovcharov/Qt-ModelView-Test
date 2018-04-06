#ifndef TESTOBJECTDELEGATE_H
#define TESTOBJECTDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class TestObjectDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TestObjectDelegate(QObject *parent = 0);
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const override;
signals:

public slots:
};

#endif // TESTOBJECTDELEGATE_H
