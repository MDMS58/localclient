#ifndef KEYBOARDTHREAD_H
#define KEYBOARDTHREAD_H

#include <QThread>
#include <QEventLoop>

class KeyboardThread : public QThread
{
public:
    void run() override;

private:
    QEventLoop m_eventLoop;
};

#endif // KEYBOARDTHREAD_H
