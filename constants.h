#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QString>

enum MattyPathToDbType { HomeAbsolute, WorkAbsolute, Relative };

class Constants
{
public:
    static void setPathToDb();
    static void setPathToDb(MattyPathToDbType PathType);
    static void setPathToDb(const QString & Path);
    static QString getPathTODb();

    Constants();
    ~Constants();

private:
    static QString PathToDb;
    static const QString TimeSeparator; // ":"
    static const QString DateSeparator; // "."
    static const QString EmptyQString; // ""
    static const QString Space; // " "
    static const QString ZeroToFill; // "0"
    static const int TimeQStringLength; // 5
    static const int DateQStringLength; // 10
    static const int PositionOfFirstDateSeparator; // 2
    static const int PositionOfSecondDateSeparator; // 5

};


#endif // CONSTANTS_H
