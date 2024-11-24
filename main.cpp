#include <iostream>
#include <conio.h> // _getch() funktion

void menu();

int main() {
    menu();
    return 0;
}
void menu() {

    std::cout << "\n                           \tWillkommen bei Kniffel!\n";
    std::cout << "\t--------------------------------------------------------------------------\n\t";
    std::cout << "|\t                                                                 |\n";
    std::cout << "\t|\t ( 1 ) Kniffel spielen\t                                         |\n";
    std::cout << "\t|\t                                                                 |\n";
    std::cout << "\t|\t ( 2 ) Anzahl der Spieler definieren\t                         |\n";
    std::cout << "\t|\t                                                                 |\n";
    std::cout << "\t|\t ( 3 ) Spielstand laden\t                                         |\n";
    std::cout << "\t|\t                                                                 |\n";
    std::cout << "\t|\t ( ESC ) Menue verlassen\t                                 |\n";
    std::cout << "\t|\t                                                                 |\n";
    std::cout << "\t--------------------------------------------------------------------------\n\t";
    
    
    char choice = _getch();
    switch (choice) {
        case '1': 
            std::cout << "Kniffel spielen" << std::endl;
            //Funktion
            break;
        case '2':
            std::cout << "Anzahl der Spieler definieren" << std::endl;
            //Funktion
            break;
        case '3':
            std::cout << "Spielstand laden" << std::endl;
            //Funktion
            break;
        case 27: // ASCII code ESC key... 27 = ESC
            std::cout << "Menue verlassen" << std::endl;
            //Funktion
            break;
        default:
            std::cout << "Ungueltige Eingabe" << std::endl;
            
            break;
    }
    
}