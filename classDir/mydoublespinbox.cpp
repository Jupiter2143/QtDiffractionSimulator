#include "mydoublespinbox.h"
#include <QContextMenuEvent>
#include <QInputDialog>
#include <QMenu>
#include <QMessageBox>

MyDoubleSpinBox::MyDoubleSpinBox(QWidget* parent)
    : QDoubleSpinBox(parent)
{
    installEventFilter(this);
    setButtonSymbols(QAbstractSpinBox::NoButtons);
    setAlignment(Qt::AlignRight);
    setMinimum(-999.999);
    setMaximum(999.999);
    setSingleStep(0.1);
}

bool MyDoubleSpinBox::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::ContextMenu) {
        QMenu menu(this);
        QAction* actSuffix_m = menu.addAction("m");
        QAction* actSuffix_cm = menu.addAction("cm");
        QAction* actSuffix_mm = menu.addAction("mm");
        QAction* actSuffix_um = menu.addAction("um");
        QAction* actSuffix_nm = menu.addAction("nm");
        QAction* selectedAction = menu.exec(mapToGlobal(static_cast<QContextMenuEvent*>(event)->pos()));
        if (selectedAction == actSuffix_m) {
            setSuffix("  m");
        } else if (selectedAction == actSuffix_cm) {
            setSuffix(" cm");
        } else if (selectedAction == actSuffix_mm) {
            setSuffix(" mm");
        } else if (selectedAction == actSuffix_um) {
            setSuffix(" um");
        } else if (selectedAction == actSuffix_nm) {
            setSuffix(" nm");
        }
        return true;
    }
    return QDoubleSpinBox::eventFilter(obj, event);
}
