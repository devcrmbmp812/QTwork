//
// Created by carbone on 4/12/18.
//

#include "Identifier.h"
#include <ColumnMap.h>

bool Identifier::isCusip(QString *s) {
    int sum = 0;
    int v = 0;

    if (s->size() != 9) return false;

    for (int i = 0; i < s->size(); ++i) {
        QChar c = s->at(i);

        if (c.isDigit())
            v = c.unicode() - '0';
        else if (c.isLetter())
            v = c.toUpper().unicode() - 'A' + 10;
        else if (c == '*')
            v = 36;
        else if (c == '@')
            v = 37;
        else if (c == '#')
            v = 38;
        else return false;

        if (i % 2 != 0) v *= 2;
        sum += (v / 10) + v % 10;
    }

    if (((10 - (sum % 10)) % 10))
        return false;

    return true;
}

bool Identifier::isIsin(QString *a) {
    int i, j, k, v, s[24];

    if (a->size() != 12) return false;

    j = 0;
    for (i = 0; i < a->size(); i++) {
        k = a->at(i).unicode();
        if (k >= '0' && k <= '9') {
            if (i < 2) return false;
            s[j++] = k - '0';
        } else if (k >= 'A' && k <= 'Z') {
            if (i == 11) return false;
            k -= 'A' - 10;
            s[j++] = k / 10;
            s[j++] = k % 10;
        } else {
            return false;
        }
    }

    v = 0;
    for (i = j - 2; i >= 0; i -= 2) {
        k = 2 * s[i];
        v += k > 9 ? k - 9 : k;
    }

    for (i = j - 1; i >= 0; i -= 2) {
        v += s[i];
    }

    return v % 10 == 0;
}


bool Identifier::isSedol(QString *a) {
    int sum = 0;
    int sedolWeights[] = {1, 3, 1, 7, 3, 9};

    if (a->size() != 7) return false;

    for (int i = 0; i < 6; ++i) {
        QChar c = a->at(i);

        if (c.isDigit()) {
            sum += (c.unicode() - '0') * sedolWeights[i];
        } else if (c.isLetter()) {
            sum += (c.toUpper().unicode() - 'A') * sedolWeights[i];
        } else
            return false;
    }

    QChar checksumChar = (10 - (sum % 10)) % 10 + '0';
    return checksumChar == a->at(6);
}

bool Identifier::isFigi(QString *a) {
    int sum = 0;

    if (a->size() != 12) return false;

    for (int i = 0; i < 11; ++i) {
        QChar c = a->at(i);
        int v;

        if (c.isDigit()) {
            v = c.unicode() - '0';
        } else if (c.isLetter()) {
            v = c.toUpper().unicode() - 'A' + 10;
        } else
            return false;

        v *= (i % 2) ? 2 : 1;
        sum += (v % 10) + (v / 10);
    }

    int checkDigit = (sum / 10 + 1) * 10 - sum;
    return checkDigit == a->at(11).unicode() - '0';
}