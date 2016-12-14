#include "MattyStyleSheetEditor.h"

QString MattyStyleSheetEditor::CurrentTheme = "MattySunShineStyleSheet";

MattyStyleSheetEditor::MattyStyleSheetEditor()
{
}

bool MattyStyleSheetEditor::setTheme(const QString & ThemeName)
{
    bool ThemeFileOpened = false;
    QFile styleFile("resources/" + ThemeName + ".qss");
    CurrentTheme = ThemeName;

    if (ThemeFileOpened = styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
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

        QFile styleFile(CurrentTheme + ".qss");

        if (ThemeFileOpened = styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qApp->setStyleSheet(styleFile.readAll());
            styleFile.close();
        }

    return ThemeFileOpened;
}

bool MattyStyleSheetEditor::refreshTheme()
{
    return setTheme(CurrentTheme);
}

MattyStyleSheetEditor::~MattyStyleSheetEditor()
{
}
