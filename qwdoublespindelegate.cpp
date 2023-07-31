#include "qwdoublespindelegate.h"
#include <QDoubleSpinBox>
QWDoubleSpinDelegate::QWDoubleSpinDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget *QWDoubleSpinDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDoubleSpinBox *editor = new QDoubleSpinBox{parent};
    editor->setFrame(false);
    editor->setDecimals(3);
    editor->setMinimum(-999);
    editor->setMaximum(999);
    editor->setSingleStep(1);
    return editor;
}

void QWDoubleSpinDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    double value = index.data(Qt::EditRole).toDouble();
    spinBox->setValue(value);
}

void QWDoubleSpinDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    double value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

void QWDoubleSpinDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
