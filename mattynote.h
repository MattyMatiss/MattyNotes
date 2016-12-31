
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
    MattyNote(struct MattyNoteRow RowFromDb);

    ~MattyNote();

    void constructNote(struct MattyNoteRow RowFromDb);

    void setTitle(const QString & Title);
    void setType(const QString & TypeName);
    void setType(int TypeId);
    void setText(const QString & Text);
    void setEventTime(const QString & EventTime);
    void setEventDate(const QString & EventDate);
    QString getTitle() const;
    QString getType() const;
    QString getText() const;
    QString getEventTime() const;
    QString getEventDate() const;
    QString getCrTime() const;
    QString getCrDate() const;
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
    QString NoteEventTime;
    QString NoteEventDate;
    QString NoteEvDayOfWeek;
    QString NoteCrTime;
    QString NoteCrDate;
    QString NoteCrDayOfWeek;
    QDateTime EventTimeAndDate;
    QDateTime CrTimeAndDate;  // Autoset in the constructor of MattyNote
};

#endif // MATTYNOTE_H
