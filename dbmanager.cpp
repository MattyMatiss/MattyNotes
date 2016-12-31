#include "dbmanager.h"
#include "queryconstructor.h"

#include <QFile>

QSqlDatabase DbManager::MattyNotesDb;
QString DbManager::PathToDb = "";

DbManager::DbManager()
{

}

bool DbManager::connected()
{
    if (MattyNotesDb.open())
    {
        return true;
    }
    else
    {
        showIsNotOpenedError();
        MattyNotesDb.close();
        return false;
    }
}

bool DbManager::connect(const QString & path)
{
    MattyNotesDb = QSqlDatabase::addDatabase("QSQLITE");
    MattyNotesDb.setDatabaseName(path);

    if(QFile::exists(path))
    {
        if (!MattyNotesDb.open())
        {
            showIsNotOpenedError();
            MattyNotesDb.close();

            return false;
        }
        else
        {
            PathToDb = MattyNotesDb.databaseName();
        }

        return true;
    }
    else
    {
        return false;
    }
}


bool DbManager::addNote(MattyNote & Note)
{
    if (connected())
    {
        QMap<QString, QString> NoteTemp;
        NoteTemp["NoteTitle"] = "\'" + Note.getTitle() + "\'";
        NoteTemp["NoteType"] = "\'" + Note.getType() + "\'";
        NoteTemp["NoteText"] = "\'" + Note.getText() + "\'";
        NoteTemp["EventTime"] = "\'" + Note.getEventTime() + "\'";
        NoteTemp["EventDate"] = "\'" + Note.getEventDate() + "\'";
        NoteTemp["CrTime"] = "\'" + Note.getCrTime() + "\'";
        NoteTemp["CrDate"] = "\'" + Note.getCrDate() + "\'";
        NoteTemp["TypeId"] = QString::number(Note.getTypeId());

        QueryConstructor AddNote;
        AddNote.setTableName(QStringLiteral("Notes"));
        AddNote.setWhatToSetFieldValue(NoteTemp);

        QSqlQuery AddNoteQuery;

        return AddNoteQuery.exec(AddNote.constructInsertQuery());
    }
    else
    {
        return false;
    }
}

bool DbManager::editNote(MattyNote & Note, int NoteId)
{
    if (connected())
    {
        QueryConstructor Edit;
        Edit.setTableName(QStringLiteral("Notes"));

        Edit.addWhereFieldValue(QStringLiteral("NoteId"), QString::number(NoteId));

        QMap<QString, QString> NoteTemp;
        NoteTemp["NoteTitle"] = "\'" + Note.getTitle() + "\'";
        NoteTemp["NoteType"] = "\'" + Note.getType() + "\'";
        NoteTemp["NoteText"] = "\'" + Note.getText() + "\'";
        NoteTemp["EventTime"] = "\'" + Note.getEventTime() + "\'";
        NoteTemp["EventDate"] = "\'" + Note.getEventDate() + "\'";
        NoteTemp["CrTime"] = "\'" + Note.getCrTime() + "\'";
        NoteTemp["CrDate"] = "\'" + Note.getCrDate() + "\'";
        NoteTemp["TypeId"] = QString::number(Note.getTypeId());

        Edit.setWhatToSetFieldValue(NoteTemp); //

        QSqlQuery editNoteQuery;
        return editNoteQuery.exec(Edit.constructUpdateQuery());
    }
    else
    {
        return false;
    }
}

bool DbManager::deleteNote(int NoteId)
{
    if (connected())
    {
        QueryConstructor Delete;
        Delete.setTableName(QStringLiteral("Notes"));
        Delete.addWhereFieldValue(QStringLiteral("NoteId"), QString::number(NoteId));

        QSqlQuery deleteNoteQuery;
        return deleteNoteQuery.exec(Delete.constructDeleteQuery());
    }
    else
    {
        return false;
    }
}

MattyNoteRow DbManager::showNote(int NoteId)
{
    MattyNoteRow Row;

    if (connected())
    {
        QueryConstructor Show;
        Show.setTableName(QStringLiteral("Notes"));
        Show.addWhereFieldValue(QStringLiteral("NoteId"), QString::number(NoteId));

        QSqlQuery showNoteQuery;
        showNoteQuery.exec(Show.constructSelectQuery());
        showNoteQuery.next();

        Row.NoteId=showNoteQuery.value("NoteId").toInt();
        Row.NoteTitle=showNoteQuery.value("NoteTitle").toString();
        Row.NoteType=showNoteQuery.value("NoteType").toString();
        Row.NoteText=showNoteQuery.value("NoteText").toString();
        Row.EventTime=showNoteQuery.value("EventTime").toString();
        Row.EventDate=showNoteQuery.value("EventDate").toString();
        Row.CrTime=showNoteQuery.value("CrTime").toString();
        Row.CrDate=showNoteQuery.value("CrDate").toString();
        Row.TypeId=showNoteQuery.value("TypeId").toInt();
    }

    return Row;
}

QSqlTableModel* DbManager::getModel(const QString & TableName) // needtodelete wherever it's called
{
    if (connected())
    {
        QSqlTableModel* MattyNotesModel = new QSqlTableModel();
        MattyNotesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        MattyNotesModel->setTable(TableName);
        MattyNotesModel->select();
        return MattyNotesModel;
    }

    else
    {
        return new QSqlTableModel();
    }
}

