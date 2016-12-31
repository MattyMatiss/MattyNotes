#include "mattygroupbox.h"
#include "mattynote.h"
#include "dbmanager.h"
#include "addnotedialog.h"
#include "mattymessagebox.h"
#include "noteholder.h"
#include "mattynotesmainwindow.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

MattyGroupBox::MattyGroupBox(const class MattyNote & ThisNote, QWidget* parent)
    : QGroupBox(parent)
{
    this->setParent(parent);
    buildFrame();
    fillFrame(ThisNote);
    QObject::connect(deleteNoteButton, SIGNAL(clicked()), this, SLOT(deleteNote()));
    QObject::connect(editNoteButton, SIGNAL(clicked()), this, SLOT(editNote()));
}

void MattyGroupBox::fillFrame(const MattyNote & ThisNote)
{
    ThisGroupBoxNote = ThisNote;

    QString TitleTemp = ThisNote.getTitle();

    if (TitleTemp.length() > 40)
    {
        this->setTitle(TitleTemp.left(40) + "...");
    }
    else
    {
        this->setTitle(TitleTemp.left(40));
    }

    this->setStatusTip(TitleTemp);

    NoteTypeLabel->setText(ThisNote.getType());
    NoteTextLabel->setText(ThisNote.getText());
    NoteCrTimeAndDateLabel->setText("Заметка создана: "
        + ThisNote.getCrDate() + " " + ThisNote.getCrTime() );
    NoteEventTimeAndDateLabel->setText(ThisNote.getEventDate() +  " " + ThisNote.getEventTime());
}


MattyGroupBox::~MattyGroupBox()
{
}

void MattyGroupBox::hideNote()
{
    NoteTextLabel->hide();
    this->setMaximumHeight(150);
}

void MattyGroupBox::expandNote()
{
    NoteTextLabel->show();
    this->setMaximumHeight(16777215);
}

void MattyGroupBox::changeExpandHideMode()
{
    if (NoteTextLabel->isHidden())
    {
        NoteTextLabel->show();
        this->setMaximumHeight(16777215);
    }
    else
    {
        NoteTextLabel->hide();
        this->setMaximumHeight(150);
    }
}

void MattyGroupBox::buildFrame()
{
    this->setMinimumHeight(150);
    this->setObjectName(QStringLiteral("MattyGroupBox"));

    gridLayout = new QGridLayout(this);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

    horizontalLayout_1 = new QHBoxLayout();
    horizontalLayout_2 = new QHBoxLayout();

    horizontalLayout_1->setSpacing(6);
    horizontalLayout_1->setObjectName(QStringLiteral("HorizontalLayout_1"));

    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QStringLiteral("HorizontalLayout_2"));

    verticalLayout->addLayout(horizontalLayout_1);
    verticalLayout->addLayout(horizontalLayout_2);

    horizontalLineWidget = new QWidget(this);
    horizontalLineWidget->setFixedHeight(2);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setObjectName(QStringLiteral("horizontalLineWidget"));
    verticalLayout->addWidget(horizontalLineWidget);

    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

    NoteTypeLabel = new QLabel(this);
    NoteTypeLabel->setObjectName(QStringLiteral("NoteTypeLabel"));
    NoteTypeLabel->setText("Тип");
    NoteTypeLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    NoteCrTimeAndDateLabel = new QLabel(this);
    NoteCrTimeAndDateLabel->setObjectName(QStringLiteral("NoteCrTimeAndDateLabel"));
    NoteCrTimeAndDateLabel->setText("Создано: ");
    NoteCrTimeAndDateLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    editNoteButton = new QPushButton(this);
    editNoteButton->setObjectName(QStringLiteral("editNoteButton"));
    editNoteButton->setSizePolicy(sizePolicy);
    editNoteButton->setMaximumSize(QSize(21, 21));
    editNoteButton->setFlat(true);

    deleteNoteButton = new QPushButton(this);
    deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
    deleteNoteButton->setSizePolicy(sizePolicy);
    deleteNoteButton->setMaximumSize(QSize(21, 21));
    deleteNoteButton->setFlat(true);

    NoteEventTimeAndDateLabel = new QLabel(this);
    NoteEventTimeAndDateLabel->setObjectName(QStringLiteral("NoteEventTimeAndDateLabel"));
    NoteEventTimeAndDateLabel->setText("Когда");
    NoteEventTimeAndDateLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    horizontalLayout_1->addWidget(NoteTypeLabel);
    horizontalLayout_1->addWidget(NoteEventTimeAndDateLabel);
    horizontalLayout_1->addItem(horizontalSpacer_1);
    horizontalLayout_1->addWidget(editNoteButton);
    horizontalLayout_1->addWidget(deleteNoteButton);

    horizontalLayout_2->addWidget(NoteCrTimeAndDateLabel);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer_2);

    NoteTextLabel = new QLabel(this);
    NoteTextLabel->setObjectName(QStringLiteral("NoteTextLabel"));
    NoteTextLabel->setMinimumSize(QSize(0, 100));
    NoteTextLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    verticalLayout->addWidget(NoteTextLabel);
    NoteTextLabel->setText("Текст");
    NoteTextLabel->setWordWrap(true);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);

    QGraphicsDropShadowEffect* GroupBoxShadow = new QGraphicsDropShadowEffect(this);
    GroupBoxShadow->setBlurRadius(25.0);
    QColor ShadowColor = QColor(77, 63, 61, 200);
    GroupBoxShadow->setColor(ShadowColor);
    GroupBoxShadow->setOffset(15, 15);
    this->setGraphicsEffect(GroupBoxShadow);
}

void MattyGroupBox::editNote()
{
    addNoteDialog newAddNoteDialog(Edit, ThisGroupBoxNote.getNoteId());
    newAddNoteDialog.setWindowModality(Qt::ApplicationModal);
    if (!newAddNoteDialog.exec())
    {
        ThisGroupBoxNote.constructNote(DbManager::showNote(ThisGroupBoxNote.getNoteId()));
        fillFrame(ThisGroupBoxNote);
    } // эта обновляшка работает. UPD: блин. не всегда
    // обновляшка не работает почему-то (та, которая срабатывает при возвращении фокуса к главному окну)
}

void MattyGroupBox::deleteNote()
{
    MattyMessageBox WantToDeleteNote(MessageBoxQuestion);
    WantToDeleteNote.setText("\n\nВы точно хотите удалить заметку \n\"" + ThisGroupBoxNote.getTitle() + "\"?");

    int answer = WantToDeleteNote.exec();
    if (answer == QMessageBox::Yes)
    {
        DbManager::deleteNote(ThisGroupBoxNote.getNoteId());
        this->~MattyGroupBox();
    }
}

void MattyGroupBox::mouseDoubleClickEvent(QMouseEvent * e)
{
    if (e->button() == Qt::LeftButton)
    {
        addNoteDialog newAddNoteDialog(Edit, ThisGroupBoxNote.getNoteId());
        newAddNoteDialog.setWindowModality(Qt::ApplicationModal);
        newAddNoteDialog.exec();
    }
}
