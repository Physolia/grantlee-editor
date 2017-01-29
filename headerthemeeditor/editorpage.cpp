/*
   Copyright (C) 2013-2017 Montel Laurent <montel@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "editorpage.h"
#include "editorwidget.h"
#include "previewwidget.h"
#include "themeeditorwidget.h"
#include "themetemplatewidget.h"
#include "kpimtextedit/plaintexteditor.h"
#include "KSplitterCollapserButton"

#include <KLocalizedString>

#include <KConfigGroup>

#include <QSplitter>
#include <QVBoxLayout>
#include <KSharedConfig>

EditorPage::EditorPage(GrantleeThemeEditor::EditorPage::PageType type, const QString &projectDirectory, QWidget *parent)
    : GrantleeThemeEditor::EditorPage(type, parent),
      mWidgetSplitter(nullptr)
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->setMargin(0);

    mMainSplitter = new QSplitter;
    if (mType == MainPage) {
        mWidgetSplitter = new QSplitter;
        mWidgetSplitter->setOrientation(Qt::Vertical);
        mWidgetSplitter->setChildrenCollapsible(false);
        lay->addWidget(mWidgetSplitter);

        mWidgetSplitter->addWidget(mMainSplitter);

        mPreview = new PreviewWidget(projectDirectory);
        mWidgetSplitter->addWidget(mPreview);
        connect(mPreview, &PreviewWidget::needUpdateViewer, this, &EditorPage::needUpdateViewer);
    } else {
        lay->addWidget(mMainSplitter);
    }

    mEditor = new ThemeEditorWidget;

    if (mType == MainPage) {
        KConfigGroup group(KSharedConfig::openConfig(), QStringLiteral("Global"));
        mEditor->setPlainText(group.readEntry("defaultTemplate", QString()));
    }
    mMainSplitter->addWidget(mEditor);
    mThemeTemplate = new ThemeTemplateWidget(i18n("Theme Templates:"));
    connect(mThemeTemplate, &ThemeTemplateWidget::insertTemplate, mEditor->editor(), &QPlainTextEdit::insertPlainText);
    mMainSplitter->addWidget(mThemeTemplate);
    mMainSplitter->setCollapsible(0, false);
    new KSplitterCollapserButton(mThemeTemplate, mMainSplitter);

    connect(mEditor->editor(), &QPlainTextEdit::textChanged, this, &GrantleeThemeEditor::EditorPage::changed);

    if (mType == MainPage) {
        KConfigGroup group(KSharedConfig::openConfig(), "EditorPage");
        const QList<int> size{400, 100};
        mMainSplitter->setSizes(group.readEntry("mainSplitter", size));
        mWidgetSplitter->setSizes(group.readEntry("widgetSplitter", size));
    }
}

EditorPage::~EditorPage()
{
    if (mType == MainPage) {
        KConfigGroup group(KSharedConfig::openConfig(), "EditorPage");
        group.writeEntry("mainSplitter", mMainSplitter->sizes());
        group.writeEntry("widgetSplitter", mWidgetSplitter->sizes());
    }
}

GrantleeThemeEditor::PreviewWidget *EditorPage::preview() const
{
    return mPreview;
}

