#ifndef MATTYSTYLESHEETEDITOR_H
#define MATTYSTYLESHEETEDITOR_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QString>
#include <QFile>
#include <QApplication>

enum DefaultTheme { MattySunShineStyleSheet, MattySnowStyleSheet, MattyDarkStyleSheet
};

class MattyStyleSheetEditor
{
public:
    MattyStyleSheetEditor();

    static bool setTheme(const QString & ThemeName);
    static bool setTheme(DefaultTheme ThemeName);
    static bool reloadCssFromQss();
    static bool composeStylesAndMoveFromDbToQss();
    static bool createQssFile(const QString& UserCssIncm);

    ~MattyStyleSheetEditor();

private:
    static QString CurrentTheme;

};

#endif // MATTYSTYLESHEETEDITOR_H
