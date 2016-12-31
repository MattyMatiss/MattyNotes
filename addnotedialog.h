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
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QComboBox>
#include <QTimeEdit>
#include <QDateEdit>
#include <QPushButton>

#include "mattynote.h"

enum Action { Add, Edit };

class addNoteDialog : public QDialog {
    Q_OBJECT

public:
    addNoteDialog(Action DialogTypeIncm, int EditingNoteIdIncm = -1,
                  QWidget *parent = 0);

    ~addNoteDialog();

private:

    class MattyNote ThisDialogNote;

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

    QAction *SaveNote;

    Action DialogType;
    int EditingNoteId;

    void buildBody();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    private slots:
    void on_createNoteButton_clicked();
    void on_cancelAddingNoteButton_clicked();
};

#endif // ADDNOTEDIALOG_H
