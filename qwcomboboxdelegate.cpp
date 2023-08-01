#include "qwcomboboxdelegate.h"
#include <QComboBox>
QWComboBoxDelegate::QWComboBoxDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
}

QWidget* QWComboBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QComboBox* comboBox = new QComboBox(parent);
    comboBox->addItem("circle");
    comboBox->addItem("rectangle");
    comboBox->addItem("point");
    return comboBox;
}

void QWComboBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QComboBox* comboBox = static_cast<QComboBox*>(editor);
    QString value = index.data(Qt::EditRole).toString();
    int currentIndex = comboBox->findText(value);
    if (currentIndex >= 0)
        comboBox->setCurrentIndex(currentIndex);
}

void QWComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    QComboBox* comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText();
    int currentIndex = comboBox->currentIndex();
    model->setData(index, value, Qt::EditRole);
    model->setData(index, currentIndex, Qt::UserRole);
}

void QWComboBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    editor->setGeometry(option.rect);
}
