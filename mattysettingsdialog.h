/*
Скорей всего, много лишнего.
Надо будет проверить.
*/


#ifndef MATTYSETTINGSDIALOG_H
#define MATTYSETTINGSDIALOG_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QListWidgetItem>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QSpacerItem>
#include <QSplitter>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

class MattySettingsDialog : public QDialog {
    Q_OBJECT

public:
    MattySettingsDialog(QWidget * parent = 0);
    ~MattySettingsDialog();

private:
   //
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
   /* QWidget *page;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_2;
    QWidget *page_2;
    QPushButton *CancelSettingsButton;
    QPushButton *ApplySettingsButton;*/
//
    QPushButton *ApplySettingsButton;
    QPushButton *CancelSettingsButton;

    QListWidgetItem* General;
    QListWidgetItem* Interface;
    QListWidgetItem* Security;

    QWidget *GeneralPageWidget;
    QWidget *InterfacePageWidget;
    QWidget *SecurityPageWidget;

    QGridLayout *InterfacePageGridLayout;
    QLabel *ChooseThemeLabel;
    QVBoxLayout *ThemeRadioButtonVerticalLayout;
    QRadioButton *SunShineRadioButton;
    QRadioButton *SnowRadioButton;
    QRadioButton *DarkRadioButton;
    QLabel *InsertCssLabel;
    QPlainTextEdit *CssCodePlainTextEdit;
    QSpacerItem *HorizontalSpacer;
    QPushButton *ApplyInterfacePageChangesButton;

    void setConnects();
    void setupUi();
    void buildPages();
    void fillInterfacePage();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    private slots:
    void on_ApplySettingsButton_clicked();
    void on_CancelSettingsButton_clicked();

};

#endif // MATTYSETTINGSDIALOG_H
