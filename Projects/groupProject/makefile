# Program Name: Letter counter
# Name: Group 13
# Date: 1/13/17
# Description: A makefile for the doodlebug game 

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
ZIPFLAGS = -D ${ASSIGNMENT}_Group_13.zip
ASSIGNMENT = Pred-Prey_Files_Version${VERSION}
VERSION = 10

doodle: Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp Menu.cpp main.cpp
	${CXX} ${CXXFLAGS} Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp Menu.cpp main.cpp -o doodlebug

zip: Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp main.cpp Menu.cpp
	zip ${ZIPFLAGS} Ant.cpp Ant.hpp Board.cpp Board.hpp Critter.cpp Critter.hpp Doodlebug.cpp Doodlebug.hpp Menu.cpp Menu.hpp main.cpp makefile  

clean: 
	rm -rf *.zip doodlebug.dYSM doodlebug
