/*
   SPDX-FileCopyrightText: 2013-2020 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef THEMESESSION_H
#define THEMESESSION_H
#include "grantleethemeeditor_export.h"
#include <QString>
#include <QStringList>

namespace GrantleeThemeEditor {
class GRANTLEETHEMEEDITOR_EXPORT ThemeSession
{
public:
    ThemeSession(const QString &projectDirectory, const QString &themeTypeName);
    ~ThemeSession();
    Q_REQUIRED_RESULT bool loadSession(const QString &session);
    void writeSession(const QString &directory = QString());

    Q_REQUIRED_RESULT QString projectDirectory() const;

    void addExtraPage(const QString &filename);
    Q_REQUIRED_RESULT QStringList extraPages() const;

    void setMainPageFileName(const QString &filename);
    Q_REQUIRED_RESULT QString mainPageFileName() const;

private:
    QString mProjectDirectory;
    QString mMainPageFileName;
    QStringList mExtraPage;
    QString mThemeTypeName;
    int mVersion;
};
}

#endif // THEMESESSION_H
