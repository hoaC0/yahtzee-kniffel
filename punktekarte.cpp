#include "punktekarte.h"
#include <iostream>
#include <iomanip>
#include <string>

Punktekarte::Punktekarte() : bonus(0) {
    punkte.fill(0);
    verwendet.fill(false);
}

void Punktekarte::eintragen(int kategorie, int wert) {
    if (!verwendet[kategorie]) {
        punkte[kategorie] = wert;
        verwendet[kategorie] = true;

        // Prüfe Bonus (wenn oberer Bereich >= 63)
        if (getZwischenSummeOben() >= 63) {
            bonus = 35;
        }
    }
}

bool Punktekarte::istVerwendet(int kategorie) const {
    return verwendet[kategorie];
}

int Punktekarte::getPunkte(int kategorie) const {
    return punkte[kategorie];
}

int Punktekarte::getBonus() const {
    return bonus;
}

int Punktekarte::getZwischenSummeOben() const {
    int summe = 0;
    for (int i = 0; i < 6; i++) {
        summe += punkte[i];
    }
    return summe;
}

int Punktekarte::getEndSummeOben() const {
    return getZwischenSummeOben() + bonus;
}

int Punktekarte::getGesamtPunkte() const {
    int summe = getEndSummeOben();
    for (int i = 6; i < 13; i++) {
        summe += punkte[i];
    }
    return summe;
}

bool Punktekarte::istVoll() const {
    for (bool b : verwendet) {
        if (!b) return false;
    }
    return true;
}

void Punktekarte::anzeigen() const {
    std::cout << "\n=== PUNKTEKARTE ===\n";
    std::cout << "Oberer Bereich:\n";
    std::cout << "1. Einser:     " << (verwendet[0] ? std::to_string(punkte[0]) : "-") << "\n";
    std::cout << "2. Zweier:     " << (verwendet[1] ? std::to_string(punkte[1]) : "-") << "\n";
    std::cout << "3. Dreier:     " << (verwendet[2] ? std::to_string(punkte[2]) : "-") << "\n";
    std::cout << "4. Vierer:     " << (verwendet[3] ? std::to_string(punkte[3]) : "-") << "\n";
    std::cout << "5. Fünfer:     " << (verwendet[4] ? std::to_string(punkte[4]) : "-") << "\n";
    std::cout << "6. Sechser:    " << (verwendet[5] ? std::to_string(punkte[5]) : "-") << "\n";
    std::cout << "Zwischensumme: " << getZwischenSummeOben() << "\n";
    std::cout << "Bonus:         " << bonus << "\n";
    std::cout << "Summe oben:    " << getEndSummeOben() << "\n\n";
    
    std::cout << "Unterer Bereich:\n";
    std::cout << "7. Dreierpasch:      " << (verwendet[6] ? std::to_string(punkte[6]) : "-") << "\n";
    std::cout << "8. Viererpasch:      " << (verwendet[7] ? std::to_string(punkte[7]) : "-") << "\n";
    std::cout << "9. Full House:        " << (verwendet[8] ? std::to_string(punkte[8]) : "-") << "\n";
    std::cout << "10. Kleine Straße:    " << (verwendet[9] ? std::to_string(punkte[9]) : "-") << "\n";
    std::cout << "11. Große Straße:     " << (verwendet[10] ? std::to_string(punkte[10]) : "-") << "\n";
    std::cout << "12. Kniffel:          " << (verwendet[11] ? std::to_string(punkte[11]) : "-") << "\n";
    std::cout << "13. Chance:           " << (verwendet[12] ? std::to_string(punkte[12]) : "-") << "\n";
    
    std::cout << "\nGesamtpunkte: " << getGesamtPunkte() << "\n";
}