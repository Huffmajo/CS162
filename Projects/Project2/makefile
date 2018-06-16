CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o utils.o Animal.o Penguin.o Tiger.o Turtle.o Zoo.o

SRCS = main.cpp utils.cpp Animal.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp

HEADERS = utils.hpp Animal.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp

Project2: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o Project2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o Project2
