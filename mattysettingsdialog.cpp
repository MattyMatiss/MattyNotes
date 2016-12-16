#include "MattySettingsDialog.h"

MattySettingsDialog::MattySettingsDialog(QWidget * parent) : QDialog(parent)
{
    MattySettingsDialogUi.setupUi(this);
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
    (MattySettingsDialogUi.listWidget, SIGNAL(currentRowChanged(int)),
        MattySettingsDialogUi.stackedWidget, SLOT(setCurrentIndex(int)));
}

void MattySettingsDialog::buildPages()
{
    for (int i = MattySettingsDialogUi.stackedWidget->count(); i >= 0; i--)
    {
        QWidget* oldwidget = MattySettingsDialogUi.stackedWidget->widget(i);
        MattySettingsDialogUi.stackedWidget->removeWidget(oldwidget);
        oldwidget->deleteLater();
    }

    MattySettingsDialogUi.stackedWidget->setMinimumWidth(250);
    MattySettingsDialogUi.splitter->setStretchFactor(0, 1);
    MattySettingsDialogUi.splitter->setStretchFactor(1, 5);

    General = new QListWidgetItem(tr("General"), MattySettingsDialogUi.listWidget); // needtodelete ? parent?
    Interface = new QListWidgetItem(tr("Interface"), MattySettingsDialogUi.listWidget);
    Security = new QListWidgetItem(tr("Security"), MattySettingsDialogUi.listWidget);

    GeneralPageWidget = new QWidget(MattySettingsDialogUi.stackedWidget);
    InterfacePageWidget = new QWidget(MattySettingsDialogUi.stackedWidget);
    SecurityPageWidget = new QWidget(MattySettingsDialogUi.stackedWidget);

    GeneralPageWidget->setMinimumWidth(250);
    InterfacePageWidget->setMinimumWidth(250);
    SecurityPageWidget->setMinimumWidth(250);

    MattySettingsDialogUi.stackedWidget->addWidget(GeneralPageWidget);
    MattySettingsDialogUi.stackedWidget->addWidget(InterfacePageWidget);
    MattySettingsDialogUi.stackedWidget->addWidget(SecurityPageWidget);

    fillInterfacePage();
}

void MattySettingsDialog::fillInterfacePage()
{
    InterfacePageGridLayout = new QGridLayout(InterfacePageWidget);
    InterfacePageGridLayout->setObjectName(QStringLiteral("InterfacePageGridLayout"));

    ChooseThemeLabel = new QLabel(InterfacePageWidget);
    ChooseThemeLabel->setObjectName(QStringLiteral("ChooseThemeLabel"));
    ChooseThemeLabel->setText("Выберите цветовую схему:");
    InterfacePageGridLayout->addWidget(ChooseThemeLabel, 0, 0, 1, 1);

    ThemeRadioButtonVerticalLayout = new QVBoxLayout(InterfacePageWidget);
    ThemeRadioButtonVerticalLayout->setObjectName(QStringLiteral("ThemeRadioButtonVerticalLayout"));
    InterfacePageGridLayout->addLayout(ThemeRadioButtonVerticalLayout, 1, 0, 1, 1);

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

    HorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
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
    move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

MattySettingsDialog::~MattySettingsDialog()
{

}
