//
// Created by carbone on 4/13/18.
//

#ifndef ETFG_V1_FIGI_H
#define ETFG_V1_FIGI_H

#include <QtCore/QString>
#include <Identifier.h>

class Figi : public QString, Identifier {
public:
    Figi(char s[]);
    bool valid();
};


#endif //ETFG_V1_FIGI_H
