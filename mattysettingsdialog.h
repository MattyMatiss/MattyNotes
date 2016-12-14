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

//#include "ui_mattysettingsdialog.h"

QT_BEGIN_NAMESPACE

class Ui_MattySettingsDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *CancelSettingsButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *ApplySettingsButton;

    void setupUi(QWidget *MattySettingsDialog)
    {
        if (MattySettingsDialog->objectName().isEmpty())
            MattySettingsDialog->setObjectName(QStringLiteral("MattySettingsDialog"));
        MattySettingsDialog->resize(676, 548);
        gridLayout = new QGridLayout(MattySettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);

        splitter = new QSplitter(MattySettingsDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setBaseSize(QSize(150, 0));
        splitter->addWidget(listWidget);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(300, 0));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(page);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_2->addWidget(plainTextEdit, 3, 0, 1, 2);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 4, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(page);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(page);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        splitter->addWidget(stackedWidget);

        horizontalLayout_2->addWidget(splitter);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CancelSettingsButton = new QPushButton(MattySettingsDialog);
        CancelSettingsButton->setObjectName(QStringLiteral("CancelSettingsButton"));

        horizontalLayout->addWidget(CancelSettingsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ApplySettingsButton = new QPushButton(MattySettingsDialog);
        ApplySettingsButton->setObjectName(QStringLiteral("ApplySettingsButton"));

        horizontalLayout->addWidget(ApplySettingsButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(MattySettingsDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MattySettingsDialog);
    } // setupUi

    void retranslateUi(QWidget *MattySettingsDialog)
    {
        MattySettingsDialog->setWindowTitle(QApplication::translate("MattySettingsDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        label->setText(QApplication::translate("MattySettingsDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\206\320\262\320\265\321\202\320\276\320\262\321\203\321\216 \321\201\321\205\320\265\320\274\321\203:", 0));
        pushButton->setText(QApplication::translate("MattySettingsDialog", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        radioButton->setText(QApplication::translate("MattySettingsDialog", "\320\241\320\276\320\273\320\275\320\265\321\207\320\275\320\260\321\217", 0));
        radioButton_2->setText(QApplication::translate("MattySettingsDialog", "\320\227\320\270\320\274\320\275\321\217\321\217", 0));
        radioButton_3->setText(QApplication::translate("MattySettingsDialog", "\320\242\321\221\320\274\320\275\320\260\321\217", 0));
        label_2->setText(QApplication::translate("MattySettingsDialog", "\320\230\320\273\320\270 \320\277\321\200\320\270\320\274\320\265\320\275\320\270\321\202\320\265 \321\201\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271 \321\201\321\202\320\270\320\273\321\214, \320\262\321\201\321\202\320\260\320\262\320\270\320\262 css-\320\272\320\276\320\264:", 0));
        CancelSettingsButton->setText(QString());
        ApplySettingsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MattySettingsDialog: public Ui_MattySettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE



class MattySettingsDialog : public QDialog {
    Q_OBJECT

public:
    MattySettingsDialog(QWidget * parent = 0);
    ~MattySettingsDialog();

private:
    Ui::MattySettingsDialog MattySettingsDialogUi;

    QPushButton ApplySettingsButton;
    QPushButton CancelSettingsButton;

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
