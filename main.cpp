#include <iostream>
#include <conio.h> // fuer _getch() - erlaubt tastenabfragen ohne enter
#include "spiel.h"

void menu(Spiel& spiel);

int main() {
    Spiel spiel;                // erstelle ein neues kniffel-spiel
    menu(spiel);               // zeige hauptmenue und starte spiel
    return 0;
}

void menu(Spiel& spiel) {
    bool exitMenu = false;     // kontrollflag fuer menuenavigation

    while (!exitMenu) {
        system("cls");         // bildschirm leeren (windows-spezifisch)
        std::cout << "\n\tWillkommen bei Kniffel!\n";
        std::cout << "\t--------------------------------------------------\n";
        std::cout << "\t| (1) Kniffel spielen                            |\n";
        std::cout << "\t| (2) Spieler hinzufuegen                        |\n";
        std::cout << "\t| (3) Spielstand speichern                       |\n";
        std::cout << "\t| (4) Spielstand laden                           |\n";
        std::cout << "\t| (ESC) Menue verlassen                          |\n";
        std::cout << "\t--------------------------------------------------\n\n";

        char choice = _getch();  // taste ohne enter lesen
        switch (choice) {
            case '1':
                if (!spiel.istBeendet()) {
                    spiel.spielen();        // spiellogik starten
                } else {
                    std::cout << "\nDas Spiel ist bereits beendet!\n";
                }
                break;

            case '2': {
                std::string name;
                std::cout << "\nGeben Sie den Namen des Spielers ein: ";
                std::cin >> name;
                spiel.spielerHinzufuegen(name);  // neuen spieler erstellen
                break;
            }

            case '3':
                spiel.speichern();          // spielstand speichern
                break;

            case '4':
                spiel.laden();          // spielstand laden
                break;

            case 27: // ESC-Taste
                std::cout << "\nMenue verlassen...\n";
                exitMenu = true;            // menue beenden
                break;

            default:
                std::cout << "\nUngueltige Eingabe. Bitte versuchen Sie es erneut.\n";
                break;
        }

        if (!exitMenu) {
            std::cout << "\nDruecken Sie eine beliebige Taste, um fortzufahren...\n";
            _getch();                      // warten auf tastendruck
        }
    }
}