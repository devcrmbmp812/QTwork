//
// Created by carbone on 4/12/18.
//

#ifndef ETFG_V1_CUSIP_H
#define ETFG_V1_CUSIP_H

#include <QtCore/QString>
#include <Identifier.h>

class Cusip : public QString, Identifier {
public:
    Cusip(char s[]);
    bool valid();
};

#endif //ETFG_V1_CUSIP_H
