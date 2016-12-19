#include "mattynotesmainwindow.h"
#include "dbmanager.h"
#include "mattynote.h"
#include "addnotedialog.h"
#include "mattygroupbox.h"
#include "noteholder.h"
#include "constants.h"
#include "mattyclocks.h"
#include "mattysettingsdialog.h"
#include "mattystylesheeteditor.h"
#include "mattymessagebox.h"

MattyNotesMainWindow::MattyNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setContextMenuPolicy(Qt::NoContextMenu);

    connectToDb();

    buildBody();

    buildMainToolBar();

    buildMattyToolBar();

    setActions();

    setConnects();

    refreshMainWindow();
}

void MattyNotesMainWindow::addNote()
{
    addNoteDialog newAddNoteDialog(Add);

    if (!newAddNoteDialog.exec())
    {
        NoteHolder::publishNotes(GroupBoxScrollAreaWidgetContents);
    }
}

void MattyNotesMainWindow::closeWindow()
{
    QApplication::quit();
}

void MattyNotesMainWindow::maximizeWindow()
{
    if (this->isMaximized())
        this->showNormal();
    else
        this->showMaximized();
}

void MattyNotesMainWindow::minimizeWindow()
{
    this->showMinimized();
}

void MattyNotesMainWindow::refreshMainWindow()
{
    MattyStyleSheetEditor::refreshTheme();
    NoteHolder::publishNotes(GroupBoxScrollAreaWidgetContents);
}

void MattyNotesMainWindow::openSettings()
{
    MattySettingsDialog newMattySettingsDialog;
    newMattySettingsDialog.setWindowModality(Qt::ApplicationModal);
    newMattySettingsDialog.exec();
}

void MattyNotesMainWindow::resizeMattyToolbarButtons()
{
    if (MattyToolBar->orientation() == Qt::Vertical)
    {
        AddNoteButton->setFixedSize(QSize(70, 51));
        RefreshNoteListButton->setFixedSize(QSize(70, 51));
        SettingsButton->setFixedSize(QSize(51, 51));
    }
    else
    {
        AddNoteButton->setFixedSize(QSize(51, 51));
        RefreshNoteListButton->setFixedSize(QSize(51, 51));
        SettingsButton->setFixedSize(QSize(51, 51));
    }
}

