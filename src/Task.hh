#ifndef TASK_HH
#define TASK_HH

#include <QNetworkReply>
#include <QObject>
#include <unistd.h>

class Task
    : public QObject
{
    Q_OBJECT
public:
    Task(QObject * parent = 0)
        : QObject(parent)
    {
    }

public slots:
    void run();
    void fetchFinished(QNetworkReply *);

signals:
    void finished();
};

#endif
