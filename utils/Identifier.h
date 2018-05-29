//
// Created by carbone on 4/12/18.
//

#ifndef ETFG_V1_IDENTIFIER_H
#define ETFG_V1_IDENTIFIER_H

#include <QtCore/QString>
#include "ColumnMap.h"

class Identifier {
public:
    static bool isCusip(QString *s);
    static bool isIsin(QString *a);
    static bool isSedol(QString *a);
    static bool isFigi(QString *a);
    static ColumnType getType(QString *a);
};


#endif //ETFG_V1_IDENTIFIER_H
