CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o Ant.o intValidation.o menu.o

SRCS = main.cpp Ant.cpp intValidation.cpp menu.cpp

HEADERS = Ant.hpp intValidation.hpp menu.hpp

lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o project1
