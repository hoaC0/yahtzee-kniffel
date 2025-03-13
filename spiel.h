#ifndef SPIEL_H
#define SPIEL_H

#include <vector>
#include <array>
#include "spieler.h"
#include "wuerfel.h"
#include "punkterechner.h"

class Spiel {
private:
    std::vector<Spieler> spieler;       // liste aller spieler
    std::array<Wuerfel, 5> wuerfel;     // die 5 wuerfel des spiels
    int aktuellerSpieler;               // index des aktuellen spielers
    bool spielBeendet;                  // flag ob das spiel beendet ist

    void wuerfelnAlle();                // wirft alle nicht gehaltenen wuerfel neu
    void wuerfelAuswahl();              // fragt nach wuerfeln, die behalten werden sollen
    void punkteEintragen();             // traegt punkte in die spielerkarte ein
    void naechsterSpieler();            // wechselt zum naechsten spieler
    void zeigeWuerfel() const;          // zeigt aktuelle wuerfelwerte an
    std::array<int, 5> getWuerfelWerte() const;  // gibt array mit allen wuerfelwerten zurueck
    void zeigeMoeglichePunkte() const;  // zeigt moegliche punkte fuer aktuelle wuerfelkombination
    void zeigeSpielstand() const;       // zeigt aktuellen spielstand aller spieler
    
    // HINWEIS: namen unterscheiden sich in header und implementation
    void speichereSpiel() const;        // deklariert, aber heisst in implementation "speichern"
    void ladeSpiel();                   // deklariert, aber heisst in implementation "laden"

public:
    Spiel();                            // konstruktor - initialisiert neues spiel
    void spielerHinzufuegen(const std::string& name);  // fuegt neuen spieler hinzu
    void spielen();                     // startet oder setzt das spiel fort
    bool istBeendet() const;            // prueft, ob das spiel beendet ist
    
    // HINWEIS: diese methoden sollten mit denen im privaten bereich uebereinstimmen
    void speichern() const;             // speichert den spielstand in datei
    void laden();                       // laedt den spielstand aus datei
};

#endif