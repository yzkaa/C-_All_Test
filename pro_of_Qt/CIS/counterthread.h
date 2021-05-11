#ifndef COUNTERTHREAD_H
#define COUNTERTHREAD_H

#include <QThread>
#include <QObject>

class CounterThread : public QThread
{
public:
    CounterThread(QObject *parent = nullptr);
    QString originImgPath;
    QString labelImgPath;
protected:
    void run();
};

#endif // COUNTERTHREAD_H
