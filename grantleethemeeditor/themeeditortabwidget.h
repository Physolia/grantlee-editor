/*
   SPDX-FileCopyrightText: 2013-2020 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef THEMEEDITORTABWIDGET_H
#define THEMEEDITORTABWIDGET_H

#include "grantleethemeeditor_export.h"
#include <QTabWidget>
namespace GrantleeThemeEditor {
class GRANTLEETHEMEEDITOR_EXPORT ThemeEditorTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit ThemeEditorTabWidget(QWidget *parent = nullptr);
    ~ThemeEditorTabWidget();

public Q_SLOTS:
    void slotMainFileNameChanged(const QString &fileName);

private:
    void slotTabContextMenuRequest(const QPoint &pos);
};
}
#endif // THEMEEDITORTABWIDGET_H