void MattyNotesMainWindow::mousePressEvent(QMouseEvent *event)
{
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MattyNotesMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

void MattyNotesMainWindow::connectToDb(const QString & PathToDb)
{
    if (PathToDb == "")
    {
        Constants::setPathToDb(RelativeREXE);

        if(!DbManager::connect(Constants::getPathTODb()))
        {
            Constants::setPathToDb(RelativeDEXE);

            if(!DbManager::connect(Constants::getPathTODb()))
            {
                Constants::setPathToDb(RelativeR);

                if(!DbManager::connect(Constants::getPathTODb()))
                {
                    Constants::setPathToDb(RelativeD);

                    if(!DbManager::connect(Constants::getPathTODb()))
                    {
                       MattyMessageBox DbNotFound(MessageBoxWarning);
                       DbNotFound.setText("База данных не найдена");
                    }
                }
            }
        }
    }

    else
    {
        Constants::setPathToDb(PathToDb);
        DbManager::connect(Constants::getPathTODb());
    }
}

void MattyNotesMainWindow::buildBody()
{
    this->setObjectName(QStringLiteral("MattyNotesMainWindowClass"));
    this->resize(768, 553);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    this->setCentralWidget(centralWidget);

    QMetaObject::connectSlotsByName(this);

    MainGridLayout = new QGridLayout(centralWidget);
    MainGridLayout->setSpacing(6);
    //gridLayout_4->setContentsMargins(11, 11, 11, 11);
    MainGridLayout->setObjectName(QStringLiteral("gridLayout_4"));

    MainSplitter = new QSplitter(centralWidget);
    MainSplitter->setObjectName(QStringLiteral("splitter"));
    MainSplitter->setOrientation(Qt::Horizontal);

    LeftSideWidget = new QWidget(MainSplitter);
    LeftGridLayout = new QGridLayout;
    LeftSideWidget->setLayout(LeftGridLayout);
    MainSplitter->addWidget(LeftSideWidget);
    LeftSideWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    LeftSideWidget->setObjectName(QStringLiteral("LeftSide"));

    RightSideWidget = new QWidget(MainSplitter);
    RightGridLayout = new QGridLayout;
    RightSideWidget->setLayout(RightGridLayout);
    MainSplitter->addWidget(RightSideWidget);
    RightSideWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    RightSideWidget->setObjectName(QStringLiteral("RightSide"));

    LeftSideVerLayout = new QVBoxLayout();
    LeftSideVerLayout->setSpacing(6);

    LeftGridLayout->addLayout(LeftSideVerLayout, 0, 0);

    MotivatorLabel = new QLabel(LeftSideWidget);
    MotivatorLabel->setText(QString::fromUtf8("Желания имеют свойство сбываться"));
    MotivatorLabel->setObjectName(QStringLiteral("MotivatorLabel"));
    MotivatorLabel->setMinimumSize(QSize(250, 0));
    MotivatorLabel->setMaximumSize(QSize(250, 16777215));
    MotivatorLabel->setWordWrap(true);
    MotivatorLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    LeftSideVerticalSpacer = new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

    LeftSideVerLayout->addWidget(MotivatorLabel);
    LeftSideVerLayout->addItem(LeftSideVerticalSpacer);

    LeftSideHorizontalSpacer = new QSpacerItem(10, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

    LeftGridLayout->addItem(LeftSideHorizontalSpacer, 1, 0);

    GroupBoxScrollArea = new QScrollArea(RightSideWidget);
    GroupBoxScrollArea->setObjectName(QStringLiteral("scrollArea"));
    GroupBoxScrollArea->setWidgetResizable(true);
    GroupBoxScrollAreaWidgetContents = new QWidget(GroupBoxScrollArea);
    GroupBoxScrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
    GroupBoxScrollAreaWidgetContents->setGeometry(QRect(0, 0, 426, 480));
    GroupBoxHolderLayout = new QGridLayout(GroupBoxScrollAreaWidgetContents);
    GroupBoxHolderLayout->setSpacing(6);
    GroupBoxHolderLayout->setContentsMargins(11, 11, 11, 11);
    GroupBoxHolderLayout->setObjectName(QStringLiteral("gridLayout_2"));
    GroupBoxScrollArea->setWidget(GroupBoxScrollAreaWidgetContents);

    NoteOptionsWidget = new QWidget(GroupBoxScrollArea);
    NoteOptionsWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    NoteOptionsWidget->setObjectName(QStringLiteral("NoteOptionsWidget"));
    RightGridLayout->addWidget(NoteOptionsWidget);
    RightGridLayout->addWidget(GroupBoxScrollArea);

    opacity = new QGraphicsOpacityEffect(NoteOptionsWidget);
    NoteOptionsWidget->setGraphicsEffect(opacity);
    NoteOptionsWidget->setAutoFillBackground(true);

    MainGridLayout->addWidget(MainSplitter, 0, 0, 1, 1);

    menuBar = new QMenuBar(this);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 768, 21));
    this->setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    this->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    statusBar->setMinimumSize(QSize(0, 0));
    this->setStatusBar(statusBar);

    MainSplitter->setStretchFactor(1, 1);
    MainSplitter->setStretchFactor(2, 3);

}

void MattyNotesMainWindow::buildMainToolBar()
{
    CloseWindowButton = new QPushButton(mainToolBar);
    CloseWindowButton->setObjectName("CloseWindowButton");
    CloseWindowButton->setMaximumSize(QSize(20, 20));
    CloseWindowButton->setFlat(true);

    MaximizeWindowButton = new QPushButton(mainToolBar);
    MaximizeWindowButton->setObjectName("MaximizeWindowButton");
    MaximizeWindowButton->setMaximumSize(QSize(20, 20));
    MaximizeWindowButton->setFlat(true);

    MinimizeWindowButton = new QPushButton(mainToolBar);
    MinimizeWindowButton->setObjectName("MinimizeWindowButton");
    MinimizeWindowButton->setMaximumSize(QSize(20, 20));
    MinimizeWindowButton->setFlat(true);

    MainToolBarSpacerLeft = new QWidget(mainToolBar);
    MainToolBarSpacerLeft->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    MainToolBarSpacerRight = new QWidget(mainToolBar);
    MainToolBarSpacerRight->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    WindowHeaderLabel = new QLabel(mainToolBar);
    WindowHeaderLabel->setObjectName(QStringLiteral("WindowHeaderLabel"));
    WindowHeaderLabel->setText("MattyNotes");

    mainToolBar->setObjectName(QStringLiteral("MainToolBar"));
    mainToolBar->addWidget(MainToolBarSpacerLeft);
    mainToolBar->addWidget(WindowHeaderLabel);
    mainToolBar->addWidget(MainToolBarSpacerRight);
    mainToolBar->addWidget(MinimizeWindowButton);
    mainToolBar->addWidget(MaximizeWindowButton);
    mainToolBar->addWidget(CloseWindowButton);
    mainToolBar->setMovable(false);
}

