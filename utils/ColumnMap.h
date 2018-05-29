//
// Created by carbone on 4/2/18.
//

#ifndef ETFG_V1_COLUMNMAP_H
#define ETFG_V1_COLUMNMAP_H

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>

enum class ColumnType {
    none,
    string,
    numeric,
    date,
    isin,
    cusip,
    sedol,
    figi
};

class ColumnMap {
private:
    QString key;
    ColumnType type;
    QList<int> columns;
    QList<QString> names;

public:
    ColumnMap();
    ColumnMap(QString key, ColumnType type, QList<QString> names);
    ColumnMap(QString key, ColumnType type, int number);
    ColumnMap(ColumnType type, QList<QString> names);
    ColumnMap(ColumnType type, int number);
    static ColumnType getType(QString *s);
    static QString stringType(QString *s);
    void debug();
    bool mapColumn(int columnNum, QString name);
    const QString &getKey() const;
    QString getData(const QStringList &columns);
};


#endif //ETFG_V1_COLUMNMAP_H
