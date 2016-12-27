#ifndef MATTYNOTES_H
#define MATTYNOTES_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QtWidgets>

class MattyNotesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MattyNotesMainWindow(QWidget *parent = 0);

    ~MattyNotesMainWindow();

private:

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
    QWidget *centralWidget;
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
