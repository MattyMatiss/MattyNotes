#include "QueryConstructor.h"

QueryConstructor::QueryConstructor()
{
    OrderByClause = "";
    TableName = "";
    WhatToSelectFieldNames = QStringList();
    WhereFieldValue = QMap<QString, QString>();
    WhatToSetFieldValue = QMap<QString, QString>();
}


QueryConstructor::~QueryConstructor()
{
}

void QueryConstructor::setOrderByClause(const QString& Field, OrderType DirectionIncm)
{
    QString Direction = "; ";
    if (DirectionIncm == Descending)
        Direction = " DESC; ";
    OrderByClause = " ORDER BY " + Field + Direction;
}


QString QueryConstructor::getOrderByClause()
{
    return OrderByClause;
}

void QueryConstructor::addWhatToSelectFieldName(const QString& FieldName)
{
    WhatToSelectFieldNames.push_back(FieldName);
}

void QueryConstructor::addWhereFieldValue(const QString& Field, const QString & Value)
{
    WhereFieldValue.insert(Field, Value);
}

void QueryConstructor::addWhatToSetFieldValue(const QString& Field, const QString & Value)
{
    WhatToSetFieldValue.insert(Field, Value);
}

void QueryConstructor::setTableName(const QString& Name)
{
    TableName = Name;
}

QString QueryConstructor::getTableName()
{
    return TableName;
}

void QueryConstructor::setWhatToSelectFieldNames(const QStringList & FieldNames)
{
    WhatToSelectFieldNames = FieldNames;
}

QStringList QueryConstructor::getWhatToSelectFieldNames()
{
    return WhatToSelectFieldNames;
}

void QueryConstructor::setWhereFieldValue(const QMap<QString, QString>& FieldValue)
{
    WhereFieldValue = FieldValue;
}

QMap<QString, QString> QueryConstructor::getWhereFieldValue()
{
    return WhereFieldValue;
}

void QueryConstructor::setWhatToSetFieldValue(const QMap<QString, QString>& FieldValue)
{
    WhatToSetFieldValue = FieldValue;
}

QMap<QString, QString> QueryConstructor::getWhatToSetFieldValue()
{
    return WhatToSetFieldValue;
}

QString QueryConstructor::constructInsertQuery()
{
    QString ResultQuery = "";

    if (TableName!="")
    {
        if (!WhatToSetFieldValue.isEmpty())
        {
            ResultQuery.append(" INSERT INTO " + TableName + " (");

            QMapIterator<QString, QString> pair(WhatToSetFieldValue);
            while (pair.hasNext())
            {
                pair.next();
                ResultQuery.append(" " + pair.key() + ",");
            }

            if (ResultQuery.endsWith(","))
                ResultQuery.chop(1);

            ResultQuery.append(") VALUES(");

            pair.toFront();

            while (pair.hasNext())
            {
                pair.next();
                ResultQuery.append(" " + pair.value() + ",");
            }

            if (ResultQuery.endsWith(","))
                ResultQuery.chop(1);

            ResultQuery.append(");");
        }
    }

    return ResultQuery;
}

QString QueryConstructor::constructSelectQuery()
{
    QString ResultQuery = "";

    if (TableName != "")
    {
        ResultQuery.append(" SELECT ");

        if (WhatToSelectFieldNames.isEmpty())
        {
            ResultQuery.append("*");
        }
        else
        {
            for (int i = 0;i < WhatToSelectFieldNames.length()-1;i++)
            {
                ResultQuery.append(" " + WhatToSelectFieldNames[i] + ",");
            }
            ResultQuery.append(WhatToSelectFieldNames.last());
        }
        ResultQuery.append(" FROM " + TableName + constructWhereEqualsClause() + " " + OrderByClause);
    }
    return ResultQuery;
}

QString QueryConstructor::constructDeleteQuery()
{
    QString ResultQuery = "";

    if (TableName != "")
    {
        ResultQuery.append(" DELETE FROM " + TableName + constructWhereEqualsClause());
    }

    return ResultQuery;
}

QString QueryConstructor::constructUpdateQuery()
{
    QString ResultQuery = "";

    if(TableName!="")
        if (!WhatToSetFieldValue.empty())
        {
            ResultQuery.append(" UPDATE " + TableName + " SET ");

            QMapIterator<QString, QString> pair(WhatToSetFieldValue);
            while (pair.hasNext())
            {
                pair.next();
                ResultQuery.append(" " + pair.key() + "=" + pair.value() + ",");
            }
            if (ResultQuery.endsWith(","))
                ResultQuery.chop(1);

            ResultQuery.append(constructWhereEqualsClause());
        }

    return ResultQuery;
}

QString QueryConstructor::constructWhereEqualsClause()
{
    QString WhereClause = "";

    if (!WhereFieldValue.empty())
    {
        WhereClause.append(" WHERE ");

        QMapIterator<QString, QString> pair(WhereFieldValue);
        while (pair.hasNext())
        {
            pair.next();
            WhereClause.append(" " + pair.key() + "=" + pair.value() + ",");
        }
        if (WhereClause.endsWith(","))
            WhereClause.chop(1);
    }
    return WhereClause;
}
