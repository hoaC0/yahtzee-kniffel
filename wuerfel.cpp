#include "wuerfel.h"
#include <cstdlib>  // fuer rand()
#include <ctime>    // fuer time()

// konstruktor - initialisiert wuerfel mit standardwerten
Wuerfel::Wuerfel() : wert(1), behalten(false) {
    static bool initialized = false;
    if (!initialized) {
        // initialisiere zufallsgenerator nur beim ersten wuerfel
        srand(static_cast<unsigned>(time(nullptr)));
        initialized = true;
    }
}

// wirft den wuerfel neu (wenn nicht behalten)
void Wuerfel::werfen() {
    if (!behalten) {
        wert = rand() % 6 + 1;  // zufaelliger wert zwischen 1 und 6
    }
}

// gibt aktuellen wurfwert zurueck
int Wuerfel::getWert() const {
    return wert;
}

// setzt behalten-status
void Wuerfel::setBehalten(bool b) {
    behalten = b;
}

// gibt behalten-status zurueck
bool Wuerfel::istBehalten() const {
    return behalten;
}

// setzt behalten-status zurueck
void Wuerfel::reset() {
    behalten = false;
}