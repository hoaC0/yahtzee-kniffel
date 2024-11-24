#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h> // _getch() funktion
#include <algorithm>  // Für std::find

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
    std::cout << "Du hast die Nummern...\n\n" << dice[0] << "\n" << dice[1] << "\n" << dice[2] << "\n" << dice[3] << "\n" << dice[4] << "\n" << "\n\n...gewuerfelt\n";
    std::cout << "Moechtest du nochmal wuerfeln?\n\n";

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
        
        while (!options.empty()) {
            std::cout << "Welche Wuerfel moechtest du behalten?\n";
            char choice;
            std::cin >> choice;

            switch (choice) {
                case 'J': // Ja (Option 'J')
                case 'j': {
                    // Wenn Ja gewählt wurde, entferne die Option aus der Liste
                    auto it = std::find(options.begin(), options.end(), 'J');
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nJa ausgewählt. Du kannst es nicht nochmal wählen." << std::endl;
                    }
                    break;
                }
                case 'N': // Nein (Option 'N')
                case 'n': {
                    // wenn Nein gewählt wurde, entferne die Option aus der Liste
                    auto it = std::find(options.begin(), options.end(), 'N');
                    if (it != options.end()) {
                        options.erase(it);
                        std::cout << "\nNein ausgewählt. Du kannst es nicht nochmal wählen." << std::endl;
                    }
                    break;
                }
                default:
                    std::cout << "\nUngueltige Eingabe, versuche es nochmal." << std::endl;
                    break;
            }

            // zeigt alle verbleibenden Optionen an
            if (!options.empty()) {    //negiert => wenn nicht leer
                std::cout << "Verfügbare Optionen: ";
                for (int i : options) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }
        }

    std::cout << "Alle Optionen wurden ausgewählt. Programm beendet." << std::endl;
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