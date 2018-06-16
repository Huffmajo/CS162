/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Main file. Runs all the support files together into
 ** the working program.
 *********************************************************************/

#include <iostream>
#include <time.h>
#include "Vampire.hpp"
#include "Game.hpp"
#include "utils.hpp"
using std::cout;

int main() {
    
    //seed random
    srand(time(NULL));
    
    
    
    // working
    menu();
    
    return 0;
}
