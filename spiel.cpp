#include "spiel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>

// konstruktor - initialisiert neues spiel
Spiel::Spiel() : aktuellerSpieler(0), spielBeendet(false) {}

// fuegt neuen spieler mit gegebenem namen hinzu
void Spiel::spielerHinzufuegen(const std::string& name) {
    spieler.push_back(Spieler(name));
}

// hauptspiellogik - fuehrt das spiel durch
void Spiel::spielen() {
    if (spieler.empty()) {
        std::cout << "Keine Spieler vorhanden!\n";
        return;
    }

    while (!spielBeendet) {
        system("cls");  // bildschirm leeren (windows-spezifisch)
        std::cout << "\nSpieler " << spieler[aktuellerSpieler].getName() << " ist am Zug\n";
        spieler[aktuellerSpieler].getPunktekarte().anzeigen();

        for (int wurf = 0; wurf < 3; wurf++) {  // maximal 3 wuerfe pro zug
            wuerfelnAlle();
            zeigeWuerfel();

            if (wurf < 2) {  // nach dem ersten und zweiten wurf darf neu gewuerfelt werden
                std::cout << "\nNochmal wuerfeln? (j/n): ";
                char antwort;
                std::cin >> antwort;
                if (antwort == 'j') {
                    wuerfelAuswahl();  // auswaehlen, welche wuerfel behalten werden
                } else {
                    break;  // keine weiteren wuerfe gewuenscht
                }
            }
        }

        zeigeMoeglichePunkte();  // zeige moegliche kategorien fuer punkteeintrag
        punkteEintragen();       // spieler waehlt kategorie und punkte werden eingetragen

        // pruefe, ob alle spielerkarten voll sind (spielende)
        bool alleVoll = true;
        for (const Spieler& spielerObj : spieler) {
            if (!spielerObj.getPunktekarte().istVoll()) {
                alleVoll = false;
                break;
            }
        }

        if (alleVoll) {
            spielBeendet = true;
            zeigeSpielstand();  // zeige endstand an
        } else {
            naechsterSpieler();  // wechsle zum naechsten spieler
        }
    }
}

// wirft alle nicht gehaltenen wuerfel neu
void Spiel::wuerfelnAlle() {
    for (Wuerfel& w : wuerfel) {
        w.werfen();  // nur nicht gehaltene wuerfel werden neu geworfen
    }
}

// fragt nach wuerfeln, die behalten werden sollen
void Spiel::wuerfelAuswahl() {
    std::cout << "\nWelche Wuerfel moechten Sie behalten? (1-5, 0 fuer fertig): ";
    int auswahl;
    
    // PROBLEM: hier werden erstmal alle wuerfel als nicht behalten markiert,
    // dabei gehen bereits ausgewaehlte wuerfel verloren - keine toggle-funktion
    for (Wuerfel& w : wuerfel) {
        w.setBehalten(false);
    }
    
    do {
        std::cin >> auswahl;
        if (auswahl >= 1 && auswahl <= 5) {
            wuerfel[auswahl - 1].setBehalten(true);  // markiere ausgewaehlten wuerfel als behalten
        }
    } while (auswahl != 0);  // 0 beendet die auswahl
}

// zeigt aktuelle wuerfelwerte an
void Spiel::zeigeWuerfel() const {
    std::cout << "\nIhre Wuerfel: ";
    for (int i = 0; i < 5; i++) {
        std::cout << wuerfel[i].getWert() << " ";
    }
    std::cout << std::endl;
}

// gibt array mit allen wuerfelwerten zurueck
std::array<int, 5> Spiel::getWuerfelWerte() const {
    std::array<int, 5> werte;
    for (int i = 0; i < 5; i++) {
        werte[i] = wuerfel[i].getWert();
    }
    return werte;
}

// zeigt moegliche punkte fuer aktuelle wuerfelkombination
void Spiel::zeigeMoeglichePunkte() const {
    std::cout << "\nMoegliche Punkte:\n";
    auto werte = getWuerfelWerte();

    for (int i = 0; i < 13; i++) {
        // zeige nur nicht verwendete kategorien an
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
                case 10: std::cout << "Grosse Strasse: "; break;
                case 11: std::cout << "Kniffel: "; break;
                case 12: std::cout << "Chance: "; break;
            }
            std::cout << PunkteRechner::berechnePunkte(i, werte) << " Punkte\n";
        }
    }
}

// traegt punkte in die spielerkarte ein
void Spiel::punkteEintragen() {
    int kategorie;
    do {
        std::cout << "\nIn welche Kategorie moechten Sie die Punkte eintragen? (1-13): ";
        std::cin >> kategorie;
        kategorie--; // array beginnt bei 0
    } while (kategorie < 0 || kategorie > 12 ||
             spieler[aktuellerSpieler].getPunktekarte().istVerwendet(kategorie));

    int punkte = PunkteRechner::berechnePunkte(kategorie, getWuerfelWerte());
    spieler[aktuellerSpieler].punkteEintragen(kategorie, punkte);
}

// wechselt zum naechsten spieler
void Spiel::naechsterSpieler() {
    for (Wuerfel& w : wuerfel) {
        w.reset();  // wuerfel zuruecksetzen (nicht mehr gehalten)
    }
    aktuellerSpieler = (aktuellerSpieler + 1) % spieler.size();  // naechster spieler (zyklisch)
}

// zeigt aktuellen spielstand aller spieler
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

// speichert den spielstand in datei
// PROBLEM: in header als "speichereSpiel" deklariert, hier als "speichern" implementiert
void Spiel::speichern() const {
    std::ofstream file("kniffel_save.txt");
    if (file.is_open()) {
        // schreibe anzahl der spieler
        file << spieler.size() << "\n";
        
        // schreibe daten jedes spielers
        for (const Spieler& spielerObj : spieler) {
            const Punktekarte& punktekarte = spielerObj.getPunktekarte();
            file << spielerObj.getName() << "\n";
            
            // schreibe punktekarte (punkte und verwendet-status)
            for (int i = 0; i < 13; i++) {
                file << punktekarte.getPunkte(i) << " " << punktekarte.istVerwendet(i) << "\n";
            }
        }
        
        // schreibe index des aktuellen spielers
        file << aktuellerSpieler << "\n";
        file.close();
        std::cout << "Spiel wurde gespeichert!\n";
    }
}

// laedt den spielstand aus datei
// PROBLEM: in header als "ladeSpiel" deklariert, hier als "laden" implementiert
void Spiel::laden() {
    std::ifstream file("kniffel_save.txt");
    if (file.is_open()) {
        spieler.clear();  // entferne alle spieler
        int spielerAnzahl;
        file >> spielerAnzahl;
        file.ignore();  // ignoriere restlichen zeilenumbruch

        // lade jeden spieler
        for (int i = 0; i < spielerAnzahl; i++) {
            std::string name;
            std::getline(file, name);
            spielerHinzufuegen(name);

            // lade punktekarte
            for (int j = 0; j < 13; j++) {
                int punkte;
                bool verwendet;
                file >> punkte >> verwendet;
                if (verwendet) {
                    spieler[i].punkteEintragen(j, punkte);
                }
            }
        }

        // lade index des aktuellen spielers
        file >> aktuellerSpieler;
        file.close();
        std::cout << "Spiel wurde geladen!\n";
    } else {
        std::cout << "Kein gespeichertes Spiel gefunden!\n";
    }
}

// prueft, ob das spiel beendet ist
bool Spiel::istBeendet() const {
    return spielBeendet;
}