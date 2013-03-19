#include "Task.hh"

#include <QCoreApplication>
#include <QSettings>
#include <QTimer>

QString config_file()
{
    char * home(getenv("XDG_CONFIG_HOME"));

    if (home && *home)
    {
        return QString(home) + "/jenkins-qtray/config";
    }

    home = getenv("HOME");

    return QString(home) + "/.config/jenkins-qtray/config";
}

int main(int argv, char ** args)
{
    QCoreApplication app(argv, args);

    QSettings settings(config_file(), QSettings::IniFormat);

    Task * task = new Task(&app);

    QObject::connect(task, SIGNAL(finished()), &app, SLOT(quit()));

    QTimer::singleShot(0, task, SLOT(run()));

    return app.exec();
}
