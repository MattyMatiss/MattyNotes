/*
Все очень запутанно и далеко от идеала.
В планах сделать несколько готовых тем оформления
в отдельных .qss файлах, чьи названия совпадают с названиями тем.
Плюс возможность менять детали через всякие радио и комбо.
Возможно с помощью некого "конструктора", который будет брать
составные части css из базы, склеивать и создавать .qss из этого.
*/

#include "mattystylesheeteditor.h"
#include "dbmanager.h"


QString MattyStyleSheetEditor::CurrentTheme = "MattySunShineStyleSheet";

MattyStyleSheetEditor::MattyStyleSheetEditor()
{
}

bool MattyStyleSheetEditor::setTheme(const QString & ThemeName)
{
    bool ThemeFileOpened = false;
    QString ThemeFileName = ThemeName + ".qss";
    QFile styleFile(ThemeFileName);

    CurrentTheme = ThemeName;

    if ((ThemeFileOpened = styleFile.open(QIODevice::ReadOnly | QIODevice::Text)))
    {
        qApp->setStyleSheet(styleFile.readAll());
        styleFile.close();
    }
    return ThemeFileOpened;
}

bool MattyStyleSheetEditor::setTheme(DefaultTheme ThemeName)
{
    bool ThemeFileOpened = false;

    switch (ThemeName)
    {
    case MattySunShineStyleSheet:
        CurrentTheme = "MattySunShineStyleSheet";
        break;

    case MattySnowStyleSheet:
        CurrentTheme = "MattySnowStyleSheet";
        break;

    case MattyDarkStyleSheet:
        CurrentTheme = "MattyDarkStyleSheet";
        break;
    }

        QFile styleFile(":/All/resources/MattySunShineStyleSheet.qss"); // некрасиво

        if ((ThemeFileOpened = styleFile.open(QIODevice::ReadOnly | QIODevice::Text)))
        {
            qApp->setStyleSheet(styleFile.readAll());
            styleFile.close();
        }

    return ThemeFileOpened;
}

bool MattyStyleSheetEditor::reloadCssFromQss()
{
    return setTheme(CurrentTheme);
}

bool MattyStyleSheetEditor::composeStylesAndMoveFromDbToQss()
{
    if(DbManager::connected())
    {

        return true;
    }

    else
    {
        return false;
    }
}

bool MattyStyleSheetEditor::createQssFile(const QString& UserCssIncm)
{

    return false;
}

MattyStyleSheetEditor::~MattyStyleSheetEditor()
{
}
