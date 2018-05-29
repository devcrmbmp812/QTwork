//
// Created by carbone on 4/12/18.
//

#include "Isin.h"

Isin::Isin(char s[]) : QString(s) {

}

bool Isin::valid() {
    return Identifier::isIsin(this);
}