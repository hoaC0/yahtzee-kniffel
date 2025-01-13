#ifndef PUNKTERECHNER_H
#define PUNKTERECHNER_H

#include <array>
#include <vector>

class PunkteRechner {
public:
    static int berechnePunkte(int kategorie, const std::array<int, 5>& wuerfel);

private:
    static int summeGleicherZahlen(int zahl, const std::array<int, 5>& wuerfel);
    static bool istKleineStrasse(const std::array<int, 5>& wuerfel);
    static bool istGrosseStrasse(const std::array<int, 5>& wuerfel);
    static bool istFullHouse(const std::array<int, 5>& wuerfel);
    static bool istXerPasch(int x, const std::array<int, 5>& wuerfel);
    static int summeAllerWuerfel(const std::array<int, 5>& wuerfel);
    static std::vector<int> zaehleWuerfel(const std::array<int, 5>& wuerfel);
};

#endif