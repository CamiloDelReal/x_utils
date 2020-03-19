#ifndef PATHUTILS_HPP
#define PATHUTILS_HPP

#include <QObject>
#include <QRegularExpression>

namespace PathUtils
{

#if defined (Q_OS_ANDROID)
static const QString SEPARATOR = QStringLiteral("/");
#elif defined (Q_OS_IOS)
static const QString SEPARATOR = QStringLiteral("/");
#elif defined (Q_OS_WIN)
static const QString SEPARATOR = QStringLiteral("\\");
#elif defined (Q_OS_LINUX)
static const QString SEPARATOR = QStringLiteral("/");
#endif

void makeParentPath(const QString &filePath);

QString appicationDataPath();

QString downloadFolder();

}

#endif //PATHUTILS_HPP
