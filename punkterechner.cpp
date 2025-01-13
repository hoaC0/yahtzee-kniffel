#include "punkterechner.h"
#include <algorithm> // fuer std::count, std::any_of, std::accumulate
#include <numeric> // fuer std::accumulate

int PunkteRechner::berechnePunkte(int kategorie, const std::array<int, 5>& wuerfel) {
    switch(kategorie) {
        case 0: return summeGleicherZahlen(1, wuerfel); // Einser
        case 1: return summeGleicherZahlen(2, wuerfel); // Zweier
        case 2: return summeGleicherZahlen(3, wuerfel); // Dreier
        case 3: return summeGleicherZahlen(4, wuerfel); // Vierer
        case 4: return summeGleicherZahlen(5, wuerfel); // Fünfer
        case 5: return summeGleicherZahlen(6, wuerfel); // Sechser
        case 6: return istXerPasch(3, wuerfel) ? summeAllerWuerfel(wuerfel) : 0; // Dreierpasch
        case 7: return istXerPasch(4, wuerfel) ? summeAllerWuerfel(wuerfel) : 0; // Viererpasch
        case 8: return istFullHouse(wuerfel) ? 25 : 0; // Full House
        case 9: return istKleineStrasse(wuerfel) ? 30 : 0; // Kleine Straße
        case 10: return istGrosseStrasse(wuerfel) ? 40 : 0; // Große Straße
        case 11: return istXerPasch(5, wuerfel) ? 50 : 0; // Kniffel
        case 12: return summeAllerWuerfel(wuerfel); // Chance
        default: return 0;
    }
}

int PunkteRechner::summeGleicherZahlen(int zahl, const std::array<int, 5>& wuerfel) {
    return std::count(wuerfel.begin(), wuerfel.end(), zahl) * zahl;
}

bool PunkteRechner::istKleineStrasse(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    return (zahlen[0] && zahlen[1] && zahlen[2] && zahlen[3]) || 
           (zahlen[1] && zahlen[2] && zahlen[3] && zahlen[4]) ||
           (zahlen[2] && zahlen[3] && zahlen[4] && zahlen[5]);
}

bool PunkteRechner::istGrosseStrasse(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    return (zahlen[0] && zahlen[1] && zahlen[2] && zahlen[3] && zahlen[4]) ||
           (zahlen[1] && zahlen[2] && zahlen[3] && zahlen[4] && zahlen[5]);
}

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

bool PunkteRechner::istXerPasch(int x, const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen = zaehleWuerfel(wuerfel);
    return std::any_of(zahlen.begin(), zahlen.end(), [x](int anzahl) { return anzahl >= x; });
}

int PunkteRechner::summeAllerWuerfel(const std::array<int, 5>& wuerfel) {
    return std::accumulate(wuerfel.begin(), wuerfel.end(), 0);
}

std::vector<int> PunkteRechner::zaehleWuerfel(const std::array<int, 5>& wuerfel) {
    std::vector<int> zahlen(6, 0);
    for (int w : wuerfel) {
        zahlen[w - 1]++;
    }
    return zahlen;
}
