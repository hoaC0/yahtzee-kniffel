#ifndef SPIELER_H
#define SPIELER_H

#include <string>
#include "punktekarte.h"

class Spieler {
private:
    std::string name;     // name des spielers
    Punktekarte karte;    // punktekarte des spielers

public:
    Spieler(const std::string& spielerName);  // konstruktor mit spielername
    std::string getName() const;              // gibt den namen des spielers zurueck
    const Punktekarte& getPunktekarte() const;// gibt die punktekarte des spielers zurueck
    void punkteEintragen(int kategorie, int punkte);  // traegt punkte in die punktekarte ein
    
    // PROBLEM: es fehlt eine methode zum aendern des spielernamens,
    // void setName(const std::string& neuerName);
};

#endif