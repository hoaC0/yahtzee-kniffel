#include "punktekarte.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>  // fuer sleep funktionalitaet

// konstruktor - initialisiert punktekarte
Punktekarte::Punktekarte() : bonus(0) {
    punkte.fill(0);         // alle punktwerte mit 0 initialisieren
    verwendet.fill(false);  // alle kategorien als nicht verwendet markieren
}

// traegt punkte in eine kategorie ein
void Punktekarte::eintragen(int kategorie, int wert) {
    if (!verwendet[kategorie]) {  // nur eintragen, wenn kategorie noch nicht verwendet wurde
        punkte[kategorie] = wert;
        verwendet[kategorie] = true;

        // pruefe bonus (wenn oberer bereich >= 63 punkte erreicht)
        if (getZwischenSummeOben() >= 63) {
            bonus = 35;  // bonus von 35 punkten gewaehren
        }
    }
}

// prueft, ob eine kategorie bereits verwendet wurde
bool Punktekarte::istVerwendet(int kategorie) const {
    return verwendet[kategorie];
}

// gibt punkte fuer eine bestimmte kategorie zurueck
int Punktekarte::getPunkte(int kategorie) const {
    return punkte[kategorie];
}

// gibt aktuellen bonus zurueck
int Punktekarte::getBonus() const {
    return bonus;
}

// berechnet zwischensumme des oberen bereichs (einser bis sechser)
int Punktekarte::getZwischenSummeOben() const {
    int summe = 0;
    for (int i = 0; i < 6; i++) {  // nur die ersten 6 kategorien (einser bis sechser)
        summe += punkte[i];
    }
    return summe;
}

// berechnet endsumme des oberen bereichs (zwischensumme + bonus)
int Punktekarte::getEndSummeOben() const {
    return getZwischenSummeOben() + bonus;
}

// berechnet gesamtpunkte (oberer + unterer bereich)
int Punktekarte::getGesamtPunkte() const {
    int summe = getEndSummeOben();  // oberer bereich mit bonus
    for (int i = 6; i < 13; i++) {  // unterer bereich (kategorien 6-12)
        summe += punkte[i];
    }
    return summe;
}

// prueft, ob alle kategorien bereits verwendet wurden
bool Punktekarte::istVoll() const {
    for (bool b : verwendet) {
        if (!b) return false;  // wenn eine kategorie noch nicht verwendet wurde
    }
    return true;  // alle kategorien wurden verwendet
}

// zeigt die punktekarte auf der konsole an
void Punktekarte::anzeigen() const {
    Sleep(1000);  // warte 1 sekunde fuer bessere lesbarkeit
    std::cout << "\n=== PUNKTEKARTE ===\n";
    Sleep(1000);
    std::cout << "Oberer Bereich:\n";
    std::cout << "1. Einser:     " << (verwendet[0] ? std::to_string(punkte[0]) : "-") << "\n";
    std::cout << "2. Zweier:     " << (verwendet[1] ? std::to_string(punkte[1]) : "-") << "\n";
    std::cout << "3. Dreier:     " << (verwendet[2] ? std::to_string(punkte[2]) : "-") << "\n";
    std::cout << "4. Vierer:     " << (verwendet[3] ? std::to_string(punkte[3]) : "-") << "\n";
    std::cout << "5. Fuenfer:     " << (verwendet[4] ? std::to_string(punkte[4]) : "-") << "\n";
    std::cout << "6. Sechser:    " << (verwendet[5] ? std::to_string(punkte[5]) : "-") << "\n";
    std::cout << "Zwischensumme: " << getZwischenSummeOben() << "\n";
    std::cout << "Bonus:         " << bonus << "\n";
    std::cout << "Summe oben:    " << getEndSummeOben() << "\n\n";
    Sleep(1000);
    std::cout << "Unterer Bereich:\n";
    Sleep(1000);
    std::cout << "7. Dreierpasch:      " << (verwendet[6] ? std::to_string(punkte[6]) : "-") << "\n";
    std::cout << "8. Viererpasch:      " << (verwendet[7] ? std::to_string(punkte[7]) : "-") << "\n";
    std::cout << "9. Full House:        " << (verwendet[8] ? std::to_string(punkte[8]) : "-") << "\n";
    std::cout << "10. Kleine Strasse:    " << (verwendet[9] ? std::to_string(punkte[9]) : "-") << "\n";
    std::cout << "11. Grosse Strasse:     " << (verwendet[10] ? std::to_string(punkte[10]) : "-") << "\n";
    std::cout << "12. Kniffel:          " << (verwendet[11] ? std::to_string(punkte[11]) : "-") << "\n";
    std::cout << "13. Chance:           " << (verwendet[12] ? std::to_string(punkte[12]) : "-") << "\n";
    Sleep(1000);
    std::cout << "\nGesamtpunkte: " << getGesamtPunkte() << "\n";
}