#include "spiel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>

Spiel::Spiel() : aktuellerSpieler(0), spielBeendet(false) {}

void Spiel::spielerHinzufuegen(const std::string& name) {
    spieler.push_back(Spieler(name));
}

void Spiel::spielen() {
    if (spieler.empty()) {
        std::cout << "Keine Spieler vorhanden!\n";
        return;
    }

    while (!spielBeendet) {
        system("cls");
        std::cout << "\nSpieler " << spieler[aktuellerSpieler].getName() << " ist am Zug\n";
        spieler[aktuellerSpieler].getPunktekarte().anzeigen();

        for (int wurf = 0; wurf < 3; wurf++) {
            wuerfelnAlle();
            zeigeWuerfel();

            if (wurf < 2) {
                std::cout << "\nNochmal wuerfeln? (j/n): ";
                char antwort;
                std::cin >> antwort;
                if (antwort == 'j') {
                    wuerfelAuswahl();
                } else {
                    break;
                }
            }
        }

        zeigeMoeglichePunkte();
        punkteEintragen();

        bool alleVoll = true;
        for (const Spieler& spielerObj : spieler) {
            if (!spielerObj.getPunktekarte().istVoll()) {
                alleVoll = false;
                break;
            }
        }

        if (alleVoll) {
            spielBeendet = true;
            zeigeSpielstand();
        } else {
            naechsterSpieler();
        }
    }
}

void Spiel::wuerfelnAlle() {
    for (Wuerfel& w : wuerfel) {
        w.werfen();
    }
}

void Spiel::wuerfelAuswahl() {
    std::cout << "\nWelche Wuerfel möchten Sie behalten? (1-5, 0 fuer fertig): ";
    int auswahl;
    for (Wuerfel& w : wuerfel) {
        w.setBehalten(false);
    }
    do {
        std::cin >> auswahl;
        if (auswahl >= 1 && auswahl <= 5) {
            wuerfel[auswahl - 1].setBehalten(true);
        }
    } while (auswahl != 0);
}

void Spiel::zeigeWuerfel() const {
    std::cout << "\nIhre Wuerfel: ";
    for (int i = 0; i < 5; i++) {
        std::cout << wuerfel[i].getWert() << " ";
    }
    std::cout << std::endl;
}

std::array<int, 5> Spiel::getWuerfelWerte() const {
    std::array<int, 5> werte;
    for (int i = 0; i < 5; i++) {
        werte[i] = wuerfel[i].getWert();
    }
    return werte;
}

void Spiel::zeigeMoeglichePunkte() const {
    std::cout << "\nMoegliche Punkte:\n";
    auto werte = getWuerfelWerte();

    for (int i = 0; i < 13; i++) {
        if (!spieler[aktuellerSpieler].getPunktekarte().istVerwendet(i)) {
            std::cout << (i + 1) << ". ";
            switch (i) {
                case 0: std::cout << "Einser: "; break;
                case 1: std::cout << "Zweier: "; break;
                case 2: std::cout << "Dreier: "; break;
                case 3: std::cout << "Vierer: "; break;
                case 4: std::cout << "Fuenfer: "; break;
                case 5: std::cout << "Sechser: "; break;
                case 6: std::cout << "Dreierpasch: "; break;
                case 7: std::cout << "Viererpasch: "; break;
                case 8: std::cout << "Full House: "; break;
                case 9: std::cout << "Kleine Strasse: "; break;
                case 10: std::cout << "Große Strasse: "; break;
                case 11: std::cout << "Kniffel: "; break;
                case 12: std::cout << "Chance: "; break;
            }
            std::cout << PunkteRechner::berechnePunkte(i, werte) << " Punkte\n";
        }
    }
}

void Spiel::punkteEintragen() {
    int kategorie;
    do {
        std::cout << "\nIn welche Kategorie moechten Sie die Punkte eintragen? (1-13): ";
        std::cin >> kategorie;
        kategorie--; // Array beginnt bei 0
    } while (kategorie < 0 || kategorie > 12 ||
             spieler[aktuellerSpieler].getPunktekarte().istVerwendet(kategorie));

    int punkte = PunkteRechner::berechnePunkte(kategorie, getWuerfelWerte());
    spieler[aktuellerSpieler].punkteEintragen(kategorie, punkte);
}

void Spiel::naechsterSpieler() {
    for (Wuerfel& w : wuerfel) {
        w.reset();
    }
    aktuellerSpieler = (aktuellerSpieler + 1) % spieler.size();
}

void Spiel::zeigeSpielstand() const {
    system("cls");
    std::cout << "\n=== SPIELENDE ===\n\n";
    for (const Spieler& spielerObj : spieler) {
        const Punktekarte& punktekarte = spielerObj.getPunktekarte();
        std::cout << spielerObj.getName() << ": " << punktekarte.getGesamtPunkte() << " Punkte\n";
        punktekarte.anzeigen();
        std::cout << "\n";
    }
}

void Spiel::speichern() const {
    std::ofstream file("kniffel_save.txt");
    if (file.is_open()) {
        file << spieler.size() << "\n";
        for (const Spieler& spielerObj : spieler) {
            const Punktekarte& punktekarte = spielerObj.getPunktekarte();
            file << spielerObj.getName() << "\n";
            for (int i = 0; i < 13; i++) {
                file << punktekarte.getPunkte(i) << " " << punktekarte.istVerwendet(i) << "\n";
            }
        }
        file << aktuellerSpieler << "\n";
        file.close();
        std::cout << "Spiel wurde gespeichert!\n";
    }
}

void Spiel::laden() {
    std::ifstream file("kniffel_save.txt");
    if (file.is_open()) {
        spieler.clear();
        int spielerAnzahl;
        file >> spielerAnzahl;
        file.ignore();

        for (int i = 0; i < spielerAnzahl; i++) {
            std::string name;
            std::getline(file, name);
            spielerHinzufuegen(name);

            for (int j = 0; j < 13; j++) {
                int punkte;
                bool verwendet;
                file >> punkte >> verwendet;
                if (verwendet) {
                    spieler[i].punkteEintragen(j, punkte);
                }
            }
        }

        file >> aktuellerSpieler;
        file.close();
        std::cout << "Spiel wurde geladen!\n";
    } else {
        std::cout << "Kein gespeichertes Spiel gefunden!\n";
    }
}

bool Spiel::istBeendet() const {
    return spielBeendet;
}
