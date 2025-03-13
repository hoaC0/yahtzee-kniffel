#ifndef PUNKTEKARTE_H
#define PUNKTEKARTE_H

#include <array>

class Punktekarte {
private:
    std::array<int, 13> punkte;      // speichert punkte fuer jede kategorie (0-12)
    std::array<bool, 13> verwendet;  // speichert, ob eine kategorie bereits verwendet wurde
    int bonus;                       // bonus punkte (35 wenn oberer bereich >= 63 punkte)

public:
    Punktekarte();                   // konstruktor - initialisiert punktekarte mit 0 und bonus mit 0
    void eintragen(int kategorie, int punkte);  // traegt punkte in eine kategorie ein und markiert diese als verwendet
    bool istVerwendet(int kategorie) const;     // prueft, ob eine kategorie bereits verwendet wurde
    int getPunkte(int kategorie) const;         // gibt punkte fuer eine bestimmte kategorie zurueck
    int getBonus() const;                       // gibt aktuellen bonus zurueck
    int getZwischenSummeOben() const;           // berechnet zwischensumme des oberen bereichs (einser bis sechser)
    int getEndSummeOben() const;                // berechnet endsumme des oberen bereichs (zwischensumme + bonus)
    int getGesamtPunkte() const;                // berechnet gesamtpunkte (oberer + unterer bereich)
    bool istVoll() const;                       // prueft, ob alle kategorien bereits verwendet wurden
    void anzeigen() const;                      // zeigt die punktekarte auf der konsole an
};

#endif