#ifndef MATTYGROUPBOX_H
#define MATTYGROUPBOX_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QGroupBox>
#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>

#include "mattynote.h"

class MattyGroupBox :
    public QGroupBox
{
    Q_OBJECT
public:
    MattyGroupBox(const class MattyNote & ThisNote = MattyNote(), QWidget* parent = 0);

    ~MattyGroupBox();

    void hideNote();
    void expandNote();
    void changeExpandHideMode();

private:
    void buildFrame();
    void fillFrame(const class MattyNote & ThisNote);
    QLabel* NoteTypeLabel;
    QLabel* NoteCrTimeAndDateLabel;
    QLabel* NoteEventTimeAndDateLabel;
    QLabel* NoteTextLabel;
    QSpacerItem* horizontalSpacer_1;
    QSpacerItem* horizontalSpacer_2;
    QSpacerItem* verticalSpacer;
    QPushButton* editNoteButton;
    QPushButton* deleteNoteButton;
    QHBoxLayout* horizontalLayout_1;
    QHBoxLayout* horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QWidget *horizontalLineWidget;

    class MattyNote ThisGroupBoxNote;
    void mouseDoubleClickEvent(QMouseEvent * e);
    //void mousePressEvent(QMouseEvent * e);

    private slots:
    void deleteNote();
    void editNote();
};

#endif // MATTYGROUPBOX_H
