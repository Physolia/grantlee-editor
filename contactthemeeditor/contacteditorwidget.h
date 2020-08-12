/*
   SPDX-FileCopyrightText: 2013-2020 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef CONTACTEDITORWIDGET_H
#define CONTACTEDITORWIDGET_H
#include "grantleethemeeditor/editorwidget.h"

class ContactEditorWidget : public GrantleeThemeEditor::EditorWidget
{
    Q_OBJECT
public:
    explicit ContactEditorWidget(QWidget *parent = nullptr);
    ~ContactEditorWidget() override;

public Q_SLOTS:
    void createCompleterList(const QStringList &extraCompletion = QStringList()) override;
};

#endif // CONTACTEDITORWIDGET_H
