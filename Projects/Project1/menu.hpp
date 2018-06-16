/*********************************************************************
 ** Program name: Langtons Ant Simulation
 ** Author: Joel Huffman
 ** Date: 1/20/2018
 ** Description: This program runs simulations of Langston's Ant from
 ** user supplied inputs. The simulations are displayed with ASCII
 ** characters onto the screen. The user can continually run simulations
 ** until they are satisfied with exiting the program.
 *********************************************************************/


#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include "intValidation.hpp"
#include "Ant.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::cout;

/*********************************************************************
 ** menu:
 ** Asks the user if they'd like to run a simulation. If they do, data
 ** for their simulation is collected. After the simulation is complete,
 ** they are given the option to run additional simulations until they
 ** wish to quit.
 *********************************************************************/
int menu();

#endif /* menu_hpp */
