#include "Constants.h"

#include <QFileInfo>

QString Constants::PathToDb = "";
// work path
 // QString Constants::PathToDb = "C:\\Users\\Ogrigorieva\\Visual Studio 2015\\Projects\\Personal\\MattyNotes\\MattyNotes.sqlite";
 //home path
//QString Constants::PathToDb = "C:\\Users\\Matty\\Documents\\Visual Studio 2015\\Projects\\Personal\\MattyNotes\\MattyNotes\\MattyNotes.sqlite";

const QString Constants::TimeSeparator = ":";
const QString Constants::DateSeparator = ".";
const QString Constants::EmptyQString = "";
const QString Constants::Space = " ";
const QString Constants::ZeroToFill = "0";
const int Constants::TimeQStringLength = 5;
const int Constants::DateQStringLength = 10;
const int Constants::PositionOfFirstDateSeparator = 2;
const int Constants::PositionOfSecondDateSeparator = 5;

void Constants::setPathToDb(MattyPathToDbType PathType)
{
    switch (PathType)
    {
    case HomeAbsolute:
        PathToDb = "C:\\Users\\Matty\\Documents\\Visual Studio 2015\\Projects\\Personal\\MattyNotes\\MattyNotes\\MattyNotes.sqlite";
        break;
    case WorkAbsolute:
        PathToDb = "C:\\Users\\Ogrigorieva\\Visual Studio 2015\\Projects\\Personal\\MattyNotes\\MattyNotes.sqlite";
        break;
    case Relative:
        PathToDb = QFileInfo(".").absolutePath() + "/" + "MattyNotes.sqlite";
        break;
    default:
        PathToDb = "MattyNotes.sqlite";
        break;
    }
}

void Constants::setPathToDb(const QString & Path)
{
    PathToDb = Path;
}

QString Constants::getPathTODb()
{
    return PathToDb;
}

Constants::Constants()
{
}


Constants::~Constants()
{
}