QStringList DbManager::getTypes()
{
    if (connected())
    {
        QStringList NoteTypes;
        QSqlQuery getTypeQuery;

        QueryConstructor GetTypes;
        GetTypes.setTableName(QStringLiteral("NoteTypes"));
        GetTypes.addWhatToSelectFieldName(QStringLiteral("TypeName"));
        GetTypes.setOrderByClause("TypeId");

        if( getTypeQuery.exec(GetTypes.constructSelectQuery()))
        {
            while (getTypeQuery.next())
            {
                NoteTypes << getTypeQuery.value(0).toString();
            }
        }

        else
        {
            QMessageBox::critical(NULL, QObject::tr("Error"), getTypeQuery.lastError().text()); //
        }

        return NoteTypes;

    }
    else
    {
        return QStringList();
    }
}

QString DbManager::getTypeName(int TypeId)
{
    if (connected())
    {
        QString TypeName;
        QSqlQuery getTypeQuery;
        getTypeQuery.prepare("SELECT TypeName FROM NoteTypes WHERE TypeId=:TypeId");
        getTypeQuery.bindValue(":TypeId", TypeId);
        getTypeQuery.exec();
        TypeName = getTypeQuery.value(0).toString();
        return TypeName;
    }
    else
    {
        return QString();
    }
}

int DbManager::getTypeId(const QString & TypeName)
{
    if (connected())
    {
        int TypeId = 0;
        QSqlQuery getTypeQuery;
        getTypeQuery.prepare("SELECT TypeId FROM NoteTypes WHERE TypeName=:TypeName");
        getTypeQuery.bindValue(":TypeName", TypeName);
        getTypeQuery.exec();
        TypeId = getTypeQuery.value(0).toInt();
        return TypeId;
    }
    else
    {
        return 0;
    }
}

int DbManager::getNoteCount()
{
    if (connected())
    {
        int NoteCount = 0;
        QSqlQuery getNoteCount;
        getNoteCount.exec("SELECT Count(*) FROM Notes");
        if (getNoteCount.next())
            NoteCount = getNoteCount.value(0).toInt();
        return NoteCount;
    }
    else
    {
        return 0;
    }
}

QVector<MattyNoteRow> DbManager::showNotes()
{
    if (connected())
    {
        QVector<MattyNoteRow> VectorOfNoteRows;

        QueryConstructor SelectAllNotes;
        SelectAllNotes.setTableName(QStringLiteral("Notes"));
        SelectAllNotes.setOrderByClause("NoteId", Descending);

        QSqlQuery getAllNotesQuery(MattyNotesDb);

        if( getAllNotesQuery.exec(SelectAllNotes.constructSelectQuery()))
        {
            while (getAllNotesQuery.next())
            {
                MattyNoteRow Row;

                Row.NoteId=getAllNotesQuery.value("NoteId").toInt();
                Row.NoteTitle=getAllNotesQuery.value("NoteTitle").toString();
                Row.NoteType=getAllNotesQuery.value("NoteType").toString();
                Row.NoteText=getAllNotesQuery.value("NoteText").toString();
                Row.EventTime=getAllNotesQuery.value("EventTime").toString();
                Row.EventDate=getAllNotesQuery.value("EventDate").toString();
                Row.CrTime=getAllNotesQuery.value("CrTime").toString();
                Row.CrDate=getAllNotesQuery.value("CrDate").toString();
                Row.TypeId=getAllNotesQuery.value("TypeId").toInt();

                VectorOfNoteRows.push_back(Row);
            }
        }
        else
        {
            QMessageBox::critical(NULL, QObject::tr("Error"), getAllNotesQuery.lastError().text());
        }

        return VectorOfNoteRows;
    }
    else
    {
        return QVector<MattyNoteRow>();
    }
}

QVector<MattyNoteRow> DbManager::showNotes(QMap<QString, QString> & Filter)
{
    if (connected())
    {
        QueryConstructor GetNotes;
        GetNotes.setTableName(QStringLiteral("Notes"));
        GetNotes.setWhereFieldValue(Filter);

        QSqlQuery getNotesQuery;

        if (!getNotesQuery.exec())
        {
            QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
        }

        QVector<MattyNoteRow> VectorOfNotes;

        while (getNotesQuery.next())
        {
            MattyNoteRow Row;

            Row.NoteId=getNotesQuery.value("NoteId").toInt();
            Row.NoteTitle=getNotesQuery.value("NoteTitle").toString();
            Row.NoteType=getNotesQuery.value("NoteType").toString();
            Row.NoteText=getNotesQuery.value("NoteText").toString();
            Row.EventTime=getNotesQuery.value("EventTime").toString();
            Row.EventDate=getNotesQuery.value("EventDate").toString();
            Row.CrTime=getNotesQuery.value("CrTime").toString();
            Row.CrDate=getNotesQuery.value("CrDate").toString();
            Row.TypeId=getNotesQuery.value("TypeId").toInt();


            VectorOfNotes.push_back(Row);
        }
        return VectorOfNotes;
    }
    else
    {
        return QVector<MattyNoteRow>();
    }
}

void DbManager::showIsNotOpenedError()
{
    QString DbName = MattyNotesDb.databaseName();

    if (DbName == "")
        QMessageBox::critical(NULL, QObject::tr("Error"), "Internal program error. Database name is not set./n Please, contact developers.");
    else
        QMessageBox::critical(NULL, QObject::tr("Error"), "Database " + DbName + " could not be opened. Please, check whether the file is still there/n" +
                              MattyNotesDb.lastError().text());
}

/*QVector<MattyCssRow> DbManager::getCss(CssTables TableName)
{
    QueryConstructor getCssQuery;
    getCssQuery.setTableName(TableName);
    // тут разбор прилетов всего содержимого таблицы. ПО ИМЕНАМ ПОЛЕЙ, А НЕ НОМЕРАМ
}*/

DbManager::~DbManager()
{
}

