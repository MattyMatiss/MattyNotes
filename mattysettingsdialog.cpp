#include "mattysettingsdialog.h"

MattySettingsDialog::MattySettingsDialog(QWidget * parent) : QDialog(parent)
{
    setupUi();
    this->setWindowFlags(Qt::FramelessWindowHint);
    // this->setAttribute(Qt::WA_DeleteOnClose);

    buildPages();

    setConnects();
}

void MattySettingsDialog::on_ApplySettingsButton_clicked()
{
    // сюда дорисовать действия
    this->close();
}

void MattySettingsDialog::on_CancelSettingsButton_clicked()
{
    this->close();
}

void MattySettingsDialog::setConnects()
{
    connect
    (listWidget, SIGNAL(currentRowChanged(int)),
        stackedWidget, SLOT(setCurrentIndex(int)));
}

void MattySettingsDialog::setupUi()
{
    if (this->objectName().isEmpty())
        this->setObjectName
                (QStringLiteral("MattySettingsDialog"));
    this->resize(676, 548);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName
            (QStringLiteral("horizontalLayout_2"));
    verticalSpacer = new QSpacerItem
            (0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    horizontalLayout_2->addItem(verticalSpacer);

    splitter = new QSplitter(this);
    splitter->setObjectName(QStringLiteral("splitter"));
    splitter->setOrientation(Qt::Horizontal);
    listWidget = new QListWidget(splitter);
    listWidget->setObjectName(QStringLiteral("listWidget"));
    listWidget->setBaseSize(QSize(150, 0));
    splitter->addWidget(listWidget);
    stackedWidget = new QStackedWidget(splitter);
    stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
    stackedWidget->setMinimumSize(QSize(300, 0));

    splitter->addWidget(stackedWidget);

    horizontalLayout_2->addWidget(splitter);

    gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName
            (QStringLiteral("horizontalLayout"));
    CancelSettingsButton = new QPushButton(this);
    CancelSettingsButton->setObjectName
            (QStringLiteral("CancelSettingsButton"));

    horizontalLayout->addWidget(CancelSettingsButton);

    horizontalSpacer = new QSpacerItem
            (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    ApplySettingsButton = new QPushButton(this);
    ApplySettingsButton->setObjectName
            (QStringLiteral("ApplySettingsButton"));

    horizontalLayout->addWidget(ApplySettingsButton);


    gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

    stackedWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(this);
}

void MattySettingsDialog::buildPages()
{
    for (int i = stackedWidget->count(); i >= 0; i--)
    {
        QWidget* oldwidget = stackedWidget->widget(i);
        delete oldwidget;
    }

    stackedWidget->setMinimumWidth(250);
    splitter->setStretchFactor(0, 2);
    splitter->setStretchFactor(1, 4);

    General = new QListWidgetItem
            (tr("General"), listWidget); //needtodelete?
    Interface = new QListWidgetItem
            (tr("Interface"), listWidget);
    Security = new QListWidgetItem
            (tr("Security"), listWidget);

    GeneralPageWidget = new QWidget(stackedWidget);
    InterfacePageWidget = new QWidget(stackedWidget);
    SecurityPageWidget = new QWidget(stackedWidget);

    GeneralPageWidget->setMinimumWidth(250);
    InterfacePageWidget->setMinimumWidth(250);
    SecurityPageWidget->setMinimumWidth(250);

    stackedWidget->addWidget(GeneralPageWidget);
    stackedWidget->addWidget(InterfacePageWidget);
    stackedWidget->addWidget(SecurityPageWidget);

    fillInterfacePage();
}

void MattySettingsDialog::fillInterfacePage()
{
    InterfacePageGridLayout = new QGridLayout(InterfacePageWidget);
    InterfacePageGridLayout->setObjectName
            (QStringLiteral("InterfacePageGridLayout"));

    ChooseThemeLabel = new QLabel(InterfacePageWidget);
    ChooseThemeLabel->setObjectName(QStringLiteral("ChooseThemeLabel"));
    ChooseThemeLabel->setText("Выберите цветовую схему:");
    InterfacePageGridLayout->addWidget(ChooseThemeLabel, 0, 0, 1, 1);

    ThemeRadioButtonVerticalLayout = new QVBoxLayout();
    ThemeRadioButtonVerticalLayout->setObjectName
            (QStringLiteral("ThemeRadioButtonVerticalLayout"));
    InterfacePageGridLayout->addLayout
            (ThemeRadioButtonVerticalLayout, 1, 0, 1, 1);

    SunShineRadioButton = new QRadioButton(InterfacePageWidget);
    SunShineRadioButton->setObjectName(QStringLiteral("SunShineRadioButton"));
    SunShineRadioButton->setText("Солнечная");

    SnowRadioButton = new QRadioButton(InterfacePageWidget);
    SnowRadioButton->setObjectName(QStringLiteral("SnowRadioButton"));
    SnowRadioButton->setText("Снежная");

    DarkRadioButton = new QRadioButton(InterfacePageWidget);
    DarkRadioButton->setObjectName(QStringLiteral("DarkRadioButton"));
    DarkRadioButton->setText("Тёмная");

    ThemeRadioButtonVerticalLayout->addWidget(SunShineRadioButton);
    ThemeRadioButtonVerticalLayout->addWidget(SnowRadioButton);
    ThemeRadioButtonVerticalLayout->addWidget(DarkRadioButton);

    InsertCssLabel = new QLabel(InterfacePageWidget);
    InsertCssLabel->
        setObjectName(QStringLiteral("InsertCssLabel"));
    InsertCssLabel->
        setText("Или создайте свою таблицу стилей (css):");
    InterfacePageGridLayout->
        addWidget(InsertCssLabel, 2, 0, 1, 2);

    CssCodePlainTextEdit = new QPlainTextEdit(InterfacePageWidget);

    CssCodePlainTextEdit->
        setObjectName(QStringLiteral
        ("CssCodePlainTextEdit"));

    InterfacePageGridLayout->
        addWidget(CssCodePlainTextEdit, 3, 0, 1, 2);

    HorizontalSpacer = new QSpacerItem
            (40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    InterfacePageGridLayout->
        addItem(HorizontalSpacer, 4, 0, 1, 1);

    ApplyInterfacePageChangesButton = new QPushButton(InterfacePageWidget);
    ApplyInterfacePageChangesButton->
        setObjectName(QStringLiteral
        ("ApplyInterfacePageChangesButton"));

    InterfacePageGridLayout->
        addWidget(ApplyInterfacePageChangesButton, 4, 1, 1, 1);
}

void MattySettingsDialog::mousePressEvent(QMouseEvent *event)
{
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MattySettingsDialog::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX() - m_nMouseClick_X_Coordinate,
         event->globalY() - m_nMouseClick_Y_Coordinate);
}

MattySettingsDialog::~MattySettingsDialog()
{

}
