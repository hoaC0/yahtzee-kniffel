#include "spieler.h"

Spieler::Spieler(const std::string& spielerName) : name(spielerName) {}

std::string Spieler::getName() const {
    return name;
}

const Punktekarte& Spieler::getPunktekarte() const {
    return karte;
}

void Spieler::punkteEintragen(int kategorie, int punkte) {
    karte.eintragen(kategorie, punkte);
}