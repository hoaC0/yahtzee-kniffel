#include <iostream>
#include <cstdlib>
#include <ctime> // random numbers
#include <vector>
#include <conio.h> // _getch() funktion
#include <algorithm>  // Für std::find
#include <windows.h> // sleep/delay

//Anzahl Wuerfel
const int num_Dice = 5;

//funktion ( einzigen ) Wuerfel wuerfeln
int rollDie() {
    return (rand() % 6) + 1;
}


// Wuerfel wuerfeln
void rollDice1() {
    srand(time(0));
    int dice[num_Dice];
    char reroll; // ja / nein
    bool same_num; // gleiche zahl 

    // erster Wurf ... 5 mal wuerfeln
    for (int i = 0; i < num_Dice; i++) {
        dice[i] = rollDie();
    }
    
        std::vector<int> W1;
        std::vector<int> W2;
        std::vector<int> W3;
        std::vector<int> W4;
        std::vector<int> W5;
        std::vector<int> W6;
    
    // wenn gleiche zahlen
    for (int j = 0; j < num_Dice; j++) {

        switch (dice[j])
        {
        case 1:
            W1.insert(W1.begin(),1);
            
            break;
        
        case 2:
            W2.insert(W2.begin(),2);
            break;
        
        case 3:
            W3.insert(W3.begin(),3);
            break;
        
        case 4:
            W4.insert(W4.begin(),4);
            break;
        
        case 5:
            W5.insert(W5.begin(),5);
            break;
        
        case 6:
            W6.insert(W6.begin(),6);
            break;
        
        default:
            break;
        }
        
    }  

    //fuer optionen spaeter
    std::vector<int> options;

    //range based
    for (int i : W1) {
        std::cout << i << " ";
        options.push_back(i);
    }
    std::cout << std::endl;

    for (int i : W2) {
        std::cout << i << " ";
        options.push_back(i);
    }    
    std::cout << std::endl;

    for (int i : W3) {    
        std::cout << i << " ";
        options.push_back(i);
    }
    std::cout << std::endl;

    for (int i : W4) {    
        std::cout << i << " ";
        options.push_back(i);
    }   
    std::cout << std::endl;             

    for (int i : W5) {            
        std::cout << i << " ";
        options.push_back(i);
    }
    std::cout << std::endl;

    for (int i : W6) {            
        std::cout << i << " ";
        options.push_back(i);
    }

    std::cout << std::endl;
    std::cout << "Du hast die Nummern...\n\n";
    Sleep(1000); // 1000ms = 1s
    for (int i = 0; i < 5; i++) {
        std::cout << dice[i] << "\n";
        Sleep(300); //300ms = 0.3s
    }
    Sleep(300); // 0.3s
    std::cout << "\n...gewuerfelt\n\n";
    Sleep(1000); // 1s

    //wenn von einer zahl mehr als einmal
    int W1Anzahl = W1.size();
    int W2Anzahl = W2.size();
    int W3Anzahl = W3.size();
    int W4Anzahl = W4.size();
    int W5Anzahl = W5.size();
    int W6Anzahl = W6.size();

    //bool value
    bool W1Val = false;
    bool W2Val = false;
    bool W3Val = false;
    bool W4Val = false;
    bool W5Val = false;    
    bool W6Val = false;
    
    //wenn von einer zahl mehr als einmal => change value
    if (W1Anzahl > 1) {
        W1Val = true;
    } 
    if (W2Anzahl > 1) {
        W2Val = true;
    }
    if (W3Anzahl > 1) {
        W3Val = true;
    }
    if (W4Anzahl > 1) {
        W4Val = true;
    }
    if (W5Anzahl > 1) {
        W5Val = true;
    }
    if (W6Anzahl > 1) {
        W6Val = true;
    }


    if (W1Val == true || W2Val == true || W3Val == true || W4Val == true || W5Val == true || W6Val == true) {

        std::cout << "Welche Wuerfel moechtest du neu wuerfeln?\n";
        Sleep(1500); // 1.5s
        std::cout << "( 1 ) Wuerfel: " <<dice[0] << "\n( 2 ) Wuerfel: " << dice[1] << "\n( 3 ) Wuerfel: " << dice[2] << "\n( 4 ) Wuerfel: " << dice[3] << "\n( 5 ) Wuerfel: " << dice[4] << "\n\n( C ) Alle Wuerfel neu wuerfeln" <<"\n\n( X ) Auswahl beenden\n\n";
        bool LoopOFF = false;
        
        while (!options.empty() && !LoopOFF) {
            char choice = _getch(); // ohne "std::cin >> choice;", da sonst 2 mal eintippen muss
            

            switch (choice) {
                //Wuerfel 1
                case 49: { 
                    auto it = std::find(options.begin(), options.end(), dice[0]);
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nWuerfel ( 1 ) ausgewaehlt. Du kannst es nicht nochmal waehlen." << std::endl;
                    }
                    break;
                }
                
                //Wuerfel 2
                case 50: {
                    auto it = std::find(options.begin(), options.end(), dice[1]);
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nWuerfel ( 2 ) ausgewaehlt. Du kannst es nicht nochmal waehlen." << std::endl;
                    }
                    break;
                }

                //Wuerfel 3
                case 51: {
                    auto it = std::find(options.begin(), options.end(), dice[2]);
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nWuerfel ( 3 ) ausgewaehlt. Du kannst es nicht nochmal waehlen." << std::endl;
                    }
                    break;
                }

                //Wuerfel 4
                case 52: {
                    auto it = std::find(options.begin(), options.end(), dice[3]);
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nWuerfel ( 4 ) ausgewaehlt. Du kannst es nicht nochmal waehlen." << std::endl;
                    }
                    break;
                }

                //Wuerfel 5
                case 53: {
                    auto it = std::find(options.begin(), options.end(), dice[4]);
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nWuerfel ( 5 ) ausgewaehlt. Du kannst es nicht nochmal waehlen." << std::endl;
                    }
                    break;
                }

                //Wuerfel 6
                case 54: {
                    auto it = std::find(options.begin(), options.end(), dice[5]);
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nWuerfel ( 6 ) ausgewaehlt. Du kannst es nicht nochmal waehlen." << std::endl;
                    }
                    break;
                }

                // x = Auswahl beenden
                case 120: { 
                    LoopOFF = true;
                    break;
                }

                // c = neu wuerfeln ( nur wenn nichts ausgewaehlt wurde )
                case 99: {
                    if (options.size() == 5) {
                        LoopOFF = true;
                        std::cout << "Alle wuerfel neu wuerfeln" << std::endl;
                        break;
                    }
                    else {
                    std::cout << "\nUngueltig!" << std::endl;
                    break;
                    }
                }

                default:
                    std::cout << "\nUngueltige Eingabe, versuche es nochmal." << std::endl;
                    break;
            }
        
            // zeigt alle verbleibenden Optionen an
            if (!options.empty()) {    //negiert => wenn nicht leer
                std::cout << "Verfuegbare Optionen: ";
                for (int i : options) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }
        }

    std::cout << "Alle Optionen wurden ausgewaehlt. Programm beendet." << std::endl;
    for (int i : options) {
        std::cout << i << " ";
        }
    }
}

int rollDice2() {
    srand(time(0));
}
    







//temporary
int main() {
    rollDice1();

    return 0;
}