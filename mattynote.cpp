#include "mattynote.h"
#include "constants.h"
#include "dbmanager.h"

MattyNote::MattyNote()
{
    CrTimeAndDate = QDateTime::currentDateTime();
    NoteCrTime = CrTimeAndDate.time().toString().mid(0, 5);
    NoteCrDate = CrTimeAndDate.date().toString("d MMM yyyy, ddd");
}

MattyNote::MattyNote(MattyNoteRow RowFromDb)
{
    NoteId = RowFromDb.NoteId;
    NoteTitle = RowFromDb.NoteTitle;
    NoteType = RowFromDb.NoteType;
    NoteText = RowFromDb.NoteText;
    setEventTime(RowFromDb.EventTime);
    setEventDate(RowFromDb.EventDate);
    NoteCrTime = RowFromDb.CrTime;
    NoteCrDate = RowFromDb.CrDate;
    NoteTypeId = RowFromDb.TypeId;
}

MattyNote::~MattyNote()
{
}

void MattyNote::constructNote(MattyNoteRow RowFromDb)
{
    NoteId = RowFromDb.NoteId;
    NoteTitle = RowFromDb.NoteTitle;
    NoteType = RowFromDb.NoteType;
    NoteText = RowFromDb.NoteText;
    setEventTime(RowFromDb.EventTime);
    setEventDate(RowFromDb.EventDate);
    NoteCrTime = RowFromDb.CrTime;
    NoteCrDate = RowFromDb.CrDate;
    NoteTypeId = RowFromDb.TypeId;
}

void MattyNote::setTitle(const QString & Title)
{
    NoteTitle = Title;
}

void MattyNote::setType(const QString & TypeName)
{
    NoteTypeId = DbManager::getTypeId(TypeName);
    NoteType = TypeName;
}

void MattyNote::setType(int TypeId)
{
    NoteType = DbManager::getTypeName(TypeId);
    NoteTypeId = TypeId;
}

void MattyNote::setText(const QString & Text)
{
    NoteText = Text;
}

void MattyNote::setEventTime(const QString & EventTime)
{
    NoteEventTime = EventTime;
    EventTimeAndDate.setTime(QTime::fromString(EventTime));
}

void MattyNote::setEventDate(const QString & EventDate)
{
    NoteEventDate = EventDate;
    EventTimeAndDate.setDate(QDate::fromString(EventDate));
}

QString MattyNote::getTitle() const
{
    return NoteTitle;
}

QString MattyNote::getType() const
{
    return NoteType;
}

int MattyNote::getTypeId() const
{
    return NoteTypeId;
}

QString MattyNote::getText() const
{
    return NoteText;
}

QString MattyNote::getEventTime() const
{
    return NoteEventTime;
}

QString MattyNote::getEventDate() const
{
    return NoteEventDate;
}

QString MattyNote::getCrTime() const
{
    return NoteCrTime;
}

QString MattyNote::getCrDate() const
{
    return NoteCrDate;
}

int MattyNote::getNoteId() const
{
    return NoteId;
}

QDateTime  MattyNote::getEventTimeAndDate() const
{
    return EventTimeAndDate;
}

QDateTime  MattyNote::getCrTimeAndDate() const
{
    return CrTimeAndDate;
}
