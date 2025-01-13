#include <iostream>
#include <conio.h> // Für _getch()
#include "spiel.h"

void menu(Spiel& spiel);

int main() {
    Spiel spiel;
    menu(spiel);
    return 0;
}

void menu(Spiel& spiel) {
    bool exitMenu = false;

    while (!exitMenu) {
        system("cls"); // Bildschirm leeren
        std::cout << "\n\tWillkommen bei Kniffel!\n";
        std::cout << "\t--------------------------------------------------\n";
        std::cout << "\t| (1) Kniffel spielen                            |\n";
        std::cout << "\t| (2) Spieler hinzufuegen                        |\n";
        std::cout << "\t| (3) Spielstand speichern                       |\n";
        std::cout << "\t| (4) Spielstand laden                           |\n";
        std::cout << "\t| (ESC) Menue verlassen                          |\n";
        std::cout << "\t--------------------------------------------------\n\n";

        char choice = _getch();
        switch (choice) {
            case '1':
                if (!spiel.istBeendet()) {
                    spiel.spielen();
                } else {
                    std::cout << "\nDas Spiel ist bereits beendet!\n";
                }
                break;

            case '2': {
                std::string name;
                std::cout << "\nGeben Sie den Namen des Spielers ein: ";
                std::cin >> name;
                spiel.spielerHinzufuegen(name);
                break;
            }

            case '3':
                spiel.speichern();
                break;

            case '4':
                spiel.laden();
                break;

            case 27: // ESC-Taste
                std::cout << "\nMenü verlassen...\n";
                exitMenu = true;
                break;

            default:
                std::cout << "\nUngültige Eingabe. Bitte versuchen Sie es erneut.\n";
                break;
        }

        if (!exitMenu) {
            std::cout << "\nDrücken Sie eine beliebige Taste, um fortzufahren...\n";
            _getch();
        }
    }
}