void MattyNotesMainWindow::buildMattyToolBar()
{
    MattyToolBar = new QToolBar(this);
    MattyToolBar->setObjectName(QStringLiteral("MattyToolBar"));
    MattyToolBar->setFloatable(false);
    this->addToolBar(Qt::BottomToolBarArea, MattyToolBar);
    Qt::ToolBarAreas MattyToolBarAreas;
    MattyToolBarAreas.setFlag(Qt::BottomToolBarArea);
    MattyToolBarAreas.setFlag(Qt::LeftToolBarArea);
    MattyToolBarAreas.setFlag(Qt::RightToolBarArea);
    MattyToolBarAreas.setFlag(Qt::TopToolBarArea);
    MattyToolBar->setAllowedAreas(MattyToolBarAreas);
    opacity = new QGraphicsOpacityEffect(MattyToolBar);
    opacity->setOpacity(0.50); // #0 to 1 will cause the fade effect to kick in
    MattyToolBar->setGraphicsEffect(opacity);
    MattyToolBar->setAutoFillBackground(true);

    AddNoteButton = new QPushButton(this->MattyToolBar);
    AddNoteButton->setObjectName(QStringLiteral("AddNoteButton"));
    AddNoteButton->setFixedSize(QSize(51, 51));

    RefreshNoteListButton = new QPushButton(this->MattyToolBar);
    RefreshNoteListButton->setObjectName(QStringLiteral("RefreshNoteListButton"));
    RefreshNoteListButton->setFixedSize(QSize(51, 51));

    SettingsButton = new QPushButton(this->MattyToolBar);
    SettingsButton->setObjectName(QStringLiteral("SettingsButton"));
    SettingsButton->setFixedSize(QSize(51, 51));

    MainClocks = new MattyClocks(this->MattyToolBar);
    MattyToolBar->addWidget(MainClocks);

    MattyToolBarMainSpacer = new QWidget(this->MattyToolBar);
    MattyToolBarMainSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    MattyToolBar->addWidget(SettingsButton);
    MattyToolBar->addWidget(MattyToolBarMainSpacer);
    MattyToolBar->addWidget(RefreshNoteListButton);
    MattyToolBar->addWidget(AddNoteButton);
}


void MattyNotesMainWindow::setActions()
{
    closeMainWindow = new QAction(this);
    closeMainWindow->setShortcut(tr("CTRL+Q"));
    this->addAction(closeMainWindow);

    addNewNote = new QAction(this);
    addNewNote->setShortcut(tr("ALT+N"));
    this->addAction(addNewNote);

    RefreshMainWindow = new QAction(this);
    RefreshMainWindow->setShortcut(tr("F5"));
    this->addAction(RefreshMainWindow);
}

inline void MattyNotesMainWindow::setConnects()
{
    QObject::connect(CloseWindowButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
    QObject::connect(MaximizeWindowButton, SIGNAL(clicked()), this,	SLOT(maximizeWindow()));
    QObject::connect(MinimizeWindowButton, SIGNAL(clicked()), this, SLOT(minimizeWindow()));
    QObject::connect(AddNoteButton, SIGNAL(clicked()), this, SLOT(addNote()));
    QObject::connect(RefreshNoteListButton, SIGNAL(clicked()), this, SLOT(refreshMainWindow()));
    QObject::connect(SettingsButton, SIGNAL(clicked()), this, SLOT(openSettings()));
    QObject::connect(closeMainWindow, SIGNAL(triggered()), this, SLOT(close()));
    QObject::connect(addNewNote, SIGNAL(triggered()), this, SLOT(addNote()));
    QObject::connect(RefreshMainWindow, SIGNAL(triggered()), this, SLOT(refreshMainWindow()));
    //QObject::connect(MattyToolBar, SIGNAL(orientationChanged()), this, SLOT(resizeMattyToolbarButtons()));
}

bool MattyNotesMainWindow::WindowActivatedEvent(QEvent *e)
{
    if (e->type() == QEvent::WindowActivate)
    {
        refreshMainWindow();
    }
    return QWidget::event(e);
}

MattyNotesMainWindow::~MattyNotesMainWindow()
{

}
