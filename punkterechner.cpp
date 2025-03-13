#include "punkterechner.h"
#include <algorithm> // fuer std::count, std::any_of
#include <numeric>   // fuer std::accumulate

// berechnet punkte fuer eine bestimmte kategorie und wuerfelkombination
int PunkteRechner::berechnePunkte(int kategorie, const std::array<int, 5>& wuerfel) {
    switch(kategorie) {
        case 0: return summeGleicherZahlen(1, wuerfel); // Einser - summiere alle einsen
        case 1: return summeGleicherZahlen(2, wuerfel); // Zweier - summiere alle zweien
        case 2: return summeGleicherZahlen(3, wuerfel); // Dreier - summiere alle dreien
        case 3: return summeGleicherZahlen(4, wuerfel); // Vierer - summiere alle vieren
        case 4: return summeGleicherZahlen(5, wuerfel); // Fuenfer - summiere alle fuenfen
        case 5: return summeGleicherZahlen(6, wuerfel); // Sechser - summiere alle sechsen
        case 6: return istXerPasch(3, wuerfel) ? summeAllerWuerfel(wuerfel) : 0; // Dreierpasch - summe wenn mind. 3 gleiche
        case 7: return istXerPasch(4, wuerfel) ? summeAllerWuerfel(wuerfel) : 0; // Viererpasch - summe wenn mind. 4 gleiche
        case 8: return istFullHouse(wuerfel) ? 25 : 0; // Full House - 25 punkte wenn 3+2 gleiche
        case 9: return istKleineStrasse(wuerfel) ? 30 : 0; // Kleine Strasse - 30 punkte wenn 4 aufeinanderfolgende
        case 10: return istGrosseStrasse(wuerfel) ? 40 : 0; // Grosse Strasse - 40 punkte wenn 5 aufeinanderfolgende
        case 11: return istXerPasch(5, wuerfel) ? 50 : 0; // Kniffel - 50 punkte wenn alle 5 gleich
        case 12: return summeAllerWuerfel(wuerfel); // Chance - summe aller wuerfel
        default: return 0; // ungueltige kategorie
    }
}

// summiert alle wuerfel mit bestimmtem wert
int PunkteRechner::summeGleicherZahlen(int zahl, const std::array<int, 5>& wuerfel) {
    return std::count(wuerfel.begin(), wuerfel.end(), zahl) * zahl;
}

// prueft auf kleine strasse (4 aufeinanderfolgende zahlen)
bool PunkteRechner::istKleineStrasse(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    // pruefe die drei moeglichen kleinen strassen: 1-2-3-4, 2-3-4-5, 3-4-5-6
    return (zahlen[0] && zahlen[1] && zahlen[2] && zahlen[3]) || 
           (zahlen[1] && zahlen[2] && zahlen[3] && zahlen[4]) ||
           (zahlen[2] && zahlen[3] && zahlen[4] && zahlen[5]);
}

// prueft auf grosse strasse (5 aufeinanderfolgende zahlen)
bool PunkteRechner::istGrosseStrasse(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    // pruefe die beiden moeglichen grossen strassen: 1-2-3-4-5 oder 2-3-4-5-6
    return (zahlen[0] && zahlen[1] && zahlen[2] && zahlen[3] && zahlen[4]) ||
           (zahlen[1] && zahlen[2] && zahlen[3] && zahlen[4] && zahlen[5]);
}

// prueft auf full house (3 gleiche + 2 gleiche)
bool PunkteRechner::istFullHouse(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    bool dreiGleiche = false;
    bool zweiGleiche = false;

    for (int anzahl : zahlen) {
        if (anzahl == 3) dreiGleiche = true;
        if (anzahl == 2) zweiGleiche = true;
    }

    return dreiGleiche && zweiGleiche;
}

// prueft auf x gleiche wuerfel (x = 3, 4 oder 5)
bool PunkteRechner::istXerPasch(int x, const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    return std::any_of(zahlen.begin(), zahlen.end(), 
                    [x](int anzahl) { return anzahl >= x; });
}

// summiert alle wuerfel
int PunkteRechner::summeAllerWuerfel(const std::array<int, 5>& wuerfel) {
    return std::accumulate(wuerfel.begin(), wuerfel.end(), 0);
}

// erstellt histogramm der wuerfelwerte (anzahl der 1er, 2er, usw.)
std::vector<int> PunkteRechner::zaehleWuerfel(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen(6, 0);  // array mit 6 nullen, fuer werte 1-6
    for (int w : wuerfel) {
        zahlen[w - 1]++;  // erhoehe zaehler fuer entsprechenden wert (w-1 wegen 0-index)
    }
    return zahlen;
}
