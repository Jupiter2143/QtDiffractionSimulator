#ifndef QWDOUBLESPINDELEGATE_H
#define QWDOUBLESPINDELEGATE_H

#include <QStyledItemDelegate>

class QWDoubleSpinDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit QWDoubleSpinDelegate(QObject* parent = nullptr);
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const Q_DECL_OVERRIDE;
    void setEditorData(QWidget* editor, const QModelIndex& index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const Q_DECL_OVERRIDE;
};

#endif // QWDOUBLESPINDELEGATE_H
