//
// Created by carbone on 4/13/18.
//

#include "Figi.h"

Figi::Figi(char s[]) : QString(s) {

}

bool Figi::valid() {
    return Identifier::isFigi(this);
}