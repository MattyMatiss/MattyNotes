#ifndef ADDNOTEDIALOG_H
#define ADDNOTEDIALOG_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

#include <QWidget>
#include "MattyNote.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QComboBox>
#include <QTimeEdit>
#include <QDateEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addNoteDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *noteTitleText;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *noteTypeComboBox;
    QTimeEdit *eventTimeEdit;
    QDateEdit *eventDateEdit;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *noteTextText;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *cancelAddingNoteButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *createNoteButton;

    void setupUi(QWidget *addNoteDialog)
    {
        if (addNoteDialog->objectName().isEmpty())
            addNoteDialog->setObjectName(QStringLiteral("addNoteDialog"));
        addNoteDialog->resize(539, 525);
        gridLayout = new QGridLayout(addNoteDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        noteTitleText = new QTextEdit(addNoteDialog);
        noteTitleText->setObjectName(QStringLiteral("noteTitleText"));
        noteTitleText->setMaximumSize(QSize(16777215, 31));

        gridLayout->addWidget(noteTitleText, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem
                (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        noteTypeComboBox = new QComboBox(addNoteDialog);
        noteTypeComboBox->setObjectName(QStringLiteral("noteTypeComboBox"));
        noteTypeComboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(noteTypeComboBox);

        eventTimeEdit = new QTimeEdit(addNoteDialog);
        eventTimeEdit->setObjectName(QStringLiteral("eventTimeEdit"));
        eventTimeEdit->setCalendarPopup(false);

        horizontalLayout->addWidget(eventTimeEdit);

        eventDateEdit = new QDateEdit(addNoteDialog);
        eventDateEdit->setObjectName(QStringLiteral("eventDateEdit"));
        eventDateEdit->setCalendarPopup(true);
        eventDateEdit->setDate(QDate(2016, 11, 1));

        horizontalLayout->addWidget(eventDateEdit);

        horizontalSpacer_2 = new QSpacerItem
                (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        noteTextText = new QTextEdit(addNoteDialog);
        noteTextText->setObjectName(QStringLiteral("noteTextText"));
        noteTextText->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(noteTextText, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName
                (QStringLiteral("horizontalLayout_5"));
        cancelAddingNoteButton = new QPushButton(addNoteDialog);
        cancelAddingNoteButton->setObjectName
                (QStringLiteral("cancelAddingNoteButton"));

        horizontalLayout_5->addWidget(cancelAddingNoteButton);

        horizontalSpacer_6 = new QSpacerItem
                (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        createNoteButton = new QPushButton(addNoteDialog);
        createNoteButton->setObjectName(QStringLiteral("createNoteButton"));

        horizontalLayout_5->addWidget(createNoteButton);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        QMetaObject::connectSlotsByName(addNoteDialog);
    } // setupUi

};

namespace Ui {
    class addNoteDialog: public Ui_addNoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

enum Action { Add, Edit };

class addNoteDialog : public QDialog {
    Q_OBJECT

public:
    addNoteDialog(Action DialogTypeIncm, int EditingNoteIdIncm = -1,
                  QWidget *parent = 0);

    QPushButton createNoteButton;
    QPushButton cancelAddingNoteButton;

    ~addNoteDialog();

private:
    Ui::addNoteDialog addNoteDialogUi;

    QAction *SaveNote;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    Action DialogType;
    int EditingNoteId;

    class MattyNote ThisDialogNote;

    private slots:
    void on_createNoteButton_clicked();
    void on_cancelAddingNoteButton_clicked();
    //void closeEvent(QCloseEvent *event);
};

#endif // ADDNOTEDIALOG_H
