#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>

#include "pathutils.hpp"

void PathUtils::makeParentPath(const QString &filePath)
{
    QFileInfo info(filePath);
    QDir dir(info.absoluteDir());
    if(!dir.exists())
    {
        dir.mkpath(info.absoluteDir().absolutePath());
    }
}

QString PathUtils::appicationDataPath()
{
    QString path;
#if defined (Q_OS_ANDROID)
    path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(1);
#elif defined (Q_OS_IOS)
    path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);
#elif defined (Q_OS_WIN)
    path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);
#elif defined (Q_OS_LINUX)
    path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);
#endif
    return path;
}

QString PathUtils::downloadFolder()
{
    return QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).value(0);
}
