#ifndef SPIELER_H
#define SPIELER_H

#include <string>
#include "punktekarte.h"

class Spieler {
private:
    std::string name;
    Punktekarte karte;

public:
    Spieler(const std::string& spielerName);
    std::string getName() const;
    const Punktekarte& getPunktekarte() const;  // Add this line
    void punkteEintragen(int kategorie, int punkte);
};

#endif