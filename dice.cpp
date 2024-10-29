#include <iostream>
#include <cstdlib>
#include <ctime>



const int num_Dice = 5;

//funktion ( einzigen ) Wuerfel wuerfeln
int rollDie() {
    return (rand() % 6) + 1;
}


// Wuerfel wuerfeln
int rollDice() {
    srand(time(0));
    int dice[num_Dice];
    char reroll;

    // erster Wurf
    for (int i = 0; i < num_Dice; i++) {
        dice[i] = rollDie();
        std::cout << "Wuerfel " << i + 1 << ": " << dice[i] << "\n";
    }

    // weiterwuerfeln?
    for (int roll = 0; roll < 2; roll++) {
        std::cout << "\nMoechtest du nochmal wuerfeln? (j/n): ";
        std::cin >> reroll;

        if (reroll != 'j' && reroll != 'J') {
            break;
        }
    }
    
}

//temporary
int main() {
    rollDice();

    return 0;
}