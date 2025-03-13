#ifndef PUNKTERECHNER_H
#define PUNKTERECHNER_H

#include <array>
#include <vector>

class PunkteRechner {
public:
    // berechnet punkte fuer eine bestimmte kategorie und wuerfelkombination
    static int berechnePunkte(int kategorie, const std::array<int, 5>& wuerfel);

private:
    // hilfsmethoden zur berechnung der punkte
    static int summeGleicherZahlen(int zahl, const std::array<int, 5>& wuerfel);  // summiert alle wuerfel mit bestimmtem wert
    static bool istKleineStrasse(const std::array<int, 5>& wuerfel);  // prueft auf kleine strasse (4 aufeinanderfolgende zahlen)
    static bool istGrosseStrasse(const std::array<int, 5>& wuerfel);  // prueft auf grosse strasse (5 aufeinanderfolgende zahlen)
    static bool istFullHouse(const std::array<int, 5>& wuerfel);      // prueft auf full house (3 gleiche + 2 gleiche)
    static bool istXerPasch(int x, const std::array<int, 5>& wuerfel); // prueft auf x gleiche wuerfel (x = 3, 4 oder 5)
    static int summeAllerWuerfel(const std::array<int, 5>& wuerfel);  // summiert alle wuerfel
    static std::vector<int> zaehleWuerfel(const std::array<int, 5>& wuerfel); // erstellt histogramm der wuerfelwerte
};

#endif