#ifndef NOTEHOLDER_H
#define NOTEHOLDER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QVector>
#include <QWidget>

class NoteHolder
{
public:
    NoteHolder();
    ~NoteHolder();
    void sortNotesByCrDate();
    static void publishNotes(QWidget* ParentWidget);
    static void setFilters();
    static void erasePublishedNotes(QWidget* ParentWidget);
private:
    static int TotalNoteCount;

    static QVector<class MattyNote> ListOfAllNotes;

    static void getAllNotes();
    static void getSelectedNotes();

};

#endif // NOTEHOLDER_H
