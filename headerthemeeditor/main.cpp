/*
   SPDX-FileCopyrightText: 2013-2020 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "themeeditormainwindow.h"

#include "grantleeeditor-version.h"

#include <QApplication>
#include <QCommandLineParser>
#include <KAboutData>
#include <KLocalizedString>
#include <Kdelibs4ConfigMigrator>
#include <KCrash>
#include <KDBusService>

int main(int argc, char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps, true);
    app.setDesktopFileName(QStringLiteral("org.kde.headerthemeeditor"));
    KCrash::initialize();
    Kdelibs4ConfigMigrator migrate(QStringLiteral("headerthemeeditor"));
    migrate.setConfigFiles(QStringList() << QStringLiteral("headerthemeeditorrc"));
    migrate.setUiFiles(QStringList() << QStringLiteral("headerthemeeditorui.rc"));
    migrate.migrate();
    KLocalizedString::setApplicationDomain("headerthemeeditor");
    KAboutData aboutData(QStringLiteral("headerthemeeditor"),
                         i18n("Header Theme Editor"),
                         QStringLiteral(GRANTLEEEDITOR_VERSION),
                         i18n("Messageviewer Header Theme Editor"),
                         KAboutLicense::GPL_V2,
                         i18n("Copyright © 2013-2020 headerthemeeditor authors"));
    aboutData.addAuthor(i18n("Laurent Montel"), i18n("Maintainer"), QStringLiteral("montel@kde.org"));
    QApplication::setWindowIcon(QIcon::fromTheme(QStringLiteral("kmail")));
    aboutData.setOrganizationDomain(QByteArray("kde.org"));
    aboutData.setProductName(QByteArray("headerthemeeditor"));

    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);

    parser.process(app);
    aboutData.processCommandLine(&parser);

    KDBusService service;

    ThemeEditorMainWindow *mw = new ThemeEditorMainWindow();
    mw->show();
    const int ret = app.exec();
    return ret;
}
