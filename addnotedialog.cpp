#include "addnotedialog.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "UtilityFunctions.h"
#include "mattynotesmainwindow.h"
#include "NoteHolder.h"
#include "Constants.h"
#include "QueryConstructor.h"
#include "mattymessagebox.h"

addNoteDialog::addNoteDialog(Action DialogTypeIncm, int EditingNoteIdIncm)
{
    addNoteDialogUi.setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_DeleteOnClose); пытается удалить что-то, что уже было удалено

    addNoteDialogUi.noteTypeComboBox->clear();
    addNoteDialogUi.noteTypeComboBox->addItems(DbManager::getTypes());

    addNoteDialogUi.eventTimeEdit->setTime(QTime::currentTime());
    addNoteDialogUi.eventDateEdit->setDate(QDate::currentDate());

    EditingNoteId = EditingNoteIdIncm;

    ThisDialogNote = MattyNote();

    if (EditingNoteIdIncm != -1)
    {
        EditingNoteId = EditingNoteIdIncm;

        ThisDialogNote.constructNote(DbManager::showNote(EditingNoteId));

        addNoteDialogUi.noteTitleText->setText(ThisDialogNote.getTitle());
        addNoteDialogUi.noteTypeComboBox->setCurrentText(ThisDialogNote.getType());
        addNoteDialogUi.noteTextText->setText(ThisDialogNote.getText());
        addNoteDialogUi.eventTimeEdit->setTime(QTime::fromString(ThisDialogNote.getEventTime()));
        addNoteDialogUi.eventDateEdit->setDate(QDate::fromString(ThisDialogNote.getEventDate()));
    }
    else
    {
    }

    DialogType = DialogTypeIncm;

    SaveNote = new QAction(this);
    SaveNote->setShortcut(tr("CTRL+RETURN"));
    this->addAction(SaveNote);
    QObject::connect(SaveNote, SIGNAL(triggered()), this, SLOT(on_createNoteButton_clicked()));
}

addNoteDialog::~addNoteDialog()
{
}

void addNoteDialog::on_cancelAddingNoteButton_clicked()
{
    MattyMessageBox NeedToEnterTitle(MessageBoxQuestion);
    NeedToEnterTitle.setText(QString::fromLocal8Bit("Вы хотите выйти без сохранения заметки?"));
    int answer = NeedToEnterTitle.exec();

    if (answer == QMessageBox::Yes)
    {
        this->close();
    }
}


void addNoteDialog::on_createNoteButton_clicked()
{
    if (addNoteDialogUi.noteTitleText->toPlainText() != "")
    {
        ThisDialogNote.setTitle(addNoteDialogUi.noteTitleText->toPlainText());
        ThisDialogNote.setType(addNoteDialogUi.noteTypeComboBox->currentText());
        ThisDialogNote.setText(addNoteDialogUi.noteTextText->toPlainText());
        ThisDialogNote.setEventTime(addNoteDialogUi.eventTimeEdit->text());
        ThisDialogNote.setEventDate(addNoteDialogUi.eventDateEdit->text());

        if (DialogType == Add)
        {
            DbManager::addNote(ThisDialogNote);
        }

        if (DialogType == Edit)
        {
            if (EditingNoteId != -1)
            {
                DbManager::editNote(ThisDialogNote, EditingNoteId);
            }
        }
        this->close();
    }
    else
    {
        MattyMessageBox NeedToEnterTitle(MessageBoxInformation);
        NeedToEnterTitle.setText(QString::fromLocal8Bit("У заметки обязательно должен быть заголовок!"));
        NeedToEnterTitle.exec();
        addNoteDialogUi.noteTitleText->setFocus();
    }
}

void addNoteDialog::mousePressEvent(QMouseEvent *event)
{
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void addNoteDialog::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}
