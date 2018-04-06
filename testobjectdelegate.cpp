#include "testobjectdelegate.h"
#include <QLineEdit>

TestObjectDelegate::TestObjectDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *TestObjectDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    return editor;
}

void TestObjectDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QVariant value = index.model()->data(index, Qt::EditRole);

    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(value.toString());
}

void TestObjectDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    model->setData(index, lineEdit->text(), Qt::EditRole);
}
