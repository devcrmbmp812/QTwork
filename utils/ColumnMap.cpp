//
// Created by carbone on 4/2/18.
//

#include <QtCore/QFile>
#include <TGlobal>
#include <QtCore/QDateTime>
#include <iostream>
#include "ColumnMap.h"
#include "ModelImport.h"
#include "Identifier.h"

ColumnMap::ColumnMap() {
}

ColumnMap::ColumnMap(QString key, ColumnType type, QList<QString> names) {
    this->key = key;
    this->type = type;
    this->names = names;
}

ColumnMap::ColumnMap(ColumnType type, QList<QString> names) {
    this->type = type;
    this->names = names;
}

ColumnMap::ColumnMap(QString key, ColumnType type, int number) {
    this->key = key;
    this->type = type;
    this->columns[0] = number;
}

ColumnMap::ColumnMap(ColumnType type, int number) {
    this->type = type;
    this->columns[0] = number;
}

ColumnType ColumnMap::getType(QString *a) {  // TODO:: move to separate class
//    tDebug("ColumnMap::getType %s", *a->toUtf8().constData());
    tDebug("ColumnMap::getType");
    QString qs = *a;
    tDebug("qs: |%s|", qs.toUtf8().constData());

    if (QDate::fromString(*a, "MM/dd/yyyy").isValid()) return ColumnType::date;
    else if (QDate::fromString(*a, "yyyy-MM-dd").isValid()) return ColumnType::date;
    else if (Identifier::isCusip(a)) return ColumnType::cusip;
    else if (Identifier::isIsin(a)) return ColumnType::isin;
    else if (Identifier::isSedol(a)) return ColumnType::sedol;
    else if (Identifier::isFigi(a)) return ColumnType::figi;
    else if (a->contains(QRegExp("^[-+]?[0-9]*\\.?[0-9]+$"))) return ColumnType::numeric;
    else return ColumnType::string;
}

QString ColumnMap::stringType(QString *a) {  // TODO:: move to separate class
    if (QDate::fromString(*a, "MM/dd/yyyy").isValid()) return "ColumnType::date";
    else if (QDate::fromString(*a, "yyyy-MM-dd").isValid()) return "ColumnType::date";
    else if (Identifier::isCusip(a)) return "ColumnType::cusip";
    else if (Identifier::isIsin(a)) return "ColumnType::isin";
    else if (Identifier::isSedol(a)) return "ColumnType::sedol";
    else if (Identifier::isFigi(a)) return "ColumnType::figi";
    else if (a->contains(QRegExp("[-+]?[0-9]*\\.?[0-9]+"))) return "ColumnType::numeric";
    else return "ColumnType::string";
}

void ColumnMap::debug() {
    tDebug("ColumnMap::debug");
    switch (this->type) {
        case ColumnType::string:
            tDebug("ColumnType::string");
            break;
        default:
            tDebug("Other");
            break;
    }
    tDebug("Key: %s", this->key.toUtf8().constData());
    foreach(QString s, this->names) tDebug("S: %s", s.toUtf8().constData());

    tDebug("Number of Columns: %d", this->columns.size());
            foreach(int s, this->columns) {
            tDebug("I: %d", s);
        }
}

bool ColumnMap::mapColumn(int columnNum, QString name) {
//    tDebug("ColumnMap::mapColumn");
    int i = this->names.indexOf(name);
    if (i != -1) {
//        tDebug("indexOf: %d columnNum: %d name: %s", i, columnNum, name.toUtf8().constData());
        this->columns.append(columnNum);
    }
}

QString ColumnMap::getData(const QStringList &columns) {
    tDebug("ColumnMap::getData");

    foreach(QString s, this->names) tDebug("Name: %s", s.toUtf8().constData());
    foreach(int i, this->columns) {
        tDebug("Column #: %d ", i);
        if (this->type == ColumnMap::getType((QString *) &columns.at(i))) {
            return columns.at(i);
        }
    }

    return "*";
}

const QString &ColumnMap::getKey() const {
    return key;
}

