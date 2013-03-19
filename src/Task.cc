#include "Task.hh"

#include <QDebug>
#include <QNetworkAccessManager>

void Task::run()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(fetchFinished(QNetworkReply*)));

    QNetworkReply * reply = manager->get(QNetworkRequest(QUrl("http://www.google.com/")));
}

void Task::fetchFinished(QNetworkReply * reply)
{
    if (reply->error())
    {
        qDebug() << "Erroh fetching " << reply->errorString();
    }
    else
    {
        QByteArray read = reply->readAll();

        qDebug() << read;
    }

    reply->deleteLater();    
    emit finished();
}
