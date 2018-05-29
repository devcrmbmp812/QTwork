//
// Created by carbone on 4/13/18.
//

#ifndef ETFG_V1_SEDOL_H
#define ETFG_V1_SEDOL_H


#include <QtCore/QString>
#include <Identifier.h>

class Sedol : public QString, Identifier {
public:
    Sedol(char s[]);
    bool valid();
};

#endif //ETFG_V1_SEDOL_H
