#include "noteholder.h"
#include "mattygroupbox.h"
#include "mattynote.h"
#include "dbmanager.h"
#include "constants.h"

int NoteHolder::TotalNoteCount = 0;
QVector<class MattyNote> NoteHolder::ListOfAllNotes = QVector<class MattyNote>();

NoteHolder::NoteHolder()
{
}


NoteHolder::~NoteHolder()
{
}

void NoteHolder::sortNotesByCrDate()
{
}

void NoteHolder::publishNotes(QWidget* ParentWidget)
{
    erasePublishedNotes(ParentWidget);

    getAllNotes();

    QVector<class MattyNote>::iterator NoteNumber;
    int i;
    for (NoteNumber = ListOfAllNotes.begin(), i=0; NoteNumber < ListOfAllNotes.end();NoteNumber++, i++)
    {

        MattyGroupBox* MyGroupBox = new MattyGroupBox(*NoteNumber, ParentWidget);
        //MyGroupBox->fillFrame(*NoteNumber);
        ParentWidget->layout()->addWidget(MyGroupBox);
    }
}

void NoteHolder::setFilters()
{
}

void NoteHolder::getAllNotes()
{
    TotalNoteCount = 0;

    if (!ListOfAllNotes.isEmpty())
        ListOfAllNotes.clear();

    QVector<QStringList> ListOfRows = DbManager::showNotes();

    for (int i = 0; i < ListOfRows.length();i++)
    {
        MattyNote TempNote(ListOfRows[i]);
        ListOfAllNotes.append(TempNote);
        TotalNoteCount++;
    }
}

void NoteHolder::getSelectedNotes() // пока не отичается от getAllNotes()
{
    TotalNoteCount = 0;

    QMap<QString, QString> Filter; // это потом заменить на метод, обрабатывающий запросы пользователя на сортировку

    QVector<QStringList> ListOfRows = DbManager::showNotes(Filter);

    if (!ListOfAllNotes.isEmpty())
        ListOfAllNotes.clear();

    for (int i = 0; i < ListOfRows.length();i++)
    {
        MattyNote TempNote(ListOfRows[i]);
        ListOfAllNotes.append(TempNote);
        TotalNoteCount++;
    }
}

void NoteHolder::erasePublishedNotes(QWidget* ParentWidget)
{
    MattyGroupBox* MgbTemp;
    while ((MgbTemp = ParentWidget->findChild<MattyGroupBox*>()) != 0)
    {
        delete MgbTemp;
    }

    QGroupBox* GbTemp;
    while ((GbTemp = ParentWidget->findChild<QGroupBox*>()) != 0)
    {
        delete GbTemp;
    }
}

