#include "wuerfel.h"
#include <cstdlib>
#include <ctime>

Wuerfel::Wuerfel() : wert(1), behalten(false) {
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned>(time(nullptr)));
        initialized = true;
    }
}

void Wuerfel::werfen() {
    if (!behalten) {
        wert = rand() % 6 + 1;
    }
}

int Wuerfel::getWert() const {
    return wert;
}

void Wuerfel::setBehalten(bool b) {
    behalten = b;
}

bool Wuerfel::istBehalten() const {
    return behalten;
}

void Wuerfel::reset() {
    behalten = false;
}