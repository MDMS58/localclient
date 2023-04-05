#include "keyeventfilter.h"
#include <QKeyEvent>

KeyEventFilter::KeyEventFilter(QObject *parent)
    : QObject(parent)
{
}

bool KeyEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        emit keyPressed(keyEvent->key());
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
}
