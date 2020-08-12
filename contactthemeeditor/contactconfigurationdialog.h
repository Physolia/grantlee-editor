/*
   SPDX-FileCopyrightText: 2013-2020 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef CONTACTCONFIGURATIONDIALOG_H
#define CONTACTCONFIGURATIONDIALOG_H

#include <QDialog>

namespace GrantleeThemeEditor {
class ConfigureWidget;
}

namespace Akonadi {
class AkonadiContactEditor;
}

namespace KPIMTextEdit {
class PlainTextEditorWidget;
}
class ContactConfigureDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ContactConfigureDialog(QWidget *parent = nullptr);
    ~ContactConfigureDialog();

    void readConfig();
    void writeConfig();

private:
    void slotDefaultClicked();
    void slotOkClicked();
    GrantleeThemeEditor::ConfigureWidget *mConfigureWidget = nullptr;
    KPIMTextEdit::PlainTextEditorWidget *mDefaultTemplate = nullptr;
    Akonadi::AkonadiContactEditor *mDefaultContact = nullptr;
};

#endif // CONTACTCONFIGURATIONDIALOG_H
