#include "DbManager.h"
#include "QueryConstructor.h"

#include <QFile>

QSqlDatabase DbManager::MattyNotesDb;
QString DbManager::PathToDb = "";

DbManager::DbManager()
{

}

bool DbManager::connect(const QString & path)
{
    MattyNotesDb = QSqlDatabase::addDatabase("QSQLITE");
    MattyNotesDb.setDatabaseName(path);

    if(QFile::exists(path))
    {
        if (!MattyNotesDb.open())
        {
            QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
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
    if (MattyNotesDb.isOpen())
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
        showIsNotOpenError();
        return false;
    }
}

bool DbManager::editNote(MattyNote & Note, int NoteId)
{
    if (MattyNotesDb.isOpen())
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
        showIsNotOpenError();
        return false;
    }
}

bool DbManager::deleteNote(int NoteId)
{
    if (MattyNotesDb.isOpen())
    {
        QueryConstructor Delete;
        Delete.setTableName(QStringLiteral("Notes"));
        Delete.addWhereFieldValue(QStringLiteral("NoteId"), QString::number(NoteId));

        QSqlQuery deleteNoteQuery;
        return deleteNoteQuery.exec(Delete.constructDeleteQuery());
    }
    else
    {
        showIsNotOpenError();
        return false;
    }
}

QStringList DbManager::showNote(int NoteId)
{
    if (MattyNotesDb.isOpen())
    {
        QueryConstructor Show;
        Show.setTableName(QStringLiteral("Notes"));
        Show.addWhereFieldValue(QStringLiteral("NoteId"), QString::number(NoteId));

        QSqlQuery showNoteQuery;
        showNoteQuery.exec(Show.constructSelectQuery());
        showNoteQuery.next();

        QStringList Fields;

        for (int i = 0;i < 9;i++)
        {
            Fields.push_back(showNoteQuery.value(i).toString());
        }

        return Fields;
    }
    else
    {
        showIsNotOpenError();
        return QStringList();
    }
}

QSqlTableModel* DbManager::getModel(const QString & TableName) // needtodelete wherever it's called
{
    if (MattyNotesDb.isOpen())
    {
        QSqlTableModel* MattyNotesModel = new QSqlTableModel();
        MattyNotesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        MattyNotesModel->setTable(TableName);
        MattyNotesModel->select();
        return MattyNotesModel;
    }

    else
    {
        showIsNotOpenError();
        return new QSqlTableModel();
    }
}

QStringList DbManager::getTypes()
{
    if (MattyNotesDb.isOpen())
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
        showIsNotOpenError();
        return QStringList();
    }
}

QString DbManager::getTypeName(int TypeId)
{
    if (MattyNotesDb.isOpen())
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
        showIsNotOpenError();
        return QString();
    }
}

int DbManager::getTypeId(const QString & TypeName)
{
    if (MattyNotesDb.isOpen())
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
        showIsNotOpenError();
        return 0;
    }
}

int DbManager::getNoteCount()
{
    if (MattyNotesDb.isOpen())
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
        showIsNotOpenError();
        return 0;
    }
}

QVector<QStringList> DbManager::showNotes()
{
    if (MattyNotesDb.isOpen())
    {
        QVector<QStringList> VectorOfNotes;

        QueryConstructor SelectAll;
        SelectAll.setTableName(QStringLiteral("Notes"));
        SelectAll.setOrderByClause("NoteId", Descending);

        QSqlQuery getNotesQuery(MattyNotesDb);

        if( getNotesQuery.exec(SelectAll.constructSelectQuery())) // возвращает false
        {
            while (getNotesQuery.next()) // соответственно тоже возвращает false
            {
                QStringList Fields;
                for (int i = 0;i < 9;i++)
                {
                    Fields.push_back(getNotesQuery.value(i).toString());
                }
                VectorOfNotes.push_back(Fields);
            }
        }
        else
        {
            QMessageBox::critical(NULL, QObject::tr("Error"), getNotesQuery.lastError().text()); // no such table. Unable to execute statement
        }

        return VectorOfNotes;
    }
    else
    {
        showIsNotOpenError();
        return QVector<QStringList>();
    }
}

QVector<QStringList> DbManager::showNotes(QMap<QString, QString> & Filter)
{
    if (MattyNotesDb.isOpen())
    {
        QueryConstructor GetNotes;
        GetNotes.setTableName(QStringLiteral("Notes"));
        GetNotes.setWhereFieldValue(Filter);

        QSqlQuery getNotesQuery;

        if (!getNotesQuery.exec())
        {
            QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
        }

        QVector<QStringList> VectorOfNotes;

        while (getNotesQuery.next())
        {
            QStringList Fields;
            for (int i = 0;i < 9;i++)
            {
                Fields.push_back(getNotesQuery.value(i).toString());
            }
            VectorOfNotes.push_back(Fields);
        }
        return VectorOfNotes;
    }
    else
    {
        showIsNotOpenError();
        return QVector<QStringList>();
    }
}

void DbManager::showIsNotOpenError()
{
    QString DbName = MattyNotesDb.databaseName();

    if (DbName == "")
        QMessageBox::critical(NULL, QObject::tr("Error"), "Internal code error. Database name is not set.");
    else
        QMessageBox::critical(NULL, QObject::tr("Error"), "Database " + DbName + " could not be opened. Please, check whether the file is still there");
}

DbManager::~DbManager()
{
}

