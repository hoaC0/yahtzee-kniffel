#ifndef SPIEL_H
#define SPIEL_H

#include <vector>
#include <array>
#include "spieler.h"
#include "wuerfel.h"
#include "punkterechner.h"

class Spiel {
private:
    std::vector<Spieler> spieler;
    std::array<Wuerfel, 5> wuerfel;
    int aktuellerSpieler;
    bool spielBeendet;

    void wuerfelnAlle();
    void wuerfelAuswahl();
    void punkteEintragen();
    void naechsterSpieler();
    void zeigeWuerfel() const;
    std::array<int, 5> getWuerfelWerte() const;
    void zeigeMoeglichePunkte() const;
    void zeigeSpielstand() const;
    void speichereSpiel() const;
    void ladeSpiel();

public:
    Spiel();
    void spielerHinzufuegen(const std::string& name);
    void spielen();
    bool istBeendet() const;
    void speichern() const;
    void laden();
};

#endif