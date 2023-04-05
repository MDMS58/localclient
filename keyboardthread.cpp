#include "keyboardthread.h"

void KeyboardThread::run()
{
    m_eventLoop.exec();
}
