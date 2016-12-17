#include "addnotedialog.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "UtilityFunctions.h"
#include "mattynotesmainwindow.h"
#include "NoteHolder.h"
#include "Constants.h"
#include "QueryConstructor.h"
#include "mattymessagebox.h"

addNoteDialog::addNoteDialog(Action DialogTypeIncm, int EditingNoteIdIncm,
                             QWidget *parent) : QDialog(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_DeleteOnClose); пытается удалить что-то, что уже было удалено

    buildBody();

    noteTypeComboBox->clear();
    noteTypeComboBox->addItems(DbManager::getTypes());

    eventTimeEdit->setTime(QTime::currentTime());
    eventDateEdit->setDate(QDate::currentDate());

    EditingNoteId = EditingNoteIdIncm;

    ThisDialogNote = MattyNote();

    if (EditingNoteIdIncm != -1)
    {
        EditingNoteId = EditingNoteIdIncm;

        ThisDialogNote.constructNote(DbManager::showNote(EditingNoteId));

        noteTitleText->setText(ThisDialogNote.getTitle());
        noteTypeComboBox->setCurrentText(ThisDialogNote.getType());
        noteTextText->setText(ThisDialogNote.getText());
        eventTimeEdit->setTime(QTime::fromString(ThisDialogNote.getEventTime()));
       eventDateEdit->setDate(QDate::fromString(ThisDialogNote.getEventDate()));
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

void addNoteDialog::buildBody()
{
    this->setObjectName(QStringLiteral("addNoteDialog"));
this->resize(539, 525);
gridLayout = new QGridLayout(this);
gridLayout->setSpacing(6);
gridLayout->setContentsMargins(11, 11, 11, 11);
gridLayout->setObjectName(QStringLiteral("gridLayout"));
noteTitleText = new QTextEdit(this);
noteTitleText->setObjectName(QStringLiteral("noteTitleText"));
noteTitleText->setMaximumSize(QSize(16777215, 31));

gridLayout->addWidget(noteTitleText, 0, 0, 1, 1);

horizontalLayout = new QHBoxLayout();
horizontalLayout->setSpacing(6);
horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
horizontalSpacer_5 = new QSpacerItem
        (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

horizontalLayout->addItem(horizontalSpacer_5);

noteTypeComboBox = new QComboBox(this);
noteTypeComboBox->setObjectName(QStringLiteral("noteTypeComboBox"));
noteTypeComboBox->setMinimumSize(QSize(150, 0));

horizontalLayout->addWidget(noteTypeComboBox);

eventTimeEdit = new QTimeEdit(this);
eventTimeEdit->setObjectName(QStringLiteral("eventTimeEdit"));
eventTimeEdit->setCalendarPopup(false);

horizontalLayout->addWidget(eventTimeEdit);

eventDateEdit = new QDateEdit(this);
eventDateEdit->setObjectName(QStringLiteral("eventDateEdit"));
eventDateEdit->setCalendarPopup(true);
eventDateEdit->setDate(QDate(2016, 11, 1));

horizontalLayout->addWidget(eventDateEdit);

horizontalSpacer_2 = new QSpacerItem
        (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

horizontalLayout->addItem(horizontalSpacer_2);


gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

noteTextText = new QTextEdit(this);
noteTextText->setObjectName(QStringLiteral("noteTextText"));
noteTextText->setMaximumSize(QSize(16777215, 16777215));

gridLayout->addWidget(noteTextText, 2, 0, 1, 1);

horizontalLayout_5 = new QHBoxLayout();
horizontalLayout_5->setSpacing(6);
horizontalLayout_5->setObjectName
        (QStringLiteral("horizontalLayout_5"));
cancelAddingNoteButton = new QPushButton(this);
cancelAddingNoteButton->setObjectName
        (QStringLiteral("cancelAddingNoteButton"));

horizontalLayout_5->addWidget(cancelAddingNoteButton);

horizontalSpacer_6 = new QSpacerItem
        (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

horizontalLayout_5->addItem(horizontalSpacer_6);

createNoteButton = new QPushButton(this);
createNoteButton->setObjectName(QStringLiteral("createNoteButton"));

horizontalLayout_5->addWidget(createNoteButton);


gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

QMetaObject::connectSlotsByName(this);
}

void addNoteDialog::on_cancelAddingNoteButton_clicked()
{
    MattyMessageBox NeedToEnterTitle(MessageBoxQuestion);
    NeedToEnterTitle.setText("Вы хотите выйти без сохранения заметки?");
    int answer = NeedToEnterTitle.exec();

    if (answer == QMessageBox::Yes)
    {
        this->close();
    }
}


void addNoteDialog::on_createNoteButton_clicked()
{
    if (noteTitleText->toPlainText() != "")
    {
        ThisDialogNote.setTitle(noteTitleText->toPlainText());
        ThisDialogNote.setType(noteTypeComboBox->currentText());
        ThisDialogNote.setText(noteTextText->toPlainText());
        ThisDialogNote.setEventTime(eventTimeEdit->text());
        ThisDialogNote.setEventDate(eventDateEdit->text());

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
        NeedToEnterTitle.setText("У заметки обязательно должен быть заголовок!");
        NeedToEnterTitle.exec();
        noteTitleText->setFocus();
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

addNoteDialog::~addNoteDialog()
{
}
