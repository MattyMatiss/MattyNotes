#include "mattystylesheeteditor.h"

QString MattyStyleSheetEditor::CurrentTheme = "MattySunShineStyleSheet";

MattyStyleSheetEditor::MattyStyleSheetEditor()
{
}

bool MattyStyleSheetEditor::setTheme(const QString & ThemeName)
{
    bool ThemeFileOpened = false;
    QString ThemeFileName = ThemeName + ".qss";
    QFile styleFile("MattySunShineStyleSheet.qss");

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

        QFile styleFile(":/All/resources/MattySunShineStyleSheet.qss");

        if ((ThemeFileOpened = styleFile.open(QIODevice::ReadOnly | QIODevice::Text)))
        {
            qApp->setStyleSheet(styleFile.readAll());
            styleFile.close();
        }


        QFile outFile("log.txt");
            outFile.open(QIODevice::WriteOnly | QIODevice::Append);
            QString ThemeFileName = ":/All/resources/MattySunShineStyleSheet.qss";
            QByteArray ba = ThemeFileName.toLatin1();
             const char *c_str2 = ba.data();
            outFile.write(c_str2);
            outFile.close();


    return ThemeFileOpened;
}

bool MattyStyleSheetEditor::refreshTheme()
{
    return setTheme(CurrentTheme);
}

MattyStyleSheetEditor::~MattyStyleSheetEditor()
{
}
