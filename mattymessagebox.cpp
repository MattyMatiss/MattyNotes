#include "mattymessagebox.h"

#include <QAbstractButton>

MattyMessageBox::MattyMessageBox(Type Type, QWidget *parent)
    : QMessageBox(parent)
{
    this->setObjectName(QStringLiteral("MattyMessageBox"));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet(NULL);
    this->setFixedWidth(150);

    switch (Type)
    {
    case MessageBoxInformation:

        this->setStandardButtons(QMessageBox::Ok);
        this->button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));

        MattyIcon.load(":All/resources/InformationCircled.png");

        break;

    case MessageBoxWarning:

        this->setStandardButtons(QMessageBox::Ok);
        this->button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));

        MattyIcon.load(":All/resources/WarningTriangled.png");

        break;

    case MessageBoxQuestion:

        this->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        this->button(QMessageBox::Yes)->setObjectName(QStringLiteral("yesButton"));
        this->button(QMessageBox::No)->setObjectName(QStringLiteral("noButton"));

        MattyIcon.load(":All/resources/QuestionSquared.png");

        break;
    }

    this->setIconPixmap(MattyIcon);
}

void MattyMessageBox::mousePressEvent(QMouseEvent *event)
{
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MattyMessageBox::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

MattyMessageBox::~MattyMessageBox()
{

}
