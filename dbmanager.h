#ifndef DBMANAGER_H
#define DBMANAGER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "mattynote.h"
#include "queryconstructor.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlError>
#include <QString>

struct RowNote
{
    RowNote()
    {}

    RowNote(int NoteIdIncm, QString NoteTitleIncm, QString NoteTypeIncm,
            QString NoteTextIncm, QString EventTimeIncm, QString EventDateIncm,
            QString CrTimeIncm, QString CtDateIncm, int TypeIdIncm)
        : NoteId(NoteIdIncm),
          NoteTitle(NoteTitleIncm),
          NoteType(NoteTypeIncm),
          NoteText(NoteTextIncm),
          EventTime(EventTimeIncm),
          EventDate(EventDateIncm),
          CrTime(CrTimeIncm),
          CrDate(CtDateIncm),
          TipeId(TypeIdIncm)
    {}

    int NoteId;
    QString NoteTitle;
    QString NoteType;
    QString NoteText;
    QString EventTime;
    QString EventDate;
    QString CrTime;
    QString CrDate;
    int TipeId; // не работает в базе + потом при M:N вообще не нужен будет
};

class DbManager
{
public:
    DbManager();
    ~DbManager();
    static bool connect(const QString& path);
    static bool addNote(MattyNote & Note);
    static bool editNote(MattyNote & Note, int NoteId);
    static bool deleteNote(int NoteId);
    static QStringList showNote(int NoteId);
    static QVector<QStringList> showNotes();
    static QVector<QStringList> showNotes(QMap<QString, QString> & Filter);
    static QSqlTableModel* getModel(const QString& path); // needtodelete wherever it's called
    static QStringList getTypes();
    static QString getTypeName(int TypeId);
    static int getTypeId(const QString & TypeName);
    static int getNoteCount();
    //static QVector<QStringList> getAllNotesOrderByCrDate();
    static void showIsNotOpenError();
private:
    static QSqlDatabase MattyNotesDb;
    static QString PathToDb;
};

#endif // DBMANAGER_H
