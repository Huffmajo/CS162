CXX = g++
CXXFLAGES = -std=c++0x -g

OBJS = main.o utils.o Die.o LoadedDie.o  Game.o

SRCS = main.cpp utils.cpp Die.cpp LoadedDie.cpp Game.cpp

HEADERS =  utils.hpp Die.hpp LoadedDie.hpp Game.hpp

lab3: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab3
