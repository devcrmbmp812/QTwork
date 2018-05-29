//
// Created by carbone on 4/12/18.
//

#ifndef ETFG_V1_ISIN_H
#define ETFG_V1_ISIN_H

#include <QtCore/QString>
#include <Identifier.h>

class Isin : public QString, Identifier {
public:
    Isin(char s[]);
    bool valid();
};

#endif //ETFG_V1_ISIN_H
