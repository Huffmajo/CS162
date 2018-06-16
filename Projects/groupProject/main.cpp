/*********************************************************************
 ** Program name: Predator-Prey Game
 ** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
 ** Date: February 18, 2018
 ** Description: main.cpp, driver for the Predator-Prey Game.
 *********************************************************************/

#include "Menu.hpp" 

#include <ctime>

int main() {
    
    cout << "\nNOTE: Extra credit is implemented!" << endl;

    // Setup seed and srand for use with rand().
    srand((unsigned)time(NULL));

    Menu menu;
    menu.runSim();
    
    cin.ignore();
    return 0;
}
