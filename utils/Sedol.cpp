//
// Created by carbone on 4/13/18.
//

#include "Sedol.h"

Sedol::Sedol(char s[]) : QString(s) {

}

bool Sedol::valid() {
    return Identifier::isSedol(this);
}