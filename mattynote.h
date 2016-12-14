
#ifndef MATTYNOTE_H
#define MATTYNOTE_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QDateTime>

class MattyNote
{
public:
    MattyNote();
    MattyNote(QStringList RowFromDb);

    ~MattyNote();

    void constructNote(QStringList RowFromDb);

    void setTitle(const QString & Title);
    void setType(const QString & TypeName);
    void setType(int TypeId);
    void setText(const QString & Text);
    void setEventTime(const QString & EventTime); // Warning! Input format must be:
    void setEventDate(const QString & EventDate); // Warning! Input format must be:

    QString getTitle() const;
    QString getType() const;
    QString getText() const;
    QString getEventTime() const; // Format:
    QString getEventDate() const; // Format:
    //QString getEvDayofWeek();
    QString getCrTime() const; // Format:
    QString getCrDate() const; // Format:
    //QString getCrDayOfWeek();
    int getTypeId() const;
    int getNoteId() const;
    QDateTime getEventTimeAndDate() const;
    QDateTime getCrTimeAndDate() const;
private:
    int NoteId;
    int NoteTypeId;
    QString NoteTitle;
    QString NoteType;
    QString NoteText;
    QString NoteEventTime; // Format:
    QString NoteEventDate; // Format:
    QString NoteEvDayOfWeek;
    QString NoteCrTime;
    QString NoteCrDate;
    QString NoteCrDayOfWeek;
    QDateTime EventTimeAndDate;
    QDateTime CrTimeAndDate;  // Automaticly set in constructor of MattyNote
};

#endif // MATTYNOTE_H
