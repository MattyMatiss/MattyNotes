#ifndef QUERYCONSTRUCTOR_H
#define QUERYCONSTRUCTOR_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QMap>
#include <QString>

enum OrderType { Straight, Descending };

class QueryConstructor
{
public:
    QueryConstructor();
    ~QueryConstructor();

    void setTableName(const QString& tableName);
    QString getTableName();
    void setWhatToSelectFieldNames(const QStringList& FieldNames);
    QStringList getWhatToSelectFieldNames();
    void setWhereFieldValue(const QMap<QString, QString>& FieldValue);
    QMap<QString, QString> getWhereFieldValue();
    void setWhatToSetFieldValue(const QMap<QString, QString>& FieldValue);
    QMap<QString, QString> getWhatToSetFieldValue();
    void setOrderByClause(const QString& Field = "", OrderType Direction = Straight);
    QString getOrderByClause();
    void addWhatToSelectFieldName(const QString& FieldName);
    void addWhereFieldValue(const QString& Field, const QString& Value);
    void addWhatToSetFieldValue(const QString& Field, const QString& Value);
    QString constructInsertQuery();
    QString constructSelectQuery();
    QString constructDeleteQuery();
    QString constructUpdateQuery();

private:

    QString TableName;
    QStringList WhatToSelectFieldNames;
    QMap<QString, QString> WhereFieldValue;
    QMap<QString, QString> WhatToSetFieldValue;
    QString OrderByClause;
    QString constructWhereEqualsClause();
};

#endif // QUERYCONSTRUCTOR_H
