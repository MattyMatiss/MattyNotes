#ifndef MATTYNOTES_H
#define MATTYNOTES_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QtWidgets>

QT_BEGIN_NAMESPACE

class Ui_MattyNotesMainWindowClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *MattyNotesMainWindowClass)
    {
        if (MattyNotesMainWindowClass->objectName().isEmpty())
            MattyNotesMainWindowClass->setObjectName(QStringLiteral("MattyNotesMainWindowClass"));
        MattyNotesMainWindowClass->resize(768, 553);
        centralWidget = new QWidget(MattyNotesMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MattyNotesMainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MattyNotesMainWindowClass);

        QMetaObject::connectSlotsByName(MattyNotesMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MattyNotesMainWindowClass)
    {
        MattyNotesMainWindowClass->setWindowTitle(QApplication::translate("MattyNotesMainWindowClass", "MattyNotes", 0));
    } // retranslateUi

};

namespace Ui {
    class MattyNotesMainWindowClass: public Ui_MattyNotesMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

class MattyNotesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MattyNotesMainWindow(QWidget *parent = 0);

    ~MattyNotesMainWindow();



private:
    Ui::MattyNotesMainWindowClass ui;

    // menuBar:
    QMenuBar *menuBar; // IsNotUsed

    // statusBar:
    QStatusBar *statusBar;

    // MainToolBar:
    QToolBar *mainToolBar;
    QWidget* MainToolBarSpacerLeft;
    QLabel* WindowHeaderLabel;
    QWidget* MainToolBarSpacerRight;
    QPushButton* MinimizeWindowButton;
    QPushButton* MaximizeWindowButton;
    QPushButton* CloseWindowButton;

    // MattyToolBar:
    QToolBar *MattyToolBar;
    class MattyClocks* MainClocks;
    QPushButton *SettingsButton;
    QWidget* MattyToolBarMainSpacer;
    QPushButton *RefreshNoteListButton;
    QPushButton *AddNoteButton;

    // centralWidget:
    QGridLayout *MainGridLayout;
    // Splitter:
    QSplitter *MainSplitter;
    QWidget *LeftSideWidget;
    QWidget *RightSideWidget;
    // LeftSideWidget:
    QGridLayout *LeftGridLayout;
    QVBoxLayout *LeftSideVerLayout;
    QLabel *MotivatorLabel;
    QSpacerItem* LeftSideVerticalSpacer;
    QSpacerItem* LeftSideHorizontalSpacer;
    // LeftSideWidget:
    QGridLayout *RightGridLayout;
    QWidget *NoteOptionsWidget;
    QScrollArea *GroupBoxScrollArea;
    QWidget *GroupBoxScrollAreaWidgetContents;
    QGridLayout *GroupBoxHolderLayout;

    QGraphicsOpacityEffect* opacity;

    QAction *closeMainWindow;
    QAction *addNewNote;
    QAction *RefreshMainWindow;

    // dragable window
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    void connectToDb(const QString& PathToDb = QStringLiteral(""));
    void buildBody();
    void buildMainToolBar();
    void buildMattyToolBar();
    void setConnects();
    void setActions();

    private slots:

    void addNote();
    void closeWindow();
    void maximizeWindow();
    void minimizeWindow();
    void refreshMainWindow();
    void openSettings();
    void resizeMattyToolbarButtons(); // IsNotUsed
    bool WindowActivatedEvent(QEvent *e);
};

#endif // MATTYNOTES_H
