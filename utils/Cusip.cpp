//
// Created by carbone on 4/12/18.
//

#include "Cusip.h"

#include<Identifier.h>


Cusip::Cusip(char s[]) : QString(s) {

}

bool Cusip::valid() {
    return Identifier::isCusip(this);
}