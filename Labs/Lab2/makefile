CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o countLetters.o outputLetters.o

SRCS = main.cpp countLetters.cpp outputLetters.cpp

HEADERS = countLetters.hpp outputLetters.hpp

lab2: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab2
