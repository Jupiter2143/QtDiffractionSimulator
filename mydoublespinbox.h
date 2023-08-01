#ifndef MYDOUBLESPINBOX_H
#define MYDOUBLESPINBOX_H

#include <QDoubleSpinBox>
extern QMap<QString, double> unitMap;
class MyDoubleSpinBox : public QDoubleSpinBox {
public:
    MyDoubleSpinBox(QWidget* parent = nullptr);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
};

#endif // MYDOUBLESPINBOX_H
