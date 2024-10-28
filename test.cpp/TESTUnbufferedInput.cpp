#include <iostream>
#include <conio.h> //_getch() funktion

int main() {
    std::cout << "press any key (press 'q' to quit):" << std::endl;
    
    char ch;
    while (true) {
        // Read a single character without buffering
        ch = _getch();
        
        // Print the character and its ASCII value
        std::cout << "You pressed: " << ch << " (ASCII: " << (int)ch << ")" << std::endl;
        
        // exit the loop if 'q' is pressed
        if (ch == 'q') {
            break;
        }
    }
    
    std::cout << "Program ended." << std::endl;
    return 0;
}